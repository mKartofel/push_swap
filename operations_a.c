/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfiszbin <vfiszbin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:32:24 by vfiszbin          #+#    #+#             */
/*   Updated: 2022/05/27 16:13:44 by vfiszbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Swap the first 2 elements at the top of stack a*/
void	sa(t_list *stack_a)
{
	int	tmp;

	if (!stack_a || ft_lstsize(stack_a) <= 1)
		return ;
	tmp = stack_a->content;
	stack_a->content = stack_a->next->content;
	stack_a->next->content = tmp;
	ft_printf("sa\n");
}

/*Take the first element at the top of b and put it at the top of a*/
void	pa(t_list **stack_a, t_list **stack_b)
{
	void	*top_of_b;

	if (!stack_b || !*stack_b)
		return ;
	top_of_b = pop_node(stack_b, *stack_b);
	ft_lstadd_front(stack_a, top_of_b);
	ft_printf("pa\n");
}

/*Shift up all elements of stack a by 1.
The first element becomes the last one*/
void	ra(t_list **stack_a)
{
	void	*top_of_a;

	if (!stack_a || !*stack_a)
		return ;
	top_of_a = pop_node(stack_a, *stack_a);
	ft_lstadd_back(stack_a, top_of_a);
	ft_printf("ra\n");
}

/*Shift down all elements of stack a by 1.
The last element becomes the first one*/
void	rra(t_list **stack_a)
{
	void	*last_of_a;

	if (!stack_a || !*stack_a)
		return ;
	last_of_a = pop_node(stack_a, ft_lstlast(*stack_a));
	ft_lstadd_front(stack_a, last_of_a);
	ft_printf("rra\n");
}
