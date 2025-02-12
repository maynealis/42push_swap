/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:22:24 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/19 15:33:58 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies up to `size - 1` characters from the string `src` to `dst`,
 *        ensuring the result is null-terminated if `size` is not zero.
 * 
 * @param dst A pointer to the destination string.
 * @param src A pointer to the source string to be copied.
 * @param size The total size of the destination buffer, including space for 
 * 			   the null terminator.
 * 
 * @return size_t The total size of the destination buffer that was intended to
 * 				  be created, the size of the src. This allows the caller to 
 * 				  determine if truncation occurred by comparing the return
 *         		  value to `size`.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_size;

	src_size = ft_strlen(src);
	if (size == 0)
		return (src_size);
	i = 0;
	while (i < size - 1 && i < src_size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_size);
}
