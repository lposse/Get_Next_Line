/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:17:40 by lposse            #+#    #+#             */
/*   Updated: 2025/03/07 20:40:30 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next_line(char **remainder)
{
	int		i;
	char	*line;
	char	*old_remainder;

	if (!*remainder)
		return (NULL);
	i = 0;
	while ((*remainder)[i] != '\n' && (*remainder)[i] != '\0')
		i++;
	if ((*remainder)[i] == '\n')
		i++;
	line = ft_substr(*remainder, 0, i);
	old_remainder = *remainder;
	if (i < (int)ft_strlen(*remainder))
		*remainder = ft_strdup(*remainder + i);
	else
		*remainder = NULL;
	free(old_remainder);
	return (line);
}

ssize_t	read_file(int fd, char **buffer, char **remainder)
{
	int		bytes;
	char	*old_remainder;

	if (!*remainder)
		*remainder = ft_strdup("");
	bytes = read(fd, *buffer, BUFFER_SIZE);
	if (bytes <= 0)
		return (bytes);
	if (!ft_strchr(*remainder, '\n'))
	{
		(*remainder)[bytes] = '\0';
		old_remainder = *remainder;
		*remainder = ft_strjoin(*remainder, *buffer);
		free(old_remainder);
	}
	return (bytes);
}

void	free_ptr(char	**ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

char	*ft_line(int fd, char **buffer, char **remainder)
{
	ssize_t	bytes_read;
	char	*last_line;

	bytes_read = read_file(fd, buffer, remainder);
	if (!**remainder || bytes_read < 0)
	{
		free_ptr(remainder);
		return (NULL);
	}
	if (ft_strchr(*remainder, '\n'))
		return (ft_next_line(remainder));
	last_line = ft_strdup(*remainder);
	free_ptr(remainder);
	return (last_line);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!remainder)
		remainder = ft_strdup("");
	line = ft_line(fd, &buffer, &remainder);
	free(buffer);
	return (line);
}
