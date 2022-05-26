/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfiszbin <vfiszbin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:48:37 by vfiszbin          #+#    #+#             */
/*   Updated: 2022/05/26 18:56:44 by vfiszbin         ###   ########.fr       */
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

int main(int argc, char ** argv)
{
	t_list *stack_a;
	t_list *stack_b;
	t_list *node;
	int i;
	
	stack_a = NULL;
	stack_b = NULL;

	if (argc  <= 1)
		return 1;
	
	for(i = argc - 1; i > 0; i--){
		check_arg_is_digit(argv[i], stack_a, stack_b);
		node = ft_lstnew(ft_atoi(argv[i]));
		if (!node)
			exit_program(stack_a, stack_b);
		ft_lstadd_front(&stack_a, node);
	}

	// print_stack(stack_a);
	// print_stack(stack_b);


	// node = ft_lstnew((void*)4); //prot
	// ft_lstadd_back(&stack_a,node);
	// node = ft_lstnew((void*)3);
	// ft_lstadd_back(&stack_a,node);
	// node = ft_lstnew((void*)6);
	// ft_lstadd_back(&stack_a,node);

	sort_stack(&stack_a, &stack_b);
	// ft_printf("\nafter sort :\n");
	// print_stack(stack_a);
	// print_stack(stack_b);

	push_all_b_to_a(&stack_a, &stack_b);

	// ft_printf("\nafter push all b to a :\n");
	// print_stack(stack_a);
	// print_stack(stack_b);
	
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
}