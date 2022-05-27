/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfiszbin <vfiszbin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:47:17 by vfiszbin          #+#    #+#             */
/*   Updated: 2022/05/27 17:02:54 by vfiszbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Sort a stack containing 2 numbers*/
void	sort_stack_of_2(t_list **stack_a)
{
	sa(*stack_a);
}

/*Sort a stack containing 3 numbers, there are only
5 possible combinations*/
void	sort_stack_of_3(t_list **stack_a)
{
	int	first;
	int	mid;
	int	last;

	first = (*stack_a)->content;
	mid = (*stack_a)->next->content;
	last = (*stack_a)->next->next->content;
	if (first > mid && mid < last && first < last)
		sa(*stack_a);
	else if (first > mid && mid > last && first > last)
	{
		sa(*stack_a);
		rra(stack_a);
	}
	else if (first > mid && mid < last && first > last)
		ra(stack_a);
	else if (first < mid && mid > last && first < last)
	{
		sa(*stack_a);
		ra(stack_a);
	}
	else if (first < mid && mid > last && first > last)
		rra(stack_a);
}

/*Sort a stack containing 5 numbers. Push the min and max to stack b,
sort the 3 remaining values in stack a, then push min and max back to stack a
at their correct position*/
void	sort_stack_of_5(t_list **stack_a, t_list **stack_b, int stack_a_size)
{
	int	i;

	assign_rank(*stack_a, *stack_b, stack_a_size);
	while (ft_lstsize(*stack_b) < 2)
	{
		if ((*stack_a)->rank == 0 || (*stack_a)->rank == 4)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	sort_stack_of_3(stack_a);
	i = 0;
	while (i < 2)
	{
		pa(stack_a, stack_b);
		if ((*stack_a)->rank == 4)
			ra(stack_a);
		i++;
	}
}

void	init_var_for_radix(int *max_rank, int *max_bits, int *i,
int stack_a_size)
{
	*max_rank = stack_a_size - 1;
	*max_bits = 0;
	while ((*max_rank >> *max_bits) != 0)
		*max_bits = *max_bits + 1;
	*i = 0;
}

/*Sort stack_a using the radix sorting algorithm.
Numbers are sorted from least significant (rightmost) to most significant 
(leftmost) bit. For each significant bit, the numbers whose corresponding 
bit is 0 (smaller) are pushed to stack b (pb), while the numbers whose 
corresponding bit is 1 (bigger) are kept in stack a by rotating them to the 
bottom of the stack (ra).
Then all numbers in stack b are pushed back on top of stack a (pa).
We then repeat the operation for all the next (more) significant bits, 
which progressively sort all number in stack a*/
void	radix_sort(t_list **stack_a, t_list **stack_b, int stack_a_size)
{
	int	max_rank;
	int	max_bits;
	int	top_of_a;
	int	i;
	int	j;

	init_var_for_radix(&max_rank, &max_bits, &i, stack_a_size);
	while (i < max_bits)
	{
		j = 0;
		while (j < stack_a_size)
		{
			top_of_a = (*stack_a)->rank;
			if (((top_of_a >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (!stack_is_empty(*stack_b))
			pa(stack_a, stack_b);
		i++;
	}
}
