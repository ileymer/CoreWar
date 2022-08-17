/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:27:56 by ljerk             #+#    #+#             */
/*   Updated: 2020/03/05 17:42:04 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int		p_pd(t_spec *spec, t_flag *flag)
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
		write(spec->fd, "0x", 2);
		while (flag->precision--)
			ft_putchar_bytes('0', spec);
		if (flag->num || !flag->precision)
			ft_print_num(spec, flag->num, 16, 97);
		return (1);
	}
	return (0);
}

static int		p_wpd_and_pdw(t_spec *spec, t_flag *flag)
{
	if (flag->width > flag->precision && flag->precision > flag->len)
	{
		flag->width -= flag->precision;
		flag->precision -= flag->len;
		if (flag->hash)
			flag->width -= 2;
		if (!flag->minus)
			print_width(spec, flag);
		while (flag->precision--)
			ft_putchar_bytes('0', spec);
		write(spec->fd, "0x", 2);
		if (flag->num || !flag->precision)
			ft_print_num(spec, flag->num, 16, 97);
		if (flag->minus)
			print_width(spec, flag);
		return (1);
	}
	return (0);
}

static int		p_wd_and_dw(t_spec *spec, t_flag *flag)
{
	if ((flag->width > flag->len && flag->len > flag->precision) ||\
	(flag->width > flag->precision && flag->precision == flag->len))
	{
		flag->width = flag->width - flag->len - (2 * flag->hash);
		if (!flag->minus && !flag->zero)
			print_width(spec, flag);
		write(spec->fd, "0x", 2);
		if (!flag->minus && flag->zero)
			print_width(spec, flag);
		if (flag->num || !flag->precision)
			ft_print_num(spec, flag->num, 16, 97);
		if (flag->minus)
			print_width(spec, flag);
		return (1);
	}
	return (0);
}

static int		p_d(t_spec *spec, t_flag *flag)
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
		write(spec->fd, "0x", 2);
		if (flag->num || !flag->precision)
			ft_print_num(spec, flag->num, 16, 97);
		return (1);
	}
	return (0);
}

void			print_p(t_spec *spec, t_flag *flag)
{
	flag->num = (unsigned long)va_arg(spec->ap, unsigned long);
	flag->len = ft_len_number(flag->num, 16);
	spec->bytes += 2;
	flag->width -= 2;
	if (flag->num == 0 && flag->dot)
		flag->precision++;
	if ((!p_pd(spec, flag)))
		if ((!p_d(spec, flag)))
			if (!(p_wd_and_dw(spec, flag)))
				p_wpd_and_pdw(spec, flag);
}
