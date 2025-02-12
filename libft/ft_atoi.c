/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:29:05 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/21 15:21:12 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts the initial portion of the string `s` pointed to by `nptr` 
 * to an int number.
 * 
 * It ignores any leading whitespaces characters, and converts the rest of the
 * string into an integer value. The function interprets one optional sign 
 * (`+` or `-`) to determine whether the number is positive or negative. 
 * If no sign is provided, the number is assumed to be positive.
 * The conversion stops when a non-digit character is found.
 * 
 * In case of an error, 0 is returned, so it is not possible to differentiate 
 * between a valid conversion to 0 and an error.
 * 
 * Notes on the code: This line: `sign += -2 * (nptr[i] == '-')` makes the sign
 * remains to 1 if the sign is `+`, and converts it to -1 if the sign is `-`.
 * 
 * @param nptr A pointer to the null-terminated string to be converted.
 * @return The converted integer value, or 0 if the conversion can not be made.
 * 
 * @note This function relies on ft_strlen, ft_isspace and ft_isdigit.
 */
int	ft_atoi(const char *nptr)
{
	size_t	size;
	size_t	i;
	char	sign;
	int		result;

	result = 0;
	size = ft_strlen(nptr);
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		sign += -2 * (nptr[i] == '-');
		i++;
	}
	while (ft_isdigit(nptr[i]) && i < size)
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
