/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:04:48 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/03/26 13:06:44 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "stack.h"

// Algorithms
typedef enum e_algorithm
{
	RADIX = 0,
	TURK = 1
}	t_algorithm;

// Define main algorithm
# ifndef ALGORITHM
#  define ALGORITHM TURK
# endif

// STRUCT SEQUENCE
typedef struct s_seq
{
	int	moves;
	int	rb;
	int	ra;
	int	rr;
	int	pb;
	int	rra;
	int	rrb;
	int	rrr;
	int	pa;
	int	sa;
	int	sb;
	int	ss;
}	t_seq;

// Parse the arguments and fill the stack
char	is_valid_argument(char *arg, t_stack *a);
void	fill_stack(int argc, char **args, t_stack **stack_a, t_stack **stack_b);
void	print_error_message_and_clean(t_stack **stack_a, t_stack **stack_b);
void	print_stacks(t_stack *a, t_stack *b);

// Rules
void	push(t_stack **src, t_stack **dst);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	swap(t_stack **stack);
void	push_print(t_stack **src, t_stack **dst, char letter);
void	push_n_print(int n, t_stack **src, t_stack **dst, char letter);
void	rotate_print(t_stack **stack, char letter);
void	reverse_rotate_print(t_stack **stack, char letter);
void	swap_print(t_stack **stack, char letter);
void	rotate_both_print(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_both_print(t_stack **stack_a, t_stack **stack_b);
void	rotate_both(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);
void	swap_both(t_stack **stack_a, t_stack **stack_b);

// Sort
void	get_max_on_top(t_stack **stack, char stack_letter);
void	get_min_on_top(t_stack **stack, char stack_letter);
void	sort_three_desc(t_stack **stack, char stack_letter);
void	sort_three_asc(t_stack **stack, char stack_letter);
void	sort_three(t_stack **stack, char stack_letter);

// Algorithm turk - calculate best move
int		moves_with_r(int n, t_stack *stack);
int		moves_with_rr(int n, t_stack *stack);
t_seq	get_best_move(t_stack *stack_a, t_stack *stack_b);
void	turk_algorithm(t_stack **stack_a, t_stack **stack_b);

// Sequence manager
t_seq	init_seq(void);
t_seq	opt_seq(t_seq seq);
void	apply_seq(t_stack **stack_a, t_stack **stack_b, t_seq best_move);

// Radix
void	radix_sort(t_stack **a, t_stack **b);

#endif
