/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 23:46:31 by ljerk             #+#    #+#             */
/*   Updated: 2019/09/19 21:50:00 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned long	i;

	i = 0;
	if (len + 1 < len)
		return (NULL);
	while (src[i] != '\0' && len > i)
	{
		dst[i] = src[i];
		i++;
	}
	if (len > i)
	{
		while (i != len)
		{
			dst[i] = '\0';
			i++;
		}
	}
	return (dst);
}
