/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:44:37 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/02/17 14:23:45 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief Checks if the stack is strictly sorted in ascending order.
 *
 * This function verifies whether the stack elements are arranged in a 
 * strictly increasing order from the current position onward.
 *
 * @param stack Pointer to the head of the stack.
 * @return 1 if the stack is strictly sorted in ascending order, 0 otherwise.
 */
char	is_strictly_sorted(t_stack *stack)
{
	int	size;
	int	i;

	size = ft_stacksize(stack);
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

/**
 * @brief Checks if the stack is circularly sorted in descending order.
 *
 * The function determines whether the stack follows a circularly 
 * sorted order, meaning the largest number is placed first, and all 
 * other elements are sorted in descending order.
 *
 * @param stack Pointer to the head of the stack.
 * @return 1 if the stack is circularly sorted in descending order, 0 otherwise.
 */
char	is_circular_sorted_descending(t_stack *stack)
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

/**
 * @brief Checks if the stack is circularly sorted in ascending order.
 *
 * This function verifies whether the stack follows a circularly sorted 
 * order, where the smallest number appears first and all subsequent elements 
 * are arranged in ascending order.
 *
 * @param stack Pointer to the head of the stack.
 * @return 1 if the stack is circularly sorted in ascending order, 0 otherwise.
 */
char	is_circular_sorted_ascending(t_stack *stack)
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
