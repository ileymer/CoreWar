/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 23:09:32 by ljerk             #+#    #+#             */
/*   Updated: 2020/08/31 14:21:37 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	init_flag(t_flag *flag)
{
	flag->plus = 0;
	flag->minus = 0;
	flag->hash = 0;
	flag->space = 0;
	flag->zero = 0;
	flag->width = 0;
	flag->dot = 0;
	flag->precision = 0;
	flag->l = 0;
	flag->ll = 0;
	flag->h = 0;
	flag->hh = 0;
	flag->bigl = 0;
	flag->star = 0;
	flag->sign = 0;
	flag->num = 0;
}

void	first_flag(t_spec *spec, t_flag *flag)
{
	init_flag(flag);
	while (spec->format[spec->i] == '+' || spec->format[spec->i] == '-' ||
			spec->format[spec->i] == '#' || spec->format[spec->i] == '0' ||
			spec->format[spec->i] == ' ')
	{
		if (spec->format[spec->i] == '+')
			flag->plus = 1;
		if (spec->format[spec->i] == '-')
			flag->minus = 1;
		if (spec->format[spec->i] == '#')
			flag->hash = 1;
		if (spec->format[spec->i] == ' ')
			flag->space = 1;
		if (spec->format[spec->i] == '0')
			flag->zero = 1;
		spec->i++;
	}
}

void	second_flag(t_spec *spec, t_flag *flag)
{
	parse_star(spec, flag);
	parse_number(spec, flag, &flag->width);
}

void	third_flag(t_spec *spec, t_flag *flag)
{
	if (spec->format[spec->i] == '.')
	{
		flag->dot = 1;
		spec->i++;
		flag->precision = 0;
		parse_star(spec, flag);
		parse_number(spec, flag, &flag->precision);
	}
}

void	fourth_flag(t_spec *spec, t_flag *flag)
{
	if (spec->format[spec->i] == 'L')
	{
		flag->bigl = 1;
		spec->i++;
	}
	else if (spec->format[spec->i] == 'h' && (spec->format[spec->i + 1] == 'h'))
	{
		flag->hh = 1;
		spec->i += 2;
	}
	else if (spec->format[spec->i] == 'h')
	{
		flag->h = 1;
		spec->i++;
	}
	else if (spec->format[spec->i] == 'l' && (spec->format[spec->i + 1] == 'l'))
	{
		flag->ll = 1;
		spec->i += 2;
	}
	else if (spec->format[spec->i] == 'l')
	{
		flag->l = 1;
		spec->i++;
	}
}
