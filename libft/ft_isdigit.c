/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:41:55 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/27 13:18:10 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
*	@brief Checks if the character is a digit (`0` to `9`).
*	
*	@param c The character to check. Must have the value of an unsigned char 
*			 or EOF.
*	@return 1 if the character is a digit; 0 otherwise.
*/
int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}
