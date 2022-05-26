/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfiszbin <vfiszbin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:32:24 by vfiszbin          #+#    #+#             */
/*   Updated: 2022/05/26 15:08:40 by vfiszbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Swap the first 2 elements at the top of stack a*/
void sa(t_list *stack_a)
{
	void* tmp;
	
	if (!stack_a || ft_lstsize(stack_a) <= 1)
		return ;
	tmp = stack_a->content;
	stack_a->content = stack_a->next->content;
	stack_a->next->content = tmp;
}

/*Swap the first 2 elements at the top of stack b*/
void sb(t_list *stack_b)
{
	void* tmp;
	
	if (!stack_b || ft_lstsize(stack_b) <= 1)
		return ;
	tmp = stack_b->content;
	stack_b->content = stack_b->next->content;
	stack_b->next->content = tmp;
}

/*sa and sb at the same time*/
void ss(t_list *stack_a, t_list *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

/*Take the first element at the top of b and put it at the top of a*/
void pa(t_list **stack_a, t_list **stack_b)
{
	void* top_of_b;
	
	if (!stack_b || !*stack_b)
		return ;
	top_of_b = pop_node(stack_b, *stack_b);
	ft_lstadd_front(stack_a, top_of_b);
}

/*Take the first element at the top of a and put it at the top of b*/
void pb(t_list **stack_a, t_list **stack_b)
{
	void* top_of_a;
	
	if (!stack_a || !*stack_a)
		return ;
	top_of_a = pop_node(stack_a, *stack_a);
	ft_lstadd_front(stack_b, top_of_a);
}

/*Shift up all elements of stack a by 1.
The first element becomes the last one*/
void ra(t_list **stack_a)
{
	void* top_of_a;
	
	if (!stack_a || !*stack_a)
		return ;
	top_of_a = pop_node(stack_a, *stack_a);
	ft_lstadd_back(stack_a, top_of_a);
}

/*Shift up all elements of stack b by 1.
The first element becomes the last one*/
void rb(t_list **stack_b)
{
	void* top_of_a;
	
	if (!stack_b || !*stack_b)
		return ;
	top_of_a = pop_node(stack_b, *stack_b);
	ft_lstadd_back(stack_b, top_of_a);
}

/*ra and rb at the same time*/
void rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

/*Shift down all elements of stack a by 1.
The last element becomes the first one*/
void rra(t_list **stack_a)
{
	void* last_of_a;
	
	if (!stack_a || !*stack_a)
		return ;
	last_of_a = pop_node(stack_a, ft_lstlast(*stack_a));
	ft_lstadd_front(stack_a, last_of_a);
}

/*Shift down all elements of stack b by 1.
The last element becomes the first one*/
void rrb(t_list **stack_b)
{
	void* last_of_b;
	
	if (!stack_b || !*stack_b)
		return ;
	last_of_b = pop_node(stack_b, ft_lstlast(*stack_b));
	ft_lstadd_front(stack_b, last_of_b);
}

/*rra and rrb at the same time*/
void rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}