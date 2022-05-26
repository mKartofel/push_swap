/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfiszbin <vfiszbin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:48:37 by vfiszbin          #+#    #+#             */
/*   Updated: 2022/05/26 15:18:02 by vfiszbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main()
{
	t_list *stack_a;
	t_list *stack_b;
	t_list *node;
	
	stack_a = NULL;
	stack_b = NULL;

	node = ft_lstnew((void*)4); //prot
	ft_lstadd_back(&stack_a,node);
	node = ft_lstnew((void*)3);
	ft_lstadd_back(&stack_a,node);
	node = ft_lstnew((void*)6);
	ft_lstadd_back(&stack_a,node);

	
	
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