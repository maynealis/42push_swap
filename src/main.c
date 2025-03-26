/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:42:53 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/02/17 19:58:15 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	fill_stack(argc, argv, &stack_a, &stack_b);
	if (ft_stacksize(stack_a) <= 3)
		sort_three(&stack_a, 'a');
	else if (ALGORITHM == RADIX)
		radix_sort(&stack_a, &stack_b);
	else if (ALGORITHM == TURK)
		turk_algorithm(&stack_a, &stack_b);
	ft_stackfree(&stack_a);
	ft_stackfree(&stack_b);
	exit(EXIT_SUCCESS);
}
