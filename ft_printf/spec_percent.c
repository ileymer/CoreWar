/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 18:23:11 by ljerk             #+#    #+#             */
/*   Updated: 2020/08/01 19:26:38 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		print_percent(t_spec *spec, t_flag *flag)
{
	flag->len = 1;
	if (flag->width)
		flag->width--;
	if (flag->minus)
	{
		ft_putchar_bytes('%', spec);
		while (flag->width--)
			ft_putchar_bytes(' ', spec);
	}
	else
	{
		while (flag->width--)
		{
			if (flag->zero)
				ft_putchar_bytes('0', spec);
			else
				ft_putchar_bytes(' ', spec);
		}
		ft_putchar_bytes('%', spec);
	}
}
