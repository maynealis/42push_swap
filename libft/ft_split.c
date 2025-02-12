/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:05:30 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/04 17:54:35 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Frees a dynamically allocated array of strings.
*
* Iterates through the array `arr` and frees each string up to the `n` index.
* Then frees the array itself. This is used to handle cleanup in case of an
* error during allocation.
*
* @param arr A pointer to an array of strings.
* @param n The number of strings in the array to free.
*
* @return always NULL to indicate that the memory has been freed.
*/
static char	**ft_free(char **arr, size_t n)
{
	while (n > 0)
		free(arr[--n]);
	free(arr);
	return (NULL);
}

/**
* @brief Counts the number of words in a string, separated by a given delimiter.
*
* A word is defined as a sequence of characters that are not the delimiter `c`.
* Words are separated by one or more occurrences of `c`.
* 
* @param a The input string.
* @param c The character used to delimiter words.
*
* @return The number of words in the string.
*/
static size_t	ft_count_words(char const *s, char c)
{
	size_t	size;
	size_t	i;
	size_t	words;

	size = ft_strlen(s);
	words = 0;
	if (s[0] != c && s[0] != '\0')
		words++;
	i = 1;
	while (i < size)
	{
		if (s[i] != c && s[i - 1] == c)
			words++;
		i++;
	}
	return (words);
}

/**
 * @brief Finds the end position of the next word in the string.
 *
 * Starts at the position `*start`, skips any occurrences of the delimiter `c`,
 * and then finds the end of the next word (a sequence of characters not equal
 * to `c`). Updates `*start` to point to the beginning of the word.
 *
 * @param s The input string.
 * @param c The delimiter character used to separate words.
 * @param start A pointer to the current position on the string.
 *
 * @return The index of the last character of the word.
 */
static size_t	ft_find_end_next_word(char const *s, char c, size_t *start)
{
	size_t	end;

	while (s[*start] == c)
		(*start)++;
	end = *start;
	while (s[end] != c && s[end] != '\0')
		end++;
	return (end);
}

/**
 * @brief Divides a string into an array of words using a given delimiter.
 *
 * @param s The input string to split.
 * @param c The delimiter character used to separate words.
 *
 * @return A pointer to an array of strings, where each string is a word. 
 * NULL if memory allocation fails or if the input string `s` is NULL.
 *
 * @note
 * - The last element of the returned array is set to NULL to mark the end.
 */
char	**ft_split(char const *s, char c)
{
	size_t	words;
	size_t	i;
	size_t	j;
	size_t	n;
	char	**result;

	if (s == NULL)
		return (NULL);
	words = ft_count_words(s, c);
	result = (char **)malloc((words + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	n = 0;
	j = 0;
	while (n < words)
	{
		i = j;
		j = ft_find_end_next_word(s, c, &i);
		result[n] = ft_substr(s, i, j - i);
		if (result[n] == NULL)
			return (ft_free(result, n));
		n++;
	}
	result[n] = (void *)0;
	return (result);
}
