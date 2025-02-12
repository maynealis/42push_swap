/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:13:43 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/27 16:07:59 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*	@brief Converts lowercase letters to uppercase.
*
*	@param c The character to convert. Must be an unsigned char value or EOF.
*	@return The uppercase equivalent of c if it exists, or c if it doesn't.
*	
*	@note This function relies on `ft_islower`.
*/
int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - ('a' - 'A'));
	return (c);
}
