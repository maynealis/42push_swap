/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:43:27 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/02/14 16:29:38 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	moves_with_r(int n, t_stack *stack)
{
	int	size;
	int	max;
	int	moves;
	int	last;
	int	first;

	size = ft_stacksize(stack);
	max = get_max_num(stack);
	moves = 0;
	while (moves < size)
	{
		last = stack->prev->num;
		first = stack->num;
		if (max == first && (n > first || n < last))
			break ;
		else if (n > first && n < last)
			break ;
		rotate(&stack);
		moves++;
	}
	return (moves);
}

int	moves_with_rr(int n, t_stack *stack)
{
	int	size;
	int	max;
	int	moves;
	int	last;
	int	first;

	size = ft_stacksize(stack);
	max = get_max_num(stack);
	moves = 0;
	while (moves < size)
	{
		last = stack->prev->num;
		first = stack->num;
		if (max == first && (n > first || n < last))
			break ;
		else if (n > first && n < last)
			break ;
		reverse_rotate(&stack);
		moves++;
	}
	return (moves);
}
