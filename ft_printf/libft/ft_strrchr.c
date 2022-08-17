/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 23:34:31 by ljerk             #+#    #+#             */
/*   Updated: 2019/09/11 16:48:23 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char ch;
	char *out;

	out = NULL;
	ch = (char)c;
	while (*s != '\0')
	{
		if (*s == ch)
			out = (char *)s;
		s++;
	}
	if (*s == ch)
		return ((char *)s);
	else
		return (out);
}
