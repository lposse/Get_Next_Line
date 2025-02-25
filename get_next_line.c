/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:17:40 by lposse            #+#    #+#             */
/*   Updated: 2025/02/25 16:41:52 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_line(ssize_t bytes_read, static char *buff)
{
	char	*line;
	size_t	i;

	line = malloc((bytes_read + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while ((size_t)bytes_read >= i)
	{
		if (buff[i] == '\n' || buff[i] == '\0')
		{
			line[i] = buff[i];
			break ;
		}
		else
			line[i] = buff[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char	*line;
	char	*temp;
	ssize_t		bytes_read;
	
	if (!buff)
		buff = malloc(BUFFER_SIZE * sizeof(char));
	if (!buff)
		return (NULL);
	bytes_read = read(fd, buff, BUFFER_SIZE);
	if (bytes_read < 0)
		return (NULL);
	while (bytes_read > 0)
	{
		line = ft_line(bytes_read, buff);
		if (line && ft_strchr(line, '\n'));
			break ;
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
	}
	temp = line;
	free(line);
	return (temp);
}
