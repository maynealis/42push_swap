/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:25:46 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/10 14:49:08 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*cleanup_memory(char **left, char *buffer, char *line_read, char *line)
{
	if (*left)
	{
		free(*left);
		*left = NULL;
	}
	if (buffer)
		free(buffer);
	if (line_read)
		free(line_read);
	if (line)
		free(line);
	return (NULL);
}

size_t	index_endline(char *s)
{
	size_t	i;
	size_t	size;

	size = ft_strlen(s);
	i = 0;
	while (i < size)
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*get_line(int fd, char *buffer, char *left)
{
	char	*temp;
	char	*line;
	int		bytes_read;

	temp = ft_strdup(left);
	while ((temp != NULL && index_endline(temp) == ft_strlen(temp)) || !temp)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(temp);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		line = ft_strjoin(temp, buffer);
		free(temp);
		temp = ft_strdup(line);
		free(line);
	}
	if (!temp)
		return (NULL);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*left[FT_MAX_OPEN_FILES];
	char		*buffer;
	char		*line_read;
	char		*line;
	size_t		end_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (cleanup_memory(&left[fd], NULL, NULL, NULL));
	line_read = get_line(fd, buffer, left[fd]);
	if (line_read == NULL)
		return (cleanup_memory(&left[fd], buffer, NULL, NULL));
	end_line = index_endline(line_read);
	line = ft_substr(line_read, 0, end_line);
	if (line == NULL)
		return (cleanup_memory(&left[fd], buffer, line_read, NULL));
	free(left[fd]);
	left[fd] = ft_substr(line_read, end_line + 1, ft_strlen(line_read));
	free(line_read);
	free(buffer);
	return (line);
}
