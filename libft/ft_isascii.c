/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:47:10 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/27 13:26:22 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
*	@brief Checks if a character is a 7-bit unsigned char value that fits into
*	the ASCII character set.
*	
*	@param c The character to check. Must have the value of an unsigned char 
*			 or EOF.
*	@return 1 if true; 0 if false.
*/
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
