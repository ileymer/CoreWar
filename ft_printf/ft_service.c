/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_service.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 23:09:32 by ljerk             #+#    #+#             */
/*   Updated: 2020/08/31 14:18:47 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			ft_putchar_bytes(int c, t_spec *spec)
{
	write(spec->fd, &c, 1);
	spec->bytes++;
	return (0);
}

void		ft_putstr_bytes(char const *s, t_spec *spec)
{
	if (!s)
		return ;
	while (*s != '\0')
	{
		write(spec->fd, s, 1);
		s++;
		spec->bytes++;
	}
}

int			ft_len_number(unsigned long num, unsigned rang)
{
	int	res;

	res = 1;
	while (num >= rang)
	{
		num /= rang;
		res++;
	}
	return (res);
}
