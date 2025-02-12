/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:47:17 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/27 13:27:44 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
*	@brief Checks for any printable character including space.
*	
*	@param c The character to check. Must have the value of an unsigned char 
*			 or EOF.
*	@return 1 if the character is printable; 0 otherwise.
*/
int	ft_isprint(int c)
{
	return (c >= ' ' && c <= '~');
}
