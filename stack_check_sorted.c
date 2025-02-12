/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:44:37 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/02/07 12:48:08 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

char	is_reverse_sorted(t_stack *stack)
{
	int	max;
	int	size;
	int	i;

	max = get_max_num(stack);
	size = ft_stacksize(stack);
	while (stack->num != max)
		stack = stack->next;
	i = 0;
	while (i < size - 1)
	{
		if (stack->next->num > stack->num)
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}

char	is_sorted(t_stack *stack)
{
	int	min;
	int	size;
	int	i;

	min = get_min_num(stack);
	size = ft_stacksize(stack);
	while (stack->num != min)
		stack = stack->next;
	i = 0;
	while (i < size - 1)
	{
		if (stack->next->num < stack->num)
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}
