/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:36:22 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/27 13:15:20 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
*	@brief Checks if a character is a lowercase letter (`a` to `z`).
*
*	@param c The character to check. Must have the value of an unsigned char 
*			 or EOF.
*	@return 1 if the character is a lowercase letter; 0 otherwise.
*/
int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}
