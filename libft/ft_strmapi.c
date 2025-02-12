/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:32:03 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/04 18:12:45 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Applies the function `f` to each character of the string `s`. A new
* string is created to collect the results from the successive applications of
* `f`.
*
* @param s The string on which to iterate.
* @param f The function to apply to each character.
*
* @return The string created from the application of `f`, or NULL if the
* allocation fails.
*
* @warning The memory allocated should be freed by the user once it is no longer
* needed. To free the memory, use the `free()` function. 
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	size;
	size_t	i;

	size = ft_strlen(s);
	result = (char *)malloc((size + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
