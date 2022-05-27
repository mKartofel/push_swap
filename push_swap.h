/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfiszbin <vfiszbin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:34:15 by vfiszbin          #+#    #+#             */
/*   Updated: 2022/05/27 16:51:00 by vfiszbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/libft/libft.h"
# include "ft_printf/includes/ft_printf.h"

void	print_stack(t_list *stack);
void	print_stack_rank(t_list *stack);
void	sa(t_list *stack_a);
void	sb(t_list *stack_b);
void	ss(t_list *stack_a, t_list *stack_b);
t_list	*pop_node(t_list **lst, t_list *node);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	free_list(t_list *lst);
int		quicksort(int *t, int begin, int end);
int		stack_is_empty(t_list *stack);
void	check_arg_is_digit(char *arg, t_list *stack_a, t_list *stack_b);
void	check_arg_is_duplicate(int num, t_list *stack_a, t_list *stack_b);
void	check_arg_is_int(char *arg, int num, t_list *stack_a, t_list *stack_b);
void	check_stack_sorted(t_list *stack_a, t_list *stack_b, int stack_a_size);
void	exit_program(t_list *stack_a, t_list *stack_b);
void	assign_rank(t_list *stack_a, t_list *stack_b, int stack_a_size);
void	sort_stack_of_2(t_list **stack_a);
void	sort_stack_of_3(t_list **stack_a);
void	sort_stack_of_5(t_list **stack_a, t_list **stack_b, int stack_a_size);
void	radix_sort(t_list **stack_a, t_list **stack_b, int stack_a_size);

#endif