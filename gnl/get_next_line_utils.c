/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:36:23 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/05 17:36:26 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief This file contains utility functions that will be used by the main 
 * get_next_line function to handle common string manipulations.
 */

size_t	gnl_strlen(char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*gnl_strdup(char *s)
{
	char	*dup;
	size_t	size;
	size_t	i;

	if (s == NULL)
		return (NULL);
	size = gnl_strlen(s);
	dup = (char *)malloc(size * sizeof(char) + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < size + 1)
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}

char	*gnl_substr(char *s, size_t ini, size_t end)
{
	char	*sub;
	size_t	size;
	size_t	i;

	if (s == NULL)
		return (NULL);
	size = gnl_strlen(s);
	if (ini >= size)
		return (NULL);
	if (end >= size)
		end = size - 1;
	sub = (char *)malloc((end - ini + 1) * sizeof(char) + 1);
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i + ini <= end)
	{
		sub[i] = s[ini + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	s1_size;
	size_t	s2_size;
	size_t	i;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (gnl_strdup(s2));
	if (s2 == NULL)
		return (gnl_strdup(s1));
	s1_size = gnl_strlen(s1);
	s2_size = gnl_strlen(s2);
	str = (char *)malloc((s1_size + s2_size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (++i < s1_size)
		str[i] = s1[i];
	i = -1;
	while (++i < s2_size)
		str[s1_size + i] = s2[i];
	str[s1_size + s2_size] = '\0';
	return (str);
}
