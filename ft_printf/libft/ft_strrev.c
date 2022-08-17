/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:26:06 by ljerk             #+#    #+#             */
/*   Updated: 2019/09/18 20:36:51 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(const char *str)
{
	char	*out;
	int		len;
	char	*start;

	len = ft_strlen(str);
	out = (char *)malloc(sizeof(char) * len + 1);
	start = out;
	len--;
	while (len >= 0)
	{
		*out = str[len];
		out++;
		len--;
	}
	*out = '\0';
	return (start);
}
