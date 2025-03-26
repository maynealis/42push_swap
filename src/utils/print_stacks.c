/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:02:49 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/03/26 13:05:38 by cmayne-p         ###   ########.fr       */
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
	ft_printf("------ a ------\t------ b ------\n");
	i = 0;
	while (i < size_a || i < size_b)
	{
		if (i < size_a)
		{
			ft_printf("(%i)% 11i",a->index, a->num);
			a = a->next;
		}
		else
			ft_printf("           ");
		ft_printf("\t");
		if (i < size_b)
		{
			ft_printf("(%i)% 11i", b->index, b->num);
			b = b->next;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("--------------------------------\n");
}
