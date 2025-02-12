/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:47:44 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/05 12:04:27 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Comapres the first `n` bytes of the memory areas `s1` and `s2`.
 * 
 * This function compares the memory areas byte by byte, treating the memory 
 * as sequences of unsigned char.
 * If n is 0, the return value is 0. No bytes are compared.
 * 
 * @param s1 The first memory area to be compared.
 * @param s2 The second memory area to be compared.
 * @param n The number of bytes to be compared.
 * 
 * @return An integer less than, equal to, or greater than zero if the first n 
 * bytes of s1 is found, respectively, to be less than, to match, or be greater 
 * than the first n bytes of s2. Specifically:
 * - A negative value if the first difference byte in `s1` is less than that 
 * in `s2`.
 * - Zero if the first `n` bytes of `s1` and `s2` are equal.
 * - A positive value if the first differing byte in `s1` is greater than that 
 * in `s2`.
 *
 * @note If either string is NULL, the behaviour is undefined. 
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
