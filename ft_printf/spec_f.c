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

static double		ft_pow(double n, int pow)
{
	return (pow ? n * ft_pow(n, pow - 1) : 1);
}

static void			ft_print_ad(t_spec *spec, t_flag *flag, long ad)
{
	flag->precision -= ft_len_number(ad, 10);
	if (!ad)
		flag->precision++;
	while (flag->precision-- > 0)
		ft_putchar_bytes('0', spec);
	if (ad)
	{
		if (ad >= 10)
			ft_print_ad(spec, flag, ad / 10);
		ad %= 10;
		ft_putchar_bytes((char)(ad + '0'), spec);
	}
}

static void			put_f(t_spec *spec, t_flag *flag)
{
	if (flag->zero && !flag->minus)
	{
		print_sign(spec, flag);
		while (flag->width-- > 0)
			ft_putchar_bytes('0', spec);
	}
	else
	{
		if (!flag->minus)
		{
			while (flag->width-- > 0)
				ft_putchar_bytes(' ', spec);
		}
		print_sign(spec, flag);
	}
	ft_print_num(spec, flag->bd, 10, 97);
	if (flag->hash || flag->precision)
		ft_putchar_bytes('.', spec);
	ft_print_ad(spec, flag, flag->ad);
	while (flag->width-- > 0)
		ft_putchar_bytes(' ', spec);
}

void				print_f(t_spec *spec, t_flag *flag)
{
	double long bd;
	double long ad;

	if (flag->bigl)
		bd = (double long)va_arg(spec->ap, double long);
	else
		bd = (double)va_arg(spec->ap, double);
	if (!flag->dot)
		flag->precision = 6;
	if (bd < 0 && ++flag->sign)
		bd *= -1;
	ad = (bd - (long)bd) * (ft_pow(10, flag->precision + 1));
	ad = ((long)ad % 10 > 4) ? (ad) / 10 + 1 : ad / 10;
	flag->bd = (long)bd + (long)(ad / ft_pow(10, flag->precision));
	flag->ad = (long)ad % (long)ft_pow(10, flag->precision);
	flag->len = ft_len_number(flag->bd, 10);
	flag->width -= flag->len + flag->precision;
	if (flag->hash || flag->precision)
		flag->width--;
	if (flag->space || flag->plus || flag->sign)
		flag->width--;
	put_f(spec, flag);
}
