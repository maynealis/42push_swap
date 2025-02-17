/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_pop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:37:53 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/02/12 09:27:19 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	first = *stack;
	last = first->prev;
	last->next = new;
	first->prev = new;
	new->next = first;
	new->prev = last;
}

void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	first = *stack;
	last = first->prev;
	new->next = first;
	new->prev = last;
	first->prev = new;
	last->next = new;
	*stack = new;
}

t_stack	*ft_stackremove_front(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!stack || !*stack)
		return (NULL);
	first = *stack;
	second = first->next;
	last = first->prev;
	first->next = NULL;
	first->prev = NULL;
	if (second == first)
	{
		*stack = NULL;
		return (first);
	}
	second->prev = last;
	last->next = second;
	*stack = second;
	return (first);
}
