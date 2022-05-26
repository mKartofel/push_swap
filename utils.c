/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfiszbin <vfiszbin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:57:36 by vfiszbin          #+#    #+#             */
/*   Updated: 2022/05/26 15:05:24 by vfiszbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *stack)
{
	while (stack){
		ft_printf("%d ", (int*)(stack->content));
		stack = stack->next;
	}
	ft_printf("\n");
}

/*Remove the node from lst and return it. Return NULL if node is not
found in lst*/
t_list	*pop_node(t_list **lst, t_list *node)
{
	t_list *cur;
	t_list *prev;

	if (lst == NULL || *lst == NULL || node == NULL)
		return (NULL);
	cur = *lst;
	if (cur == node){
		*lst = cur->next;
		cur->next = NULL;
		return cur;
	}
	prev = cur;
	cur = cur->next;
	while (cur){
		if (cur == node)
		{
			prev->next = cur->next;
			// ft_printf("cur = %d ", (int*)(cur->content));
			// ft_printf("prev = %d ", (int*)(prev->content));
			cur->next = NULL;
			return cur;
		}
		prev = cur;
		cur = cur->next;
	}
	return NULL;
}