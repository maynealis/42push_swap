/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:50:11 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/02/12 11:24:04 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

static char	is_int_in_range(char *arg)
{
	size_t	len;

	len = ft_strlen(arg);
	if (ft_isdigit(arg[0]) && len >= 10)
	{
		if (len > 10 || ft_strncmp(arg, "2147483647", len) > 0)
			return (0);
	}
	else if (arg[0] == '-' && len >= 11)
	{
		if (len > 11 || ft_strncmp(arg, "-2147483648", len) > 0)
			return (0);
	}
	else if (arg[0] == '+' && len >= 11)
	{
		if (len > 11 || ft_strncmp(arg, "+2147483647", len) > 0)
			return (0);
	}
	return (1);
}

static char	is_valid_integer(char *arg)
{
	size_t	len;
	size_t	i;

	if (!ft_isdigit(arg[0]) && arg[0] != '-' && arg[0] != '+')
		return (0);
	i = 1;
	len = ft_strlen(arg);
	while (i < len)
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (is_int_in_range(arg));
}

static char	is_not_duplicate(t_stack *a, int n)
{
	int	size;
	int	i;

	size = ft_stacksize(a);
	i = 0;
	while (i < size)
	{
		if (n == a->num)
			return (0);
		a = a->next;
		i++;
	}
	return (1);
}

char	is_valid_argument(char *arg, t_stack *a)
{
	char	is_valid;

	is_valid = is_valid_integer(arg);
	if (is_valid)
		is_valid = is_not_duplicate(a, ft_atoi(arg));
	return (is_valid);
}
