/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 23:27:48 by ljerk             #+#    #+#             */
/*   Updated: 2019/09/19 22:15:53 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *sub;
	char *begin;

	if (len + 1 < len)
		return (NULL);
	sub = (char *)malloc(sizeof(char) * len + 1);
	if (!s || !sub)
		return (NULL);
	begin = sub;
	while (len--)
	{
		*sub = s[start++];
		sub++;
	}
	*sub = '\0';
	return (begin);
}
