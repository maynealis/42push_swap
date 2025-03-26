/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:40:02 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/03/26 12:40:06 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"
#include "libft.h"

static void	create_index(t_stack *stack)
{
	t_stack	*start;
	t_stack	*current;
	t_stack	*aux;
	int		count_lower;

	start = stack;
	current = stack;
	while (1)
	{
		count_lower = 0;
		aux = start;
		while (1)
		{
			if (aux->num < current->num)
				count_lower++;
			aux = aux->next;
			if (aux == start)
				break ;
		}
		current->index = count_lower;
		current = current->next;
		if (current == start)
			break ;
	}
}

static char	add_number(t_stack **a, int n)
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

void	print_error_message_and_clean(t_stack **stack_a, t_stack **stack_b)
{
	ft_putendl_fd("Error", 2);
	ft_stackfree(stack_a);
	ft_stackfree(stack_b);
	exit(EXIT_FAILURE);
}

void	fill_stack(int argc, char **args, t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_argument(args[i], *stack_a))
			print_error_message_and_clean(stack_a, stack_b);
		if (!add_number(stack_a, ft_atoi(args[i])))
			print_error_message_and_clean(stack_a, stack_b);
		i++;
	}
	create_index(*stack_a);
}
