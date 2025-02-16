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

#include "stack.h"
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
		if (((((*a)->num) >> d) & 1) == 0) //TODO opt
			push_print(a, b, 'b');
		else if (((((*a)->num) >> d) & 1) == 1) //&& are_more_one_in_digit((*a)->next, d))
			rotate_print(a, 'a');
	//	else
	//		ft_printf("");
		i++;
	}
	while (*b)
		push_print(b, a, 'a');
}

int	ft_numlen(unsigned long n, char *base)
{
	size_t	len_base;
	int		len;

	if (n == 0)
		return (1);
	len_base = ft_strlen(base);
	len = 0;
	while (n != 0)
	{
		n /= len_base;
		len++;
	}
	return (len);
}
#include <stdio.h>
void	radix_sort(t_stack **a, t_stack **b)
{
	int	d = 0;
	int	max = get_max_num(*a);
	int	d_max = ft_numlen(max, "01");
	printf("d_max is %i and number max is %i\n", d_max, max);
	while (d < d_max)
	{
		radix(a, b, d);
		d++;
	}
}

