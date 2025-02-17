/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:48:33 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/02/17 15:08:56 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf_bonus.h"

void	sort_three_desc(t_stack **stack, char stack_letter)
{
	if (!is_circular_sorted_descending(*stack))
		swap_print(stack, stack_letter);
}

void	sort_three_asc(t_stack **stack, char stack_letter)
{
	if (!is_circular_sorted_ascending(*stack))
		swap_print(stack, stack_letter);
}

void	get_max_on_top(t_stack **stack, char stack_letter)
{
	int	pos;
	int	size;
	int	i;

	pos = get_pos_max_num(*stack);
	size = ft_stacksize(*stack);
	if (pos == 0)
		return ;
	i = 0;
	if (pos <= (size / 2))
	{
		while (i++ < pos)
			rotate_print(stack, stack_letter);
	}
	else
	{
		while (i++ < size - pos)
			reverse_rotate_print(stack, stack_letter);
	}
}

void	get_min_on_top(t_stack **stack, char stack_letter)
{
	int	pos;
	int	size;
	int	i;

	pos = get_pos_min_num(*stack);
	size = ft_stacksize(*stack);
	if (pos == 0)
		return ;
	i = 0;
	if (pos <= (size / 2))
	{
		while (i++ < pos)
			rotate_print(stack, stack_letter);
	}
	else
	{
		while (i++ < size - pos)
			reverse_rotate_print(stack, stack_letter);
	}
}
