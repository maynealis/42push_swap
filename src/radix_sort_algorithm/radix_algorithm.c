/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:33:42 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/02/16 15:52:02 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	radix(t_stack **a, t_stack **b, int d)
{
	int	size_a;
	int	i;

	size_a = ft_stacksize(*a);
	i = 0;
	while (i < size_a)
	{
		if (((((*a)->index) >> d) & 1) == 0)
			push_print(a, b, 'b');
		else if (((((*a)->index) >> d) & 1) == 1)
			rotate_print(a, 'a');
		i++;
	}
	while (*b)
		push_print(b, a, 'a');
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	d;
	int	max;
	int	d_max;

	d = 0;
	max = get_max_index(*a);
	d_max = ft_numlen(max, "01");
	while (d < d_max)
	{
		radix(a, b, d);
		d++;
	}
}
