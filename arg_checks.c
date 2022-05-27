/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfiszbin <vfiszbin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:41:31 by vfiszbin          #+#    #+#             */
/*   Updated: 2022/05/27 17:21:17 by vfiszbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Check if arg is a number*/
void	check_arg_is_digit(char *arg, t_list *stack_a, t_list *stack_b)
{
	int	i;

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

/*Check whether the argument is a duplicate of an existing element of
the stack*/
void	check_arg_is_duplicate(int num, t_list *stack_a, t_list *stack_b)
{
	t_list	*cur;

	cur = stack_a;
	while (cur)
	{
		if (cur->content == num)
			exit_program(stack_a, stack_b);
		cur = cur->next;
	}
}

/*Check if the argument is a valid C integer that does not overflow/underflow*/
void	check_arg_is_int(char *arg, int num, t_list *stack_a, t_list *stack_b)
{
	char	*num_str;

	num_str = ft_itoa(num);
	if (!num_str)
		exit_program(stack_a, stack_b);
	if (ft_strncmp(arg, num_str, ft_strlen(num_str)) != 0)
	{
		free(num_str);
		exit_program(stack_a, stack_b);
	}
	free(num_str);
}

/*Check if the stack_a is already sorted*/
void	check_stack_sorted(t_list *stack_a, t_list *stack_b, int stack_a_size)
{
	t_list	*cur;
	t_list	*prev;

	if (stack_a_size <= 1)
	{
		free_list(stack_a);
		free_list(stack_b);
		exit(1);
	}
	prev = stack_a;
	cur = stack_a->next;
	while (cur)
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
