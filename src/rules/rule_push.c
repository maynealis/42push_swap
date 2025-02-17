/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:44:23 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/02/14 17:18:16 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_printf_bonus.h"

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*node;

	if (!src || !dst || !*src)
		return ;
	node = ft_stackremove_front(src);
	ft_stackadd_front(dst, node);
}

void	push_print(t_stack **src, t_stack **dst, char letter)
{
	push(src, dst);
	ft_printf("p%c\n", letter);
}

void	push_n_print(int n, t_stack **src, t_stack **dst, char letter)
{
	int	i;

	i = 0;
	while (i < n)
	{
		push_print(src, dst, letter);
		i++;
	}
}
