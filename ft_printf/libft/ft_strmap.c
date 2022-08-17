/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 00:16:01 by ljerk             #+#    #+#             */
/*   Updated: 2019/09/19 21:51:03 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	size_t	len;
	int		i;
	char	*st;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	if (len + 1 < len)
		return (NULL);
	res = (char *)malloc(sizeof(char) * len + 1);
	st = res;
	if (!res)
		return (NULL);
	while (s[i])
	{
		res[i] = f(s[i]);
		i++;
	}
	res[i] = '\0';
	return (st);
}
