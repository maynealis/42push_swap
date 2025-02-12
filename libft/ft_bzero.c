/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:56:08 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/27 15:33:25 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*	@brief Erases the data in a block of memory.
*
*	This function erases the data in the n bytes of the memory starting at 
*	the location pointed to by s, by writing zeros (byts containing `\0`) to 
*	that area.
*	
*	If n is 0, the function does nothing.
*
*	@param s The pointer to the memory area to be erased. 
*	@param n The number of bytes to erase.
*	
*	@note Limitations and edge cases:
*	- **NULL pointer**: If `s` is NULL, the behavior is undefined. 
*		It is the caller's responsibility to ensure `s` is a valid pointer.
*	- **Buffer size**: If `n` exceeds the size of the allocated buffer for `s`, 
*		the function may cause a buffer overflow, resulting in undefined 
*		behavior. 
*/
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}
