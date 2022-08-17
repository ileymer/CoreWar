/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:37:48 by ljerk             #+#    #+#             */
/*   Updated: 2019/09/19 21:44:48 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char *d;
	char *s;

	if ((!dst && !src) || n + 1 < n)
		return (NULL);
	d = (char *)dst;
	s = (char *)src;
	while (n && (unsigned char)(*s) != (unsigned char)c)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	if (n == 0)
		return (NULL);
	else
	{
		*d = *s;
		d++;
		return (d);
	}
}
