/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:48:05 by rdolf             #+#    #+#             */
/*   Updated: 2021/02/09 17:48:08 by rdolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*ch;

	i = 0;
	ch = (char *)s;
	while (ch[i] != (char)c)
	{
		if (ch[i] == '\0')
			return (NULL);
		i++;
	}
	return (ch + i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	char	*strj;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	strj = (char *)malloc(sizeof(*strj) * len + 1);
	if (!(strj))
		return (NULL);
	while (*s1 != '\0')
		strj[i++] = *s1++;
	while (*s2 != '\0')
		strj[i++] = *s2++;
	strj[i] = '\0';
	return (strj);
}
