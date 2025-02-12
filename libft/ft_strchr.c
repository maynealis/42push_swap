/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:54:36 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/05 11:58:19 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Returns a pointer to the first occurrence of the character c in the 
 * string s.
 * 
 * In case the character is not found, it returns a NULL. The terminating null
 * byte is considered part of the string, so that if c is specified as '\0'
 * the return value is a pointer to the terminator.
 * 
 * @param s The string to be searched
 * @param c The character to be found
 * @return A pointer to the first occurence of the character c in the string
 * or NUll if the character is not found.
 *
 * @note If string `s` is NULL, the behaviour is undefined.
 */
char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	size;
	char	*str;

	str = (char *)s;
	size = ft_strlen(s);
	i = 0;
	while (i <= size)
	{
		if (s[i] == (unsigned char)c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
