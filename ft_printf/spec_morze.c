/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_morze.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 13:37:24 by ljerk             #+#    #+#             */
/*   Updated: 2020/07/26 13:37:26 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	print_nums(t_spec *spec, char digit)
{
	int tire;

	digit = (int)digit - 48;
	if (digit <= 5)
		tire = 5 - digit % 5;
	else
		tire = digit % 5;
	if (digit <= 5)
	{
		while (digit-- > 0)
			write(spec->fd, "*", 1);
		while (tire-- > 0)
			write(spec->fd, "-", 1);
	}
	else
	{
		while (tire-- > 0)
			write(spec->fd, "-", 1);
		digit = 5 - digit % 5;
		while (digit-- > 0)
			write(spec->fd, "*", 1);
	}
	write(spec->fd, " ", 1);
}

void	print_morze(t_spec *spec)
{
	char *str;

	if ((str = (char *)va_arg(spec->ap, char *)))
	{
		while (*str)
		{
			if (*str <= '9' && *str >= '0')
				print_nums(spec, *str);
			str++;
		}
	}
}
