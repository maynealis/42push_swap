/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:49:46 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/05 11:30:23 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*	@brief Calculates the length of the string `s`.
*	
*	This function returns the size of a null-terminated string excluding the
*	terminating null byte (`\0`).
*
*	@param s The string to check.
*	@return The number of bytes in the string pointed by s.
*
*	@note Limitations and edge cases:
*	- **Passing a NULL pointer**: If a NULL pointer is passed to this function,
*		it will result in undefined behavior, typically leading to a 
*		segmentation fault.
*	- **Strings not null-terminated**: If the string is not null-terminated, 
*		the function will read beyond the allocated memory, potentially causing 
*		a segmentation fault or returning an unexpected result.
*	- **Strings larger than `size_t`**: This function cannot handle strings 
*		whose length exceeds the maximum value of `size_t`, as the return value
*		is of type `size_t`.
*/
size_t	ft_strlen(const char *s)
{
	unsigned long	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
