/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specificator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 23:22:24 by ljerk             #+#    #+#             */
/*   Updated: 2020/03/06 18:35:17 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void	def_types(t_spec *spec, t_flag *flag)
{
	if (spec->format[spec->i] == 's')
		print_s(spec, flag);
	if (spec->format[spec->i] == 'c')
		print_c(spec, flag);
	if (spec->format[spec->i] == 'q')
		print_q(spec, flag);
	if (spec->format[spec->i] == 'b')
		print_base(spec, flag);
	if (spec->format[spec->i] == 'd' || spec->format[spec->i] == 'i')
		print_d(spec, flag);
	if (spec->format[spec->i] == 'u' || spec->format[spec->i] == 'U')
		print_u(spec, flag);
	if (spec->format[spec->i] == 'o' || spec->format[spec->i] == 'O')
		print_o(spec, flag);
	if (spec->format[spec->i] == 'x' || spec->format[spec->i] == 'X')
		print_x(spec, flag);
	if (spec->format[spec->i] == 'p')
		print_p(spec, flag);
	if (spec->format[spec->i] == 'f' || spec->format[spec->i] == 'F')
		print_f(spec, flag);
	if (spec->format[spec->i] == '%')
		print_percent(spec, flag);
	if (spec->format[spec->i] == 'm')
		print_morze(spec);
}

void		print_spec(t_spec *spec, t_flag *flag)
{
	if (spec->format[spec->i] == 's' || spec->format[spec->i] == 'S' ||
		spec->format[spec->i] == 'c' || spec->format[spec->i] == 'C' ||
		spec->format[spec->i] == 'p' || spec->format[spec->i] == 'i' ||
		spec->format[spec->i] == 'd' || spec->format[spec->i] == 'D' ||
		spec->format[spec->i] == 'o' || spec->format[spec->i] == 'O' ||
		spec->format[spec->i] == 'u' || spec->format[spec->i] == 'U' ||
		spec->format[spec->i] == 'x' || spec->format[spec->i] == 'X' ||
		spec->format[spec->i] == 'f' || spec->format[spec->i] == 'F' ||
		spec->format[spec->i] == 'q' || spec->format[spec->i] == 'Q' ||
		spec->format[spec->i] == 'b' || spec->format[spec->i] == 'B' ||
		spec->format[spec->i] == 'm' || spec->format[spec->i] == 'M' ||
		spec->format[spec->i] == '%')
	{
		def_types(spec, flag);
		spec->i++;
	}
}
