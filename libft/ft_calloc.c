/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:36:42 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/05 16:16:14 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates enough space for `nmemb` elements that are `size` bytes of 
 * memory each. The allocated memory is filled with bytes of value zero.
 * 
 * @param nmemb The number of elements to allocate memory for.
 * @param size The size in bytes of each element.
 * @return A pointer to the allocated memory. If there is an error, it 
 * returns a NULL pointer.
 * 
 * @note 
 *	- If either `nmemb` or `size` is zero, the function will return a unique 
 *   pointer to a block of memory of size `1` byte.
 * 
 *	- If the total memory requested exceeds the maximum allowable size 
 *   (`FT_INT_MAX`), the function will return `NULL` to indicate an error.
 * 
 *	- The `ft_bzero` function is used to fill the allocated memory block with 
 *   zeros.
 * 
 * @warning The memory allocated by `ft_calloc` should be freed by the user 
 * once it is no longer needed. To free the allocated memory, use the `free()` 
 * function.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	if (nmemb == 0 || size == 0)
		return ((void *)malloc(1));
	if (size != 0 && nmemb > FT_INT_MAX / size)
		return (NULL);
	result = malloc(nmemb * size);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, nmemb * size);
	return (result);
}
