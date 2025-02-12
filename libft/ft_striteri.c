/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:15:58 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/04 18:14:02 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Applies the function `f` to each character of the string `s`.
*
* @param s The string on which to iterate.
* @param f The function to apply to each character.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	size;
	size_t	i;

	size = ft_strlen(s);
	i = 0;
	while (i < size)
	{
		f(i, &s[i]);
		i++;
	}
}
