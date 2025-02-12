/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:39:26 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/04 18:08:57 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	ft_intlen(int n)
{
	if (ft_abs(n) < 10)
		return (1);
	return (1 + ft_intlen(n / 10));
}

static int	ft_pow10(int exp)
{
	int	i;
	int	result;

	i = -1;
	result = 1;
	while (++i < exp)
		result *= 10;
	return (result);
}

/**
* @brief Allocates and returns a string representing the integer received as an
* argument.
*
* @param n The integer to convert.
*
* @return The string representing the integer, or NULL if the allocation fails.
*
* @warning The memory allocated should be freed by the user once it is no longer
* needed. To free the memory, use the `free()` function. 
*/
char	*ft_itoa(int n)
{
	char	*result;
	int		is_neg;
	int		len;
	int		i;

	len = ft_intlen(n);
	is_neg = 0;
	if (n == (int)FT_INT_MIN)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		is_neg = 1;
	result = (char *)malloc((len + is_neg + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len + is_neg)
	{
		if (i == 0 && is_neg)
			result[0] = '-';
		else
			result[i] = (ft_abs(n) / ft_pow10(len + is_neg - 1 - i)) % 10 + '0';
		i++;
	}
	result[i] = '\0';
	return (result);
}
