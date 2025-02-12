/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:13:30 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/27 19:41:16 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Allocates and returns a string representing the unsigned long 
* received as an argument in a particular base.
*
* @param n The unsigned long to convert.
* @param base The base in to which to convert the number.
*
* @return The string representing the unsigned long, 
* or NULL if the allocation fails.
*
* @warning The memory allocated should be freed by the user once it is no longer
* needed. To free the memory, use the `free()` function.
* @note This function relies on `ft_numlen` to calculate the number of digits
* in the particular base.
*/
char	*ft_ultoa_base(unsigned long n, char *base)
{
	char	*result;
	size_t	len_base;
	int		len_n;

	len_base = ft_strlen(base);
	len_n = ft_numlen(n, base);
	result = (char *)malloc((len_n + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[len_n] = '\0';
	if (n == 0)
		result[0] = base[0];
	while (n > 0)
	{
		result[--len_n] = base[n % len_base];
		n /= len_base;
	}
	return (result);
}
