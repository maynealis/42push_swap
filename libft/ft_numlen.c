/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:05:05 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/27 19:08:55 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** 
*	@brief Calculates the number of digits of an unsigned long `n` in a
*	particular `base`.
*	
*	@param n The number to check.
*	@param base The base in string format (e.g. "0123456789").
*	@return The number of digits of `n` in the `base`.
*/
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
