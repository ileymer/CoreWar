/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:29:32 by ljerk             #+#    #+#             */
/*   Updated: 2020/08/31 14:20:45 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# define FT_ABS(X) ((X) < 0 ? - (X) : (X))
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct			s_flag
{
	int					plus;
	int					minus;
	int					hash;
	int					space;
	int					zero;
	int					star;
	int					width;
	int					dot;
	int					precision;
	int					l;
	int					ll;
	int					bigl;
	int					h;
	int					hh;
	int					sign;
	unsigned long		num;
	int					len;
	char				type;
	unsigned long		bd;
	long				ad;
	unsigned long		base;
}						t_flag;

typedef struct			s_spec
{
	int					i;
	char				*format;
	int					bytes;
	unsigned int		fd;
	va_list				ap;
}						t_spec;

int						ft_printf(const char *format, ...);
void					first_flag(t_spec *spec, t_flag *flag);
void					second_flag(t_spec *spec, t_flag *flag);
void					third_flag(t_spec *spec, t_flag *flag);
void					fourth_flag(t_spec *spec, t_flag *flag);
void					print_spec(t_spec *spec, t_flag *flag);
void					print_c(t_spec *spec, t_flag *flag);
void					print_s(t_spec *spec, t_flag *flag);
void					print_d(t_spec *spec, t_flag *flag);
void					print_u(t_spec *spec, t_flag *flag);
void					print_x(t_spec *spec, t_flag *flag);
void					print_o(t_spec *spec, t_flag *flag);
void					print_f(t_spec *spec, t_flag *flag);
void					print_p(t_spec *spec, t_flag *flag);
void					print_percent(t_spec *spec, t_flag *flag);
void					print_morze(t_spec *spec);
void					print_q(t_spec *spec, t_flag *flag);
void					print_base(t_spec *spec, t_flag *flag);
void					parse_star(t_spec *spec, t_flag *flag);
int						ft_putchar_bytes(int c, t_spec *spec);
void					ft_putstr_bytes(char const *s, t_spec *spec);
void					parse_number(t_spec *spec, t_flag *flag, int *res);
void					make_4thflag(t_spec *spec, t_flag *flag);
void					base_make_4thflag(t_spec *spec, t_flag *flag, int base);
int						ft_len_number(unsigned long num, unsigned rang);
void					ft_print_num(t_spec *spec, unsigned long n,\
									unsigned rang, char c);
void					print_sign(t_spec *spec, t_flag *flag);
void					print_width(t_spec *spec, t_flag *flag);

#endif
