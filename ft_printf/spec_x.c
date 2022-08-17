/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:23:11 by ljerk             #+#    #+#             */
/*   Updated: 2020/08/01 19:26:51 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int			xpd(t_spec *spec, t_flag *flag)
{
	int p;
	int w;
	int l;

	p = flag->precision;
	w = flag->width;
	l = flag->len;
	if ((p > w && w > l) || (p > l && l > w) || (w == p && p > l)\
		|| (p > w && w == l))
	{
		flag->precision -= l;
		if (flag->hash && (flag->num || !flag->precision))
		{
			ft_putchar_bytes('0', spec);
			ft_putchar_bytes(spec->format[spec->i], spec);
		}
		while (flag->precision--)
			ft_putchar_bytes('0', spec);
		if (flag->num || !flag->precision)
			ft_print_num(spec, flag->num, flag->base,\
							(int)spec->format[spec->i] - 23);
		return (1);
	}
	return (0);
}

static int			xwpd_and_pdw(t_spec *spec, t_flag *flag)
{
	if (flag->width > flag->precision && flag->precision > flag->len)
	{
		flag->width -= flag->precision;
		flag->precision -= flag->len;
		if (flag->hash && flag->num)
			flag->width -= 2;
		if (!flag->minus)
			print_width(spec, flag);
		if (flag->hash && (flag->num || !flag->precision))
		{
			ft_putchar_bytes('0', spec);
			ft_putchar_bytes(spec->format[spec->i], spec);
		}
		while (flag->precision--)
			ft_putchar_bytes('0', spec);
		if (flag->num || !flag->precision)
			ft_print_num(spec, flag->num, flag->base,\
						(int)spec->format[spec->i] - 23);
		if (flag->minus)
			print_width(spec, flag);
		return (1);
	}
	return (0);
}

static int			xwd_and_dw(t_spec *spec, t_flag *flag)
{
	if ((flag->width > flag->len && flag->len > flag->precision) ||\
	(flag->width > flag->precision && flag->precision == flag->len))
	{
		flag->width -= flag->len;
		if (flag->num || !flag->precision)
			flag->width -= 2 * flag->hash;
		if (!flag->minus && !flag->zero)
			print_width(spec, flag);
		if (flag->hash && (flag->num || !flag->precision))
		{
			ft_putchar_bytes('0', spec);
			ft_putchar_bytes(spec->format[spec->i], spec);
		}
		if (!flag->minus && flag->zero)
			print_width(spec, flag);
		if (flag->num || !flag->precision)
			ft_print_num(spec, flag->num, flag->base,\
						(int)spec->format[spec->i] - 23);
		if (flag->minus)
			print_width(spec, flag);
		return (1);
	}
	return (0);
}

static int			xd(t_spec *spec, t_flag *flag)
{
	int p;
	int w;
	int l;

	l = flag->len;
	p = flag->precision;
	w = flag->width;
	if ((l > w && w > p) || (l > p && p > w) || (w == l && l > p) || \
		(w == l && l == p) || (p == l && l > w) || (l > w && w == p))
	{
		if (flag->hash && (flag->num || !flag->precision))
		{
			ft_putchar_bytes('0', spec);
			ft_putchar_bytes(spec->format[spec->i], spec);
		}
		if (flag->num || !flag->precision)
			ft_print_num(spec, flag->num, flag->base,
						(int)spec->format[spec->i] - 23);
		return (1);
	}
	return (0);
}

void				print_x(t_spec *spec, t_flag *flag)
{
	flag->base = 16;
	base_make_4thflag(spec, flag, flag->base);
	if (flag->minus || flag->precision > 0)
		flag->zero = 0;
	if (flag->num == 0 && !flag->dot)
		flag->hash = 0;
	if ((!xpd(spec, flag)))
		if ((!xd(spec, flag)))
			if (!(xwd_and_dw(spec, flag)))
				xwpd_and_pdw(spec, flag);
}
