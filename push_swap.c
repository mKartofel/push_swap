/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfiszbin <vfiszbin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:48:37 by vfiszbin          #+#    #+#             */
/*   Updated: 2022/05/27 17:58:18 by vfiszbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Free the two stacks before writing Error in stderror and exiting program*/
void	exit_program(t_list *stack_a, t_list *stack_b, t_list *node)
{
	write(2, "Error\n", 6);
	free_list(stack_a);
	free_list(stack_b);
	if (node != NULL)
		free(node);
	exit(1);
}

void	fill_tab(int *sorted_tab, t_list *stack_a)
{
	t_list	*cur;
	int		i;

	cur = stack_a;
	i = 0;
	while (cur)
	{
		sorted_tab[i] = cur->content;
		i++;
		cur = cur->next;
	}
}

/*Assign its rank to every element of the stack_a*/
void	assign_rank(t_list *stack_a, t_list *stack_b, int stack_a_size)
{
	int		*sorted_tab;
	int		rank;
	t_list	*cur;

	sorted_tab = malloc(sizeof(int) * stack_a_size);
	if (!sorted_tab)
		exit_program(stack_a, stack_b, NULL);
	fill_tab(sorted_tab, stack_a);
	quicksort(sorted_tab, 0, stack_a_size - 1);
	cur = stack_a;
	while (cur)
	{
		rank = 0;
		while (cur->content != sorted_tab[rank])
			rank++;
		cur->rank = rank;
		cur = cur->next;
	}
	free(sorted_tab);
}

void	init_stack(t_list **stack_a, t_list **stack_b, int argc, char **argv)
{
	int		i;
	int		num;
	t_list	*node;

	i = argc - 1;
	while (i > 0)
	{
		check_arg_is_digit(argv[i], *stack_a, *stack_b);
		num = ft_atoi(argv[i]);
		node = ft_lstnew(num);
		if (!node)
			exit_program(*stack_a, *stack_b, NULL);
		check_duplicate(num, *stack_a, *stack_b, node);
		ft_lstadd_front(stack_a, node);
		check_arg_is_int(argv[i], num, *stack_a, *stack_b);
		i--;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		stack_a_size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (1);
	init_stack(&stack_a, &stack_b, argc, argv);
	stack_a_size = ft_lstsize(stack_a);
	check_stack_sorted(stack_a, stack_b, stack_a_size);
	if (stack_a_size == 2)
		sort_stack_of_2(&stack_a);
	else if (stack_a_size == 3)
		sort_stack_of_3(&stack_a);
	else if (stack_a_size == 5)
		sort_stack_of_5(&stack_a, &stack_b, stack_a_size);
	else
	{
		assign_rank(stack_a, stack_b, stack_a_size);
		radix_sort(&stack_a, &stack_b, stack_a_size);
	}
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