/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:29:27 by ljerk             #+#    #+#             */
/*   Updated: 2019/09/19 21:47:15 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(long l)
{
	size_t	len;

	len = 1;
	while (l /= 10)
		len++;
	return (len);
}

char			*ft_itoa(int n)
{
	char			*res;
	unsigned int	l;
	size_t			len;

	len = 0;
	l = 1;
	if (n < 0)
	{
		l *= -n;
		len++;
	}
	else
		l = n;
	len += ft_len(l);
	if (!(res = ft_strnew(len)) || len + 1 < len)
		return (NULL);
	res[--len] = '0' + (l % 10);
	while (l /= 10)
		res[--len] = '0' + (l % 10);
	if (n < 0)
		*(res + 0) = '-';
	return (res);
}
