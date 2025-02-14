/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:12:20 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/02/14 17:26:34 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

char	add_number(t_stack **a, int n)
{
	t_stack	*new;

	new = ft_stacknew(n);
	if (new == NULL)
	{
		ft_stackfree(a);
		return (0);
	}
	ft_stackadd_back(a, new);
	return (1);
}

char	print_error_message_and_clean(t_stack **stack_a, t_stack **stack_b)
{
	ft_putendl_fd("Error", 2);
	ft_stackfree(stack_a);
	ft_stackfree(stack_b);
	return (1);
}

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

void	sort_three(t_stack **stack, char letter)
{
	sort_three_asc(stack, letter);
	get_min_on_top(stack, letter);
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (!is_valid_argument(argv[i], stack_a))
			return (print_error_message_and_clean(&stack_a, &stack_b));
		if (!add_number(&stack_a, ft_atoi(argv[i])))
			return (print_error_message_and_clean(&stack_a, &stack_b));
		i++;
	}
	if (ft_stacksize(stack_a) <= 3)
		sort_three(&stack_a, 'a');
	else
		turk_algorithm(&stack_a, &stack_b);
	ft_stackfree(&stack_a);
	ft_stackfree(&stack_b);
	return (0);
}
