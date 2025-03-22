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

// //TODO to test
// #include <stdio.h>
// void	print_stacks(t_stack *a, t_stack *b)
// {
// 	int	size_a;
// 	int	size_b;
// 	int	i;

// 	size_a = ft_stacksize(a);
// 	size_b = ft_stacksize(b);
// 	printf("------ a ------\t------ b ------\n");
// 	i = 0;
// 	while (i < size_a || i < size_b)
// 	{
// 		if (i < size_a)
// 		{
// 			//print_binary(a->number, 7);
// 			printf("(%i)% 11i",a->index, a->num);
// 			a = a->next;
// 		}
// 		else
// 			printf("           "); //TODO
// 		printf("\t");
// 		if (i < size_b)
// 		{
// 			//print_binary(a->number, 7);
// 			printf("(%i)% 11i", b->index, b->num);
// 			b = b->next;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// 	printf("--------------------------------\n");
// }

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
