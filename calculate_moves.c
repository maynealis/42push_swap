/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:43:27 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/02/12 17:08:02 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"

int	moves_with_r(int n, t_stack *stack)
{
	int	size;
	int	i;
	int	moves;
	int	last;
	int	first;

	i = 0;
	size = ft_stacksize(stack);
	int	max = get_max_num(stack);
	moves = 0;
	while (i < size)
	{
		last = stack->prev->num;
		first = stack->num;
		if (max == first && (n > first || n < last))
			break ;
		else if (n > first && n < last)
			break ;
		else
		{
			rotate(&stack);
			moves++;
		}
		i++;
	}
	return (moves);
}

int	moves_with_rr(int n, t_stack *stack)
{
	int	size;
	int	i;
	int	moves;
	int	last;
	int	first;

	i = 0;
	size = ft_stacksize(stack);
	int	max = get_max_num(stack);
	moves = 0;
	while (i < size)
	{
		last = stack->prev->num;
		first = stack->num;
		if (max == first && (n > first || n < last))
			break ;
		else if (n > first && n < last)
			break ;
		else
		{
			reverse_rotate(&stack);
			moves++;
		}
		i++;
	}
	return (moves);
}
