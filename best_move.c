/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:54:01 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/02/14 16:35:22 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_seq	get_min_moves_r_r(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		size_a;
	t_seq	seq;

	seq = init_seq();
	i = 0;
	size_a = ft_stacksize(stack_a);
	seq.rb = moves_with_r(stack_a->num, stack_b);
	seq.moves = seq.rb;
	while (i < size_a)
	{
		if (moves_with_r(stack_a->num, stack_b) < seq.moves && i < seq.moves)
		{
			seq.rb = moves_with_r(stack_a->num, stack_b);
			seq.ra = i;
			if (seq.rb >= seq.ra)
				seq.moves = seq.rb;
			else
				seq.moves = seq.ra;
		}
		stack_a = stack_a->next;
		i++;
	}
	seq.pb = 1;
	return (seq);
}

t_seq	get_min_moves_r_rr(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		size_a;
	t_seq	seq;

	seq = init_seq();
	i = 0;
	size_a = ft_stacksize(stack_a);
	seq.rrb = moves_with_rr(stack_a->num, stack_b);
	seq.moves = seq.rrb;
	while (i < size_a)
	{
		if (moves_with_rr(stack_a->num, stack_b) + i < seq.moves)
		{
			seq.rrb = moves_with_rr(stack_a->num, stack_b);
			seq.ra = i;
			seq.moves = seq.rrb + seq.ra;
		}
		stack_a = stack_a->next;
		i++;
	}
	seq.pb = 1;
	return (seq);
}

t_seq	get_min_moves_rr_r(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		size_a;
	t_seq	seq;

	seq = init_seq();
	i = 0;
	size_a = ft_stacksize(stack_a);
	seq.rb = moves_with_r(stack_a->num, stack_b);
	seq.moves = seq.rb;
	while (i < size_a)
	{
		if (moves_with_r(stack_a->num, stack_b) + i < seq.moves)
		{
			seq.rb = moves_with_r(stack_a->num, stack_b);
			seq.rra = i;
			seq.moves = seq.rb + seq.rra;
		}
		stack_a = stack_a->prev;
		i++;
	}
	seq.pb = 1;
	return (seq);
}

t_seq	get_min_moves_rr_rr(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		size_a;
	t_seq	seq;

	seq = init_seq();
	i = 0;
	size_a = ft_stacksize(stack_a);
	seq.rrb = moves_with_rr(stack_a->num, stack_b);
	seq.moves = seq.rrb;
	while (i < size_a)
	{
		if (moves_with_rr(stack_a->num, stack_b) < seq.moves && i < seq.moves)
		{
			seq.rrb = moves_with_rr(stack_a->num, stack_b);
			seq.rra = i;
			if (seq.rrb >= seq.rra)
				seq.moves = seq.rrb;
			else
				seq.moves = seq.rra;
		}
		stack_a = stack_a->prev;
		i++;
	}
	seq.pb = 1;
	return (seq);
}

t_seq	get_best_move(t_stack *stack_a, t_stack *stack_b)
{
	t_seq	best_seq;

	best_seq = get_min_moves_r_r(stack_a, stack_b);
	if (get_min_moves_rr_rr(stack_a, stack_b).moves < best_seq.moves)
		best_seq = get_min_moves_rr_rr(stack_a, stack_b);
	else if (get_min_moves_r_rr(stack_a, stack_b).moves < best_seq.moves)
		best_seq = get_min_moves_r_rr(stack_a, stack_b);
	else if (get_min_moves_rr_r(stack_a, stack_b).moves < best_seq.moves)
		best_seq = get_min_moves_rr_r(stack_a, stack_b);
	return (best_seq);
}
