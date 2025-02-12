/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:52:50 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/02/09 19:09:08 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_stacksize(t_stack *stack)
{
	t_stack	*first;
	int		size;

	if (!stack)
		return (0);
	first = stack;
	size = 1;
	while (stack)
	{
		stack = stack->next;
		if (stack == first)
			break ;
		size++;
	}
	return (size);
}

t_stack	*ft_stacknew(int number)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->num = number;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_stackfree(t_stack **stack)
{
	t_stack	*next;
	int		size;
	int		i;

	if (!stack)
		return ;
	size = ft_stacksize(*stack);
	i = 0;
	while (i < size)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
		i++;
	}
	*stack = NULL;
}
