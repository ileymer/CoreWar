/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:35:40 by ljerk             #+#    #+#             */
/*   Updated: 2019/09/19 21:40:47 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		ld;
	size_t		ls;
	long		i;
	long		j;
	long		s;

	ld = ft_strlen(dst);
	ls = ft_strlen(src);
	if (ls + 1 < ls || ld + 1 < ld || size + 1 < size)
		return (0);
	i = 0;
	j = 0;
	s = size - ld;
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0' && j + 1 < s)
	{
		dst[i + j] = (char)src[j];
		j++;
	}
	dst[i + j] = '\0';
	if (size < ld)
		return (ls + size);
	return (ld + ls);
}
