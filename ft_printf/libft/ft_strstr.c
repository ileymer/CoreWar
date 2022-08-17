/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:58:09 by ljerk             #+#    #+#             */
/*   Updated: 2019/09/19 21:19:18 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	const char *out;
	const char *start;

	if (*s2 == '\0')
		return ((char*)s1);
	while (*s1 != '\0')
	{
		out = s1;
		start = s2;
		while (*out == *start && *start != '\0')
		{
			out++;
			start++;
		}
		if (*start == '\0')
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
