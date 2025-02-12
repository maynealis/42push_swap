/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:39:57 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/05 12:03:47 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Scans the initial n bytes of the memory area pointed to by s for the 
 * first instance of c.
 * 
 * Both c and the bytes of the memory area pointed to by s are interpreted as 
 * unsigned char.

 * @param s The memory area to be searched
 * @param c Tne byte to be located, interpreted as an ùnsigned char`
 * @param n The number of bytes from `s` to search
 * @return A pointer to the matching byte or NULL if the character does not 
 * occur in the given memory area.
 *
 * @note If string `s` is NULL, the behaviour is undefined.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*src;

	src = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (src[i] == (unsigned char) c)
			return (&src[i]);
		i++;
	}
	return (NULL);
}
