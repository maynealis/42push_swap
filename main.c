/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:42:53 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/02/12 17:08:47 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_bonus.h"
#include "push_swap.h"

char	add_number(t_stack **a, int n)
{
	t_stack	*new;

	new = ft_stacknew(n);
	if (new == NULL)
		//free all stack
		return (0);
	ft_stackadd_back(a, new);
	return (1);
}

//#include <stdio.h> //TODO: change to my printf
void	print_stacks(t_stack *a, t_stack *b)
{
	int	size_a;
	int	size_b;
	int	i;

	size_a = ft_stacksize(a);
	size_b = ft_stacksize(b);
	ft_printf("---- a ----\t---- b ----\n");
	i = 0;
	while (i < size_a || i < size_b)
	{
		if (i < size_a)
		{
			//print_binary(a->number, 7);
			ft_printf("% 11i", a->num);
			a = a->next;
		}
		else
			ft_printf("           "); //TODO
		ft_printf("\t");
		if (i < size_b)
		{
			//print_binary(a->number, 7);
			ft_printf("% 11i", b->num);
			b = b->next;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("--------------------------\n");
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
	int		l;
	int		f;

	push_print(stack_a, stack_b, 'b');
	push_print(stack_a, stack_b, 'b');
	push_print(stack_a, stack_b, 'b');
	sort_three_desc(stack_b, 'b');
	while (ft_stacksize(*stack_a) > 3)
	{
		seq = get_best_move(*stack_a, *stack_b);
		seq = opt_seq(seq);
		//ft_printf("Size of a: %i\t Size of b: %i\n", ft_stacksize(*stack_a), ft_stacksize(*stack_b));
		//ft_printf("Number of moves: %i\n", seq.moves);
		//ft_printf("Number to move: %i\n", seq.number);
		apply_seq(stack_a, stack_b, seq);
		//print_stacks(*stack_a, *stack_b);
		//ft_printf("Number that I moved %i\n", (*stack_b)->num);
	}
	sort_three_asc(stack_a, 'a');
	//get_min_on_top(stack_a, 'a');
	print_stacks(*stack_a, *stack_b);
	while (*stack_b)
	{
		l = (*stack_a)->prev->num;
		f = (*stack_a)->num;
		if ((l < f && (*stack_b)->num < f && (*stack_b)->num > l)
		|| (l > f && ((*stack_b)->num < f || (*stack_b)->num > l)))
			push_print(stack_b, stack_a, 'a');
		else
			reverse_rotate_print(stack_a, 'a');
	}
	get_min_on_top(stack_a, 'a');
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
		if (!add_number(&stack_a, ft_atoi(argv[i]))) //ha fallado el anadir el numero al stack
			return (print_error_message_and_clean(&stack_a, &stack_b));
		i++;
	}
	if (ft_stacksize(stack_a) <= 3)
	{
		sort_three_asc(&stack_a, 'a'); //TODO check for fewer than 3
		get_min_on_top(&stack_a, 'a');
	}
	else if (ft_stacksize(stack_a) < 6)
		sort_three_asc(&stack_a, 'a');//TODO for 5 numb
	else
		turk_algorithm(&stack_a, &stack_b);
	ft_stackfree(&stack_a);
	ft_stackfree(&stack_b);
	return (0);
}
