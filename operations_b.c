/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfiszbin <vfiszbin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:08:56 by vfiszbin          #+#    #+#             */
/*   Updated: 2022/05/27 16:12:33 by vfiszbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Swap the first 2 elements at the top of stack b*/
void	sb(t_list *stack_b)
{
	int	tmp;

	if (!stack_b || ft_lstsize(stack_b) <= 1)
		return ;
	tmp = stack_b->content;
	stack_b->content = stack_b->next->content;
	stack_b->next->content = tmp;
	ft_printf("sb\n");
}

/*Take the first element at the top of a and put it at the top of b*/
void	pb(t_list **stack_a, t_list **stack_b)
{
	void	*top_of_a;

	if (!stack_a || !*stack_a)
		return ;
	top_of_a = pop_node(stack_a, *stack_a);
	ft_lstadd_front(stack_b, top_of_a);
	ft_printf("pb\n");
}

/*Shift up all elements of stack b by 1.
The first element becomes the last one*/
void	rb(t_list **stack_b)
{
	void	*top_of_a;

	if (!stack_b || !*stack_b)
		return ;
	top_of_a = pop_node(stack_b, *stack_b);
	ft_lstadd_back(stack_b, top_of_a);
	ft_printf("rb\n");
}

/*Shift down all elements of stack b by 1.
The last element becomes the first one*/
void	rrb(t_list **stack_b)
{
	void	*last_of_b;

	if (!stack_b || !*stack_b)
		return ;
	last_of_b = pop_node(stack_b, ft_lstlast(*stack_b));
	ft_lstadd_front(stack_b, last_of_b);
	ft_printf("rrb\n");
}
