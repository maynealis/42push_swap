/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:56:22 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/04 17:25:25 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Allocates and returns a copy of `s1` with the characters specified in 
* `set` removed from the beginning and the end of the string.
*
* @param s1 The string to be trimmed.
* @param set The reference set of characters to trim.
*
* @return The trimmed string or NULL if the allocation fails.
* 
* @warning The memory allocated should be freed by the user once it is no longer
* needed. To free the memory, use the `free()` function.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	ini;
	size_t	end;
	size_t	size;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	size = ft_strlen(s1);
	ini = 0;
	end = 0;
	while (ini < size && ft_strchr(set, s1[ini]) != NULL)
		ini++;
	while (end < size - 1 - ini && ft_strchr(set, s1[size - 1 - end]) != NULL)
		end++;
	result = ft_substr(s1, ini, size - ini - end);
	if (result == NULL)
		return (NULL);
	return (result);
}
