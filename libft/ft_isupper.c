/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:35:26 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/27 13:15:23 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
*	@brief Checks if a character is an uppercase letter (`A` to `Z`).
*
*	@param c The character to check. Must have the value of an unsigned char 
*			 or EOF.
*	@return 1 if the character is an uppercase letter; 0 otherwise.
*/
int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}
