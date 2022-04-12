/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 21:35:51 by rdolf             #+#    #+#             */
/*   Updated: 2020/11/27 21:39:52 by rdolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t	l;

	if (n == 0)
		return (1);
	l = 0;
	if (n < 0)
		l++;
	while (n)
	{
		n /= 10;
		l++;
	}
	return (l);
}

char			*ft_itoa(int n)
{
	size_t	len;
	size_t	m;
	char	*rtrn;

	m = 0;
	len = ft_intlen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(rtrn = (char *)malloc(len + 1)))
		return (NULL);
	rtrn[len] = '\0';
	if (n < 0)
	{
		rtrn[0] = '-';
		n *= -1;
		m = 1;
	}
	while (len-- > m)
	{
		rtrn[len] = '0' + n % 10;
		n /= 10;
	}
	return (rtrn);
}
