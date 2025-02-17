/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:14:16 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/02/16 15:12:47 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_seq	init_seq(void)
{
	t_seq	seq;

	seq.moves = 0;
	seq.rb = 0;
	seq.ra = 0;
	seq.rr = 0;
	seq.pb = 0;
	seq.pa = 0;
	seq.rra = 0;
	seq.rrb = 0;
	seq.rrr = 0;
	seq.sa = 0;
	seq.sb = 0;
	seq.ss = 0;
	return (seq);
}

t_seq	opt_seq(t_seq seq)
{
	while (seq.ra > 0 && seq.rb > 0)
	{
		seq.rr ++;
		seq.ra--;
		seq.rb--;
	}
	while (seq.rra > 0 && seq.rrb > 0)
	{
		seq.rrr++;
		seq.rra--;
		seq.rrb--;
	}
	return (seq);
}

void	apply_seq(t_stack **stack_a, t_stack **stack_b, t_seq best_move)
{
	while (best_move.rrr-- > 0)
		reverse_rotate_both_print(stack_a, stack_b);
	while (best_move.rr-- > 0)
		rotate_both_print(stack_a, stack_b);
	while (best_move.ra-- > 0)
		rotate_print(stack_a, 'a');
	while (best_move.rb-- > 0)
		rotate_print(stack_b, 'b');
	while (best_move.rra-- > 0)
		reverse_rotate_print(stack_a, 'a');
	while (best_move.rrb-- > 0)
		reverse_rotate_print(stack_b, 'b');
	if (best_move.sa)
		swap_print(stack_a, 'a');
	if (best_move.sb)
		swap_print(stack_b, 'b');
	if (best_move.pa)
		push_print(stack_b, stack_a, 'a');
	if (best_move.pb)
		push_print(stack_a, stack_b, 'b');
}
