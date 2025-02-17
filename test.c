/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:02:49 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/02/17 17:04:09 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "stack.h"

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
