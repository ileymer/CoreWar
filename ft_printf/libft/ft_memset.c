/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:29:02 by ljerk             #+#    #+#             */
/*   Updated: 2020/08/12 17:27:15 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *d, int c, size_t len)
{
	unsigned char	*buf;
	unsigned char	ch;

	buf = (unsigned char *)d;
	ch = (unsigned char)c;
	while (len-- > 0)
		*buf++ = ch;
	return (d);
}
