/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:43:08 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/05 11:24:46 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*	@brief Checks for an alphanumeric character.
*	
*	This function checks if the character is alphanumeric by verifying if it is 
*	either an alphabetic character using `ft_isalpha`, or a digit using 
*	`ft_isdigit`.
*
*	@param c The character to check. Must have the value of an unsigned char 
*			 or EOF.
*	@return 1 if the character is alphanumeric; 0 otherwise.
*	@note This function relies on `ft_isalpha` and `ft_isdigit`.
*/
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
