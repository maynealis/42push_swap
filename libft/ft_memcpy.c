/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:01:15 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/05 12:47:07 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*	@brief Copies n bytes from memory area src to memory area dest.
*	
*	The memory areas must not overlap. If they do, use ft_memmove instead.
*	
*	The cast to `unsigned char *` ensures that we can use the pointer 
*	arithmetic (`c_dest[i] = c_src[i]`) to copy the memory in increments of 
*	one byte at a time.
*	
*	@param dest The pointer to the destination memory area where the content
*				will be copied. 
*	@param src The pointer to the source memory area from where the content
*				will be copied. 
*	@param n The number of bytes to copy.
*	
*	@return The pointer to the memory area dest.
*
*	@note Limitations and edge cases:
*	- **NULL pointer**: If `s` is NULL, the behavior is undefined. 
*		It is the caller's responsibility to ensure `s` is a valid pointer.
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*c_dest;
	unsigned char	*c_src;

	c_dest = (unsigned char *)dest;
	c_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		c_dest[i] = c_src[i];
		i++;
	}
	return (dest);
}
