/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:24:28 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/05 12:01:13 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compares at most `n` bytes of the string `s1` and `s2`.
 * 
 * This function compares the strings `s1` and `s2` byte by byte up to a 
 * maximum of `n` bytes or until a null-terminator (`\0`) is encountered in 
 * either string.
 * The result is determined by the difference between the first pair of 
 * differing bytes, interpreted as `unsigned char` values.
 * 
 * Casting to `unsigned char` ensures that all characters, including extended 
 * ASCII (greater than 127) are treated as non-negative values, following the 
 * behavior specified by the C standard.
 * 
 * @param s1 A pointer to the first string to compare
 * @param s2 A pointer to the second string to compare
 * @param n The maximum number of bytes to compare
 * 
 * @return An integer less than, equal to, or greater than zero if the first 
 * `n` bytes of `s1` are found, respectively, to be less than, to match, or to 
 * be greater than the first `n` bytes of `s2`.
 * - If the strings are equal up to `n` bytes or until a null-terminator, the 
 *   function returns `0`.
 * - If a difference is found, the function returns the difference between the 
 *   first pair of different bytes.
 *
 * @note If either string is NULL, the behaviour is undefined.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0' || s2[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
