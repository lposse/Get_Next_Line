
#include <unistd.h>
#include <stdlib.h>

char	*ft_line(ssize_t bytes_read, static char *buff)
{
	char	*result;
	size_t	i;

	i = 0;
	while (bytes_read >= i)
	{
		if (buff[i] == '\n' || buff[i] == '\0')
			break ;
		else
			result[i] = buff[i];
	}
	i++;
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char	*line;
	char	*temp;
	ssize_t		bytes_read;
	
	if (!buff)
		buff = malloc((sizeof(buff) + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (bytes_read)
	{
		bytes_read = read(fd, buff, sizeof(buff));
		if (bytes_read < 0)
			return (NULL);
		else
			line = ft_line(bytes_read, buff);
	}
	temp = line;
	free(line);
	return (temp)
}
