/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:29:55 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/27 13:10:16 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*	@brief Checks if a character is an alphabetic character.
*	
*	This function checks if the character is alphabetic by verifying if it is 
*	either an uppercase letter (`A` to `Z`) or a lowercase letter (`a` to `z`).
*
*	@param c The character to check. Must have the value of an unsigned char 
*			 or EOF.
*	@return 1 if the character is alphabetic; 0 otherwise.
*	@note This function relies on `ft_isupper` and `ft_islower`.
*/
int	ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c));
}
