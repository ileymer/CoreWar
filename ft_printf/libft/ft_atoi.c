/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 19:42:33 by ljerk             #+#    #+#             */
/*   Updated: 2019/09/18 22:56:09 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long long	ft_over(char *str, int m)
{
	unsigned long long	res;
	int					i;

	i = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (m == -1)
	{
		if (res >= 2147483648)
			return (0);
		return (res);
	}
	if (res >= 2147483647)
		return (-1);
	return (res);
}

int							ft_atoi(const char *str)
{
	int		r;
	int		m;
	char	*s;
	int		i;

	r = 0;
	m = 1;
	s = (char*)str;
	i = 0;
	while (s[i] == '\n' || s[i] == ' ' || s[i] == '\t' ||
			s[i] == '\r' || s[i] == '\v' || s[i] == '\f')
	{
		i++;
	}
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			m = -1;
		i++;
	}
	r = ft_over(s + i, m);
	return ((int)r * m);
}
