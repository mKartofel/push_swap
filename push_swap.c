/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfiszbin <vfiszbin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:48:37 by vfiszbin          #+#    #+#             */
/*   Updated: 2022/05/27 15:49:21 by vfiszbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// # This function return the sorted stack
// def sortStack ( stack ):
//     tmpStack = createStack()
//     while(isEmpty(stack) == False):
         
//         # pop out the first element
//         tmp = top(stack)
//         pop(stack)
 
//         # while temporary stack is not
//         # empty and top of stack is
//         # greater than temp
//         while(isEmpty(tmpStack) == False and
//              int(top(tmpStack)) > int(tmp)):
             
//             # pop from temporary stack and
//             # push it to the input stack
//             push(stack,top(tmpStack))
//             pop(tmpStack)
 
//         # push temp in temporary of stack
//         push(tmpStack,tmp)
     
//     return tmpStack

void sort_stack(t_list ** stack_a, t_list ** stack_b){
	t_list * tmp;
	int i = 0;
	while(ft_lstsize(*stack_a) > 0){
		tmp = *stack_a; 
		ra(stack_a);
		// ft_printf("tmp = %d\n", ((int*)(tmp)->content));
		while(ft_lstsize(*stack_b) > 0 && ((*stack_b)->content) > ((tmp)->content))
		{
			// ft_printf("top_b = %d\n", (int*)((*stack_b)->content));
			pa(stack_a, stack_b);
			// ft_printf("\n---after pa :\n");
			// print_stack(*stack_a);
			// print_stack(*stack_b);
			// ft_printf("---\n");
		}
		rra(stack_a);
		pb(stack_a, stack_b);
		// ft_printf("\n---after it %d :\n", i);
		// print_stack(*stack_a);
		// print_stack(*stack_b);
		// ft_printf("---\n", i);
		i++;
	}
}

void push_all_b_to_a(t_list ** stack_a, t_list ** stack_b){
	while(ft_lstsize(*stack_b) > 0){
		pa(stack_a, stack_b);
	}
}

/*Free the two stacks before writing Error in stderror and exiting program*/
void exit_program(t_list *stack_a, t_list *stack_b)
{
	write(2, "Error\n", 6);
	free_list(stack_a);
	free_list(stack_b);
	exit(1);
}

/*Check if arg is a number*/
void check_arg_is_digit(char *arg, t_list *stack_a, t_list *stack_b)
{
	int i;

	if (arg[0] != '-' && !ft_isdigit(arg[0]))
		exit_program(stack_a, stack_b);
	i = 1;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			exit_program(stack_a, stack_b);
		i++;
	}
}

/*Check whether the argument is a duplicate of an existing element of the stack*/
void check_arg_is_duplicate(int num, t_list *stack_a, t_list *stack_b)
{
	t_list *cur;

	cur = stack_a;
	while(cur)
	{
		if (cur->content == num)
			exit_program(stack_a, stack_b);
		cur = cur->next;
	}
}

/*Check if the argument is a valid C integer that does not overflow/underflow*/
void check_arg_is_int(char *arg, int num, t_list *stack_a, t_list *stack_b)
{
	char *num_str;
	
	num_str = ft_itoa(num);
	if (!num_str)
		exit_program(stack_a, stack_b);
	if (ft_strncmp(arg, num_str, ft_strlen(num_str)) != 0){
		free(num_str);
		exit_program(stack_a, stack_b);
	}
	free(num_str);
}

/*Check if the stack_a is already sorted*/
void check_stack_sorted(t_list *stack_a, t_list *stack_b, int stack_a_size)
{
	t_list *cur;
	t_list *prev;

	if (stack_a_size <= 1){
		free_list(stack_a);
		free_list(stack_b);
		exit(1);
	}
		
	prev = stack_a;
	cur = stack_a->next;
	while(cur)
	{
		if (prev->content > cur->content)
			return ;
		prev = cur;
		cur = cur->next;
	}
	free_list(stack_a);
	free_list(stack_b);
	exit(1);
}

/*Assign its rank to every element of the stack_a*/
void assign_rank(t_list *stack_a, t_list *stack_b, int stack_a_size)
{
	int *sorted_tab;
	int rank;
	t_list *cur;

	sorted_tab = malloc(sizeof(int) * stack_a_size);
	if (!sorted_tab)
		exit_program(stack_a, stack_b);
	cur = stack_a;
	rank = 0;
	while(cur)
	{
		sorted_tab[rank] = cur->content;
		rank++;
		cur = cur->next;
	}
	quicksort(sorted_tab, 0, stack_a_size - 1);
	cur = stack_a;
	while(cur)
	{
		rank = 0;
		while (cur->content != sorted_tab[rank])
			rank++;
		cur->rank = rank;
		cur = cur->next;
	}
	free(sorted_tab);
}

/*Sort stack_a using the radix sorting algorithm.
Numbers are sorted from least significant (rightmost) to most significant (leftmost) bit.
For each significant bit, the numbers whose corresponding bit is 0 (smaller) are pushed to stack b (pb),
while the numbers whose corresponding bit is 1 (bigger) are kept in stack a by rotating them to the bottom of the stack (ra).
Then all numbers in stack b are pushed back on top of stack a (pa).
We then repeat the operation for all the next (more) significant bits, which progressively sort all number in stack a*/
void radix_sort(t_list **stack_a, t_list **stack_b, int stack_a_size)
{
	int max_rank;
	int max_bits;
	int top_of_a;

	max_rank = stack_a_size -1;
	max_bits = 0;
	while ((max_rank >> max_bits) != 0) 
		++max_bits;
	for (int i = 0 ; i < max_bits ; ++i)
	{
		for(int j = 0 ; j < stack_a_size ; ++j)
		{
			top_of_a = (*stack_a)->rank;
			if (((top_of_a >> i) & 1) == 1) 
				ra(stack_a); 	
			else 
				pb(stack_a, stack_b);
		}
		while (!stack_is_empty(*stack_b)) 
			pa(stack_a, stack_b);
	}
}

/*Sort a stack containing 2 numbers*/
void sort_stack_of_2(t_list **stack_a)
{
	sa(*stack_a);
}

/*Sort a stack containing 3 numbers, there are only
5 possible combinations*/
void sort_stack_of_3(t_list **stack_a)
{
	int first;
	int mid;
	int last;

	first = (*stack_a)->content;
	mid = (*stack_a)->next->content;
	last = (*stack_a)->next->next->content;
	
	if (first > mid && mid < last && first < last)
		sa(*stack_a);
	else if (first > mid && mid > last && first > last){
		sa(*stack_a);
		rra(stack_a);
	}
	else if (first > mid && mid < last && first > last)
		ra(stack_a);
	else if (first < mid && mid > last && first < last){
		sa(*stack_a);
		ra(stack_a);
	}
	else if (first < mid && mid > last && first > last)
		rra(stack_a);
}

/*Sort a stack containing 5 numbers*/
void sort_stack_of_5(t_list **stack_a, t_list **stack_b, int stack_a_size)
{
	assign_rank(*stack_a, *stack_b, stack_a_size);
	while (ft_lstsize(*stack_b) < 2){
		if ((*stack_a)->rank == 0 || (*stack_a)->rank == 4)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	sort_stack_of_3(stack_a);
	// ft_printf("\nafter sort 3 :\n");
	// print_stack(*stack_a);
	// print_stack(*stack_b);
	// ft_printf("---\n");
	for (int i = 0; i < 2; i++){
		pa(stack_a, stack_b);
		if ((*stack_a)->rank == 4)
			ra(stack_a);
	}
}

int main(int argc, char ** argv)
{
	t_list *stack_a;
	t_list *stack_b;
	t_list *node;
	int i;
	int num;
	int stack_a_size;
	
	stack_a = NULL;
	stack_b = NULL;

	if (argc  <= 1)
		return 1;
	
	for(i = argc - 1; i > 0; i--){
		check_arg_is_digit(argv[i], stack_a, stack_b);
		num = ft_atoi(argv[i]);
		node = ft_lstnew(num);
		if (!node)
			exit_program(stack_a, stack_b);
		check_arg_is_int(argv[i], num, stack_a, stack_b);
		check_arg_is_duplicate(num, stack_a, stack_b);
		ft_lstadd_front(&stack_a, node);
	}
	stack_a_size = ft_lstsize(stack_a);
	check_stack_sorted(stack_a, stack_b, stack_a_size);
	// print_stack(stack_a);
	// print_stack(stack_b);

	if (stack_a_size == 2)
		sort_stack_of_2(&stack_a);
	else if (stack_a_size == 3)
		sort_stack_of_3(&stack_a);
	else if (stack_a_size == 5)
		sort_stack_of_5(&stack_a, &stack_b, stack_a_size);
	else{
		assign_rank(stack_a, stack_b, stack_a_size);
		radix_sort(&stack_a, &stack_b, stack_a_size);
	}

	// print_stack(stack_a);
	// print_stack(stack_b);

	free_list(stack_a);
	free_list(stack_b);



}


//Tests operations	
// node = ft_lstnew((void*)4); //prot
// ft_lstadd_back(&stack_a,node);
// node = ft_lstnew((void*)3);
// ft_lstadd_back(&stack_a,node);
// node = ft_lstnew((void*)6);
// ft_lstadd_back(&stack_a,node);

// node = ft_lstnew((void*)7); //prot
// ft_lstadd_back(&stack_b,node);
// node = ft_lstnew((void*)2);
// ft_lstadd_back(&stack_b,node);
// node = ft_lstnew((void*)9);
// ft_lstadd_back(&stack_b,node);

// print_stack(stack_a);
// print_stack(stack_b);

// sa(stack_a);
// sb(stack_b);
// ft_printf("\nsa & sb :\n");
// print_stack(stack_a);
// print_stack(stack_b);

// ss(stack_a, stack_b);
// ft_printf("\nss :\n");
// print_stack(stack_a);
// print_stack(stack_b);

// pa(&stack_a, &stack_b);
// ft_printf("\npa :\n");
// print_stack(stack_a);
// print_stack(stack_b);

// pb(&stack_a, &stack_b);
// ft_printf("\npb :\n");
// print_stack(stack_a);
// print_stack(stack_b);

// ra(&stack_a);
// rb(&stack_b);
// ft_printf("\nra & rb :\n");
// print_stack(stack_a);
// print_stack(stack_b);

// rr(&stack_a, &stack_b);
// ft_printf("\nrr :\n");
// print_stack(stack_a);
// print_stack(stack_b);

// rra(&stack_a);
// rrb(&stack_b);
// ft_printf("\nrra & rrb:\n");
// print_stack(stack_a);
// print_stack(stack_b);

// rrr(&stack_a, &stack_b);
// ft_printf("\nrrr :\n");
// print_stack(stack_a);
// print_stack(stack_b);