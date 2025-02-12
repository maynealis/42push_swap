/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:25:46 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/04 18:29:06 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Allocates and returns a new string, which is the result of the
* concatenation of `s1` and `s2`.
*
* @param s1 The prefix string.
* @param s2 The suffix string.
*
* @return The new string, or NULL if the allocation fails or both original
* strings are NULL.
*
* @note After allocating enough space for the new string, the memory is set to
* zeros using ft_bzero and then concatenates both strings using ft_strlcat,
* leaving 1 space for the null terminator. If one of them is NULL, the this
* function returns a copy of the other string using ft_strdup.
* 
* @warning The memory allocated by `ft_strjoin` should be freed by the user      
* once it is no longer needed. To free the allocated memory, use the `free()`   
* function.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	s1_size;
	size_t	s2_size;

	if (!s1 && !s2)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	result = (char *)malloc(s1_size + s2_size + 1);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, s1_size + s2_size + 1);
	ft_strlcat(result, s1, s1_size + 1);
	ft_strlcat(result, s2, s1_size + s2_size + 1);
	return (result);
}
