/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_min_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:37:56 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/02/07 13:17:27 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	get_max_num(t_stack *stack)
{
	t_stack	*first;
	int		max;

	first = stack;
	max = first->num;
	while (stack)
	{
		stack = stack->next;
		if (stack == first)
			break ;
		if (stack->num > max)
			max = stack->num;
	}
	return (max);
}

int	get_min_num(t_stack *stack)
{
	t_stack	*first;
	int		min;

	first = stack;
	min = first->num;
	while (stack)
	{
		stack = stack->next;
		if (stack == first)
			break ;
		if (stack->num < min)
			min = stack->num;
	}
	return (min);
}

int	get_pos_max_num(t_stack *stack)
{
	t_stack	*first;
	int		max;
	int		pos;
	int		i;

	first = stack;
	max = first->num;
	pos = 0;
	i = 1;
	while (stack)
	{
		stack = stack->next;
		if (stack == first)
			break ;
		if (stack->num > max)
		{
			max = stack->num;
			pos = i;
		}
		i++;
	}
	return (pos);
}

int	get_pos_min_num(t_stack *stack)
{
	t_stack	*first;
	int		min;
	int		pos;
	int		i;

	first = stack;
	min = first->num;
	pos = 0;
	i = 1;
	while (stack)
	{
		stack = stack->next;
		if (stack == first)
			break ;
		if (stack->num < min)
		{
			min = stack->num;
			pos = i;
		}
		i++;
	}
	return (pos);
}
