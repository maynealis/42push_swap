/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:54:43 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/05 11:50:35 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Concatenates the string `src` to the end of the string `dst`, 
 *        ensuring that `dst` is null-terminated, and does not exceed the
 *        total size specified by `size`.
 * 
 * @param dst A pointer to the destination string.
 * @param src A pointer to the source string.
 * @param size The total size of the destination buffer, including space for 
 * 			   the null terminator.
 * 
 * @return size_t The total length of the string that would be created if there 
 * 		   were enough space in `dst`. This is the length of the original `dst` 
 * 		   plus the length of `src`. If `size` is less than or equal to the 
 * 		   length of `dst`, the lenght of `dst` is considered to be `size`.
 * @note If one of the strings is NULL, the behavious is undefined.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_size;

	if (!dst && !src)
		return (0);
	dst_size = ft_strlen(dst);
	if (size <= dst_size)
		return (size + ft_strlen(src));
	i = 0;
	while (i + dst_size < size - 1 && src[i] != '\0')
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	dst[dst_size + i] = '\0';
	return (dst_size + ft_strlen(src));
}
