/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfiszbin <vfiszbin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:57:36 by vfiszbin          #+#    #+#             */
/*   Updated: 2022/05/27 16:39:52 by vfiszbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	print_stack(t_list *stack)
// {
// 	while (stack)
// 	{
// 		ft_printf("%d ", (stack->content));
// 		stack = stack->next;
// 	}
// 	ft_printf("\n");
// }

// void	print_stack_rank(t_list *stack)
// {
// 	while (stack){
// 		ft_printf("%d ", (stack->rank));
// 		stack = stack->next;
// 	}
// 	ft_printf("\n");
// }

/*If the node to pop is the first of lst*/
int	pop_first_node(t_list **lst, t_list *node, t_list *cur)
{
	if (cur == node)
	{
		*lst = cur->next;
		cur->next = NULL;
		return (1);
	}
	return (0);
}

/*Remove the node from lst and return it. Return NULL if node is not
found in lst*/
t_list	*pop_node(t_list **lst, t_list *node)
{
	t_list	*cur;
	t_list	*prev;

	if (lst == NULL || *lst == NULL || node == NULL)
		return (NULL);
	cur = *lst;
	if (pop_first_node(lst, node, cur) == 1)
		return (cur);
	prev = cur;
	cur = cur->next;
	while (cur)
	{
		if (cur == node)
		{
			prev->next = cur->next;
			cur->next = NULL;
			return (cur);
		}
		prev = cur;
		cur = cur->next;
	}
	return (NULL);
}

/*Free all memeory allocated for the list*/
void	free_list(t_list *lst)
{
	t_list	*tmp;
	t_list	*cur;

	cur = lst;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
}

/*Test if the stack i sempty*/
int	stack_is_empty(t_list *stack)
{
	if (stack == NULL)
		return (1);
	return (0);
}
