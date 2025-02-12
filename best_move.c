/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:54:01 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/02/12 09:32:53 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_seq	get_min_moves_r_r(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_seq	seq;

	seq = init_seq();
	i = 0;
	seq.rb = moves_with_r(stack_a->num, stack_b);
	seq.moves = seq.rb;
	seq.number = stack_a->num; //TODO DEBUG
	while (i < ft_stacksize(stack_a) && i < ft_stacksize(stack_b))
	{
		if (moves_with_r(stack_a->num, stack_b) < seq.moves && i < seq.moves)
		{
			seq.rb = moves_with_r(stack_a->num, stack_b);
			seq.ra = i;
			seq.number = stack_a->num; //TODO DEBUG
			if (seq.rb >= seq.ra)
				seq.moves = seq.rb;
			else
				seq.moves = seq.ra;
		}
		if (i >= ft_stacksize(stack_a))
			break ;
		stack_a = stack_a->next;
		i++;
	}
	seq.pb = 1;
	return (seq);
}

t_seq	get_min_moves_r_rr(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_seq	seq;

	seq = init_seq();
	i = 0;
	seq.rrb = moves_with_rr(stack_a->num, stack_b);
	seq.moves = seq.rrb;
	seq.number = stack_a->num; //TODO DEBUG
	while (i < ft_stacksize(stack_a) && i < ft_stacksize(stack_b))
	{
		if (moves_with_rr(stack_a->num, stack_b) + i < seq.moves)
		{
			seq.rrb = moves_with_rr(stack_a->num, stack_b);
			if (seq.rrb > ft_stacksize(stack_b) / 2)
			{
				seq.rb = ft_stacksize(stack_b) - seq.rrb;
				seq.rrb = 0;
			}
			if (i > ft_stacksize(stack_a) / 2)
				seq.rra = ft_stacksize(stack_a) - i;
			else
				seq.ra = i;
			if (seq.ra > 0 && seq.rb > 0 && seq.ra > seq.rb)
				seq.moves = seq.ra;
			else if (seq.ra > 0 && seq.rb > 0 && seq.ra <= seq.rb)
				seq.moves = seq.rb;
			else if (seq.rra > 0 && seq.rrb > 0 && seq.rra > seq.rrb)
				seq.moves = seq.rra;
			else if (seq.rra > 0 && seq.rrb > 0 && seq.rra <= seq.rrb)
				seq.moves = seq.rrb;
			else
				seq.moves = seq.rb + seq.rrb + seq.ra + seq.rra;
			seq.number = stack_a->num; //TODO DEBUG
		}
		if (i >= ft_stacksize(stack_a))
			break ;
		stack_a = stack_a->next;
		i++;
	}
	seq.pb = 1;
	return (seq);
}

t_seq	get_min_moves_rr_r(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_seq	seq;

	seq = init_seq();
	i = 0;
	seq.rb = moves_with_r(stack_a->num, stack_b);
	seq.moves = seq.rb;
	seq.number = stack_a->num; //TODO DEBUG
	while (i < ft_stacksize(stack_a) && i < ft_stacksize(stack_b))
	{
		if (moves_with_r(stack_a->num, stack_b) + i < seq.moves)
		{
			seq.rb = moves_with_r(stack_a->num, stack_b);
			if (seq.rb > ft_stacksize(stack_b) / 2)
			{
				seq.rrb = ft_stacksize(stack_b) - seq.rb;
				seq.rb = 0;
			}
			if (i > ft_stacksize(stack_a) / 2)
				seq.ra = ft_stacksize(stack_a) - i;
			else
				seq.rra = i;
			if (seq.ra > 0 && seq.rb > 0 && seq.ra > seq.rb)
				seq.moves = seq.ra;
			else if (seq.ra > 0 && seq.rb > 0 && seq.ra <= seq.rb)
				seq.moves = seq.rb;
			else if (seq.rra > 0 && seq.rrb > 0 && seq.rra > seq.rrb)
				seq.moves = seq.rra;
			else if (seq.rra > 0 && seq.rrb > 0 && seq.rra <= seq.rrb)
				seq.moves = seq.rrb;
			else
				seq.moves = seq.rb + seq.rra + seq.ra + seq.rrb;
			seq.number = stack_a->num; //TODO DEBUG
		}
		if (i >= ft_stacksize(stack_a))
			break ;
		stack_a = stack_a->prev;
		i++;
	}
	seq.pb = 1;
	return (seq);
}

t_seq	get_min_moves_rr_rr(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_seq	seq;

	seq = init_seq();
	i = 0;
	seq.rrb = moves_with_rr(stack_a->num, stack_b);
	seq.moves = seq.rrb;
	seq.number = stack_a->num; //TODO DEBUG
	while (i < ft_stacksize(stack_a) && i < ft_stacksize(stack_b))
	{
		if (moves_with_rr(stack_a->num, stack_b) < seq.moves && i < seq.moves)
		{
			seq.rrb = moves_with_rr(stack_a->num, stack_b);
			seq.rra = i;
			seq.number = stack_a->num; //TODO DEBUG
			if (seq.rrb >= seq.rra)
				seq.moves = seq.rrb;
			else
				seq.moves = seq.rra;
		}
		if (i >= ft_stacksize(stack_a))
			break ;
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
	if (get_min_moves_r_rr(stack_a, stack_b).moves < best_seq.moves)
		best_seq = get_min_moves_r_rr(stack_a, stack_b);
	else if (get_min_moves_rr_r(stack_a, stack_b).moves < best_seq.moves)
		best_seq = get_min_moves_rr_r(stack_a, stack_b);
	else if (get_min_moves_rr_rr(stack_a, stack_b).moves < best_seq.moves)
		best_seq = get_min_moves_rr_rr(stack_a, stack_b);
	return (best_seq);
}
