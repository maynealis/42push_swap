/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:03:37 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/05 12:49:18 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Copies n bytes from memory area src to memory area dest.
 * 
 * The memory areas may overlap.
 *
 * If n is 0, the function does nothing and simply returns `dest`.
 * 
 * @param dest The pointer to the destination memory are.
 * @param src The pointer to the source memory area.
 * @param n The number of bytes to copy.
 * @return The pointer to the memory area dest.
 * 
 * @note Edge cases:
 * - **n > size of src**: If `n`is bigger than the size of the allocated memory
 * 	for source, the behaviour of the function is unpredicted.
 * - If either or both operators are NULL, the behaviour is undefined. 
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*c_dest;
	unsigned char	*c_src;

	c_dest = (unsigned char *)dest;
	c_src = (unsigned char *)src;
	if (dest <= src)
	{
		i = -1;
		while (++i < n)
			c_dest[i] = c_src[i];
	}
	else
	{
		i = n;
		while (i-- > 0)
			c_dest[i] = c_src[i];
	}
	return (dest);
}
