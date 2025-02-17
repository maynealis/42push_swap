/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:30:23 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/02/17 14:08:29 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_printf_bonus.h"

void	swap(t_stack **stack)
{
	t_stack	*first;

	if (!stack || !*stack || ft_stacksize(*stack) < 2)
		return ;
	first = ft_stackremove_front(stack);
	*stack = (*stack)->next;
	ft_stackadd_front(stack, first);
	*stack = (*stack)->prev;
}

void	swap_both(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	swap_print(t_stack **stack, char letter)
{
	swap(stack);
	ft_printf("s%c\n", letter);
}

void	swap_both_print(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
