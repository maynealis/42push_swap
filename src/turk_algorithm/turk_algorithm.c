/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:12:20 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/02/16 15:26:24 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	turk_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	t_seq	seq;
	t_seq	opt;
	int		l;
	int		f;

	push_n_print(3, stack_a, stack_b, 'b');
	sort_three_desc(stack_b, 'b');
	while (ft_stacksize(*stack_a) > 3)
	{
		seq = get_best_move(*stack_a, *stack_b);
		opt = opt_seq(seq);
		apply_seq(stack_a, stack_b, opt);
	}
	sort_three_asc(stack_a, 'a');
	while (*stack_b)
	{
		l = (*stack_a)->prev->num;
		f = (*stack_a)->num;
		if ((l <= f && (*stack_b)->num < f && (*stack_b)->num > l)
			|| (l >= f && ((*stack_b)->num < f || (*stack_b)->num > l)))
			push_print(stack_b, stack_a, 'a');
		else
			reverse_rotate_print(stack_a, 'a');
	}
	get_min_on_top(stack_a, 'a');
}
