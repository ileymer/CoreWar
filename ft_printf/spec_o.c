/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:27:56 by ljerk             #+#    #+#             */
/*   Updated: 2020/03/05 17:42:04 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int		opd(t_spec *spec, t_flag *flag)
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
		p -= l;
		while (p--)
			ft_putchar_bytes('0', spec);
		if (flag->hash && flag->precision < 1)
			ft_putchar_bytes('0', spec);
		if (flag->num || !flag->precision)
			ft_print_num(spec, flag->num, 8, 97);
		return (1);
	}
	return (0);
}

static int		owpd_and_pdw(t_spec *spec, t_flag *flag)
{
	if (flag->width > flag->precision && flag->precision > flag->len)
	{
		flag->width -= flag->precision;
		flag->precision -= flag->len + flag->hash;
		if (!flag->minus)
			print_width(spec, flag);
		while (flag->precision--)
			ft_putchar_bytes('0', spec);
		if (flag->hash && flag->precision < 1)
			ft_putchar_bytes('0', spec);
		if (flag->num || !flag->precision)
			ft_print_num(spec, flag->num, flag->base, 97);
		if (flag->minus)
			print_width(spec, flag);
		return (1);
	}
	return (0);
}

static int		owd_and_dw(t_spec *spec, t_flag *flag)
{
	if ((flag->width > flag->len && flag->len > flag->precision) ||\
		(flag->width > flag->precision && flag->precision == flag->len))
	{
		flag->width = flag->width - flag->len - flag->hash;
		if (!flag->minus)
			print_width(spec, flag);
		if (flag->hash)
			ft_putchar_bytes('0', spec);
		if (flag->num || !flag->precision)
			ft_print_num(spec, flag->num, flag->base, 97);
		if (flag->minus)
			print_width(spec, flag);
		return (1);
	}
	return (0);
}

static int		od(t_spec *spec, t_flag *flag)
{
	int p;
	int w;
	int l;

	l = flag->len;
	p = flag->precision;
	w = flag->width;
	if ((l > w && w > p) || (l > p && p > w) || (w == l && l > p) ||
		(w == l && l == p) || (p == l && l > w) || (l > w && w == p))
	{
		if (flag->hash)
			ft_putchar_bytes('0', spec);
		if (flag->num || !flag->precision)
			ft_print_num(spec, flag->num, flag->base, 97);
		return (1);
	}
	return (0);
}

void			print_o(t_spec *spec, t_flag *flag)
{
	flag->base = 8;
	base_make_4thflag(spec, flag, flag->base);
	if (flag->minus)
		flag->zero = 0;
	if (flag->precision > 0)
		flag->zero = 0;
	if (flag->num == 0 && !flag->dot)
		flag->hash = 0;
	if ((!opd(spec, flag)))
		if ((!od(spec, flag)))
			if (!(owd_and_dw(spec, flag)))
				owpd_and_pdw(spec, flag);
}
