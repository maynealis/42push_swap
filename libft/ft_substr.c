/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:48:25 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/04 17:09:33 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Allocates and returns a substring from the string `s`.
*
* @param s The string from which to create the substring.
* @param start The start index of the substring in the string `s`.
* @param len The maximum length of the substring.
*
* @return The substring, or NULL if the allocation fails.
*
* @note 
* - If `s` is NULL, nothing is done.
*
* - If the index `start` is out of the string `s`, the result substring is an 
* empty string. 
*
* @warning The memory allocated by `ft_substr` should be freed by the user     
* once it is no longer needed. To free the allocated memory, use the `free()`  
* function.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	size_s;

	if (s == NULL)
		return (NULL);
	size_s = ft_strlen(s);
	if (start >= size_s)
		len = 0;
	else if (start + len > size_s)
		len = size_s - start;
	result = (char *)malloc(len + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
