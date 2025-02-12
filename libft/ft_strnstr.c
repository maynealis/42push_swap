/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:03:29 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/27 11:59:41 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the first occurrence of the substring `little` within the 
 * string `big`, searching at most `len` characters.
 * 
 * @param big The larger string to be searched.
 * @param little The substring to look for.
 * @param len The maximum number of characters to search.  If `len` is greater 
 * 			  than the length of `big`, the search is limited to the length of 
 * 			  `big`.
 * 
 * @return char* A pointer to the beginning of the located substring within 
 * 				`big`, or NULL if `little` is not found in the first `len` 
 * 				characters of `big`.
 * 
 * @note If `little` is an empty string, the function returns `big`.
 *       If `big` is NULL or does not contain `little` within the specified 
 * 		 range, the function returns NULL.
 * 		 This function depends on ft_strncmp and ft_strlen.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	size_lit;
	size_t	size_big;

	size_lit = ft_strlen(little);
	if (size_lit == 0)
		return ((char *)big);
	size_big = ft_strlen(big);
	if (len > size_big)
		len = size_big;
	i = 0;
	while (i + size_lit <= len)
	{
		if (big[i] == little[0] && ft_strncmp(big + i, little, size_lit) == 0)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
