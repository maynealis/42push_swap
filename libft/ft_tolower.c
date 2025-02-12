/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:45:26 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/27 16:08:53 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*	@brief Converts uppercase letters to lowercase.
*
*	@param c The character to convert. Must be an unsigned char value or EOF.
*	@return The lowercase equivalent of c if it exists, or c if it doesn't.
*	
*	@note This function relies on `ft_isupper`.
*/
int	ft_tolower(int c)
{
	if (ft_isupper(c))
		return (c - ('A' - 'a'));
	return (c);
}
