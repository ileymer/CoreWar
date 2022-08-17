/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 22:22:01 by ljerk             #+#    #+#             */
/*   Updated: 2019/09/20 17:24:58 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	slen;
	int		lastres;

	if (len + 1 < len)
		return (NULL);
	if (*s2 == '\0')
		return ((char*)s1);
	slen = ft_strlen(s2);
	lastres = 1;
	while (*s1 != '\0' && slen <= len && (lastres = ft_strncmp(s1, s2, slen)))
	{
		len--;
		s1++;
	}
	if (lastres != 0)
		return (NULL);
	else
		return ((char*)s1);
}
