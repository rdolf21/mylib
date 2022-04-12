/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:05:49 by rdolf             #+#    #+#             */
/*   Updated: 2021/11/18 17:05:59 by rdolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strnew(int i)
{
	char		*str;

	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	while (i > 0)
	{
		str[i] = '\0';
		i--;
	}
	return (str);
}

char	*ft_new_remainder(char *remainder_line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (remainder_line[i] && remainder_line[i] != '\n')
		i++;
	if (!remainder_line[i])
	{
		free(remainder_line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(remainder_line) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (remainder_line[i])
		str[j++] = remainder_line[i++];
	str[j] = '\0';
	free(remainder_line);
	return (str);
}

char	*ft_get_line(char *remainder)
{
	int		i;
	char	*get_line;

	i = 0;
	if (!remainder[i])
		return (NULL);
	while (remainder[i] && remainder[i] != '\n')
		i++;
	get_line = (char *)malloc(sizeof(char) * (i + 2));
	if (!get_line)
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
	{
		get_line[i] = remainder[i];
		i++;
	}
	if (remainder[i] == '\n')
	{
		get_line[i] = remainder[i];
		i++;
	}
	get_line[i] = '\0';
	return (get_line);
}

char	*read_line(int fd, char *line)
{
	int		byte_was_read;
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;

	byte_was_read = 1;
	while (!ft_strchr(line, '\n') && byte_was_read != 0)
	{
		byte_was_read = read(fd, buff, BUFFER_SIZE);
		if (byte_was_read == -1)
			return (NULL);
		buff[byte_was_read] = '\0';
		tmp = line;
		line = ft_strjoin(line, buff);
		free(tmp);
		if (!(line))
			return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*remainder_line;
	char		*line;

	if ((fd < 0 || BUFFER_SIZE < 1
			|| (read(fd, buff, 0)) < 0))
		return (NULL);
	if (!remainder_line)
		remainder_line = ft_strnew(0);
	remainder_line = read_line(fd, remainder_line);
	line = ft_get_line(remainder_line);
	remainder_line = ft_new_remainder(remainder_line);
	return (line);
}
