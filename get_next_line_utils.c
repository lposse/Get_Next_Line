/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lposse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:42:16 by lposse            #+#    #+#             */
/*   Updated: 2025/03/04 22:18:34 by lposse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr_s;

	if (!s)
		return (NULL);
	if (c < 0 || c > 255)
		return (NULL);
	ptr_s = (char *)s;
	while (*ptr_s != '\0')
	{
		if (*ptr_s == (char)c)
			return (ptr_s);
		ptr_s++;
	}
	if (c == '\0')
		return (ptr_s);
	return (NULL);
}

char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*s2;

	len = 0;
	while (src[len] != '\0')
		len++;
	s2 = (char *)malloc((len + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		s2[i] = src[i];
		i++;
	}
	s2[len] = '\0';
	return (s2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (len == 0 || start >= s_len)
		return (ft_strdup(""));
	if (s_len - start < len || len > s_len)
		len = s_len - start;
	substr = (char *)ft_calloc((len + 1), sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	return (substr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}
