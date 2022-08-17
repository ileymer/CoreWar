/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:23:11 by ljerk             #+#    #+#             */
/*   Updated: 2020/08/01 19:27:06 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	parse_star(t_spec *spec, t_flag *flag)
{
	int val;

	if (spec->format[spec->i] == '*' && ++spec->i)
	{
		flag->star = 1;
		if ((val = (int)va_arg(spec->ap, int)))
		{
			if (val < 0 && flag->dot)
				flag->dot = 0;
			else if (val < 0 && !flag->dot)
			{
				flag->minus = 1;
				flag->width = FT_ABS(val);
			}
			else
			{
				if (flag->dot)
					flag->precision = val;
				else
					flag->width = val;
			}
		}
		else
			flag->zero = 1;
	}
}

void	parse_number(t_spec *spec, t_flag *flag, int *res)
{
	if (spec->format[spec->i] <= '9' && spec->format[spec->i] >= '0' &&
		(!*res || flag->star))
	{
		*res = 0;
		while (spec->format[spec->i] <= '9' && spec->format[spec->i] >= '0')
		{
			*res *= 10;
			*res += spec->format[spec->i] - '0';
			spec->i++;
		}
	}
}
