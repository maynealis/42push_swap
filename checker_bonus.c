/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:12:53 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/02/17 14:34:20 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "stack.h"
#include "ft_printf_bonus.h"
#include "get_next_line.h"
#include "checker.h"

void	apply_instruction(char *inst, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(inst, "sa\n", 3) == 0)
		swap(stack_a);
	else if (ft_strncmp(inst, "sb\n", 3) == 0)
		swap(stack_b);
	else if (ft_strncmp(inst, "ss\n", 3) == 0)
		swap_both(stack_a, stack_b);
	else if (ft_strncmp(inst, "pa\n", 3) == 0)
		push(stack_b, stack_a);
	else if (ft_strncmp(inst, "pb\n", 3) == 0)
		push(stack_a, stack_b);
	else if (ft_strncmp(inst, "ra\n", 3) == 0)
		rotate(stack_a);
	else if (ft_strncmp(inst, "rb\n", 3) == 0)
		rotate(stack_b);
	else if (ft_strncmp(inst, "rr\n", 3) == 0)
		rotate_both(stack_a, stack_b);
	else if (ft_strncmp(inst, "rra\n", 4) == 0)
		reverse_rotate(stack_a);
	else if (ft_strncmp(inst, "rrb\n", 4) == 0)
		reverse_rotate(stack_b);
	else if (ft_strncmp(inst, "rrr\n", 4) == 0)
		reverse_rotate_both(stack_a, stack_b);
}

void	checker(t_stack **stack_a, t_stack **stack_b)
{
	char *inst;

	inst = get_next_line(0);
	while (inst)
	{
		if (ft_strnstr(INSTRUCTIONS, inst, ft_strlen(INSTRUCTIONS)) == NULL)
		{
			free(inst);
			print_error_message_and_clean(stack_a, stack_b);
			return ;
		}
		apply_instruction(inst, stack_a, stack_b);
		free(inst);
		inst = get_next_line(0);
	}
	if (is_strictly_sorted(*stack_a) && (*stack_b) == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	int	i;
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
	checker(&stack_a, &stack_b);
	ft_stackfree(&stack_a);
	ft_stackfree(&stack_b);
	return (0);
}
