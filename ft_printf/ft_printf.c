/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 23:09:32 by ljerk             #+#    #+#             */
/*   Updated: 2020/08/31 14:19:28 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	flags(t_spec *spec, t_flag *flag)
{
	first_flag(spec, flag);
	second_flag(spec, flag);
	third_flag(spec, flag);
	fourth_flag(spec, flag);
	print_spec(spec, flag);
}

int		parse(t_spec *spec, t_flag *flag)
{
	spec->i = 0;
	spec->bytes = 0;
	while (spec->format[spec->i] != '\0')
	{
		if (spec->format[spec->i] == '%')
		{
			spec->i++;
			flags(spec, flag);
		}
		else if (spec->format[spec->i] == '{' &&\
				spec->format[spec->i + 1] == 'f' &&\
				spec->format[spec->i + 2] == 'd' &&\
				spec->format[spec->i + 3] == '}')
		{
			spec->fd = (unsigned int)va_arg(spec->ap, unsigned int);
			spec->i += 4;
		}
		else
		{
			ft_putchar_bytes(spec->format[spec->i], spec);
			spec->i++;
		}
	}
	return (spec->bytes);
}

int		ft_printf(const char *format, ...)
{
	t_spec		spec;
	t_flag		flag;

	va_start(spec.ap, format);
	spec.format = ft_strdup(format);
	if (spec.format == NULL)
		exit(0);
	spec.fd = 1;
	parse(&spec, &flag);
	va_end(spec.ap);
	free(spec.format);
	return (spec.bytes);
}

void	ft_print_num(t_spec *spec, unsigned long n, unsigned rang, char c)
{
	if (n >= rang)
		ft_print_num(spec, n / rang, rang, c);
	n = n % rang;
	n += n < 10 ? '0' : c - 10;
	ft_putchar_bytes((char)n, spec);
}

void	print_sign(t_spec *spec, t_flag *flag)
{
	if (flag->plus && !flag->sign)
		ft_putchar_bytes('+', spec);
	if (flag->sign)
		ft_putchar_bytes('-', spec);
	else if (flag->space && !flag->plus)
		ft_putchar_bytes(' ', spec);
}
