/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_q.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 18:23:11 by ljerk             #+#    #+#             */
/*   Updated: 2020/08/01 19:27:21 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void		second_pt(t_spec *spec)
{
	char	*troll2;
	int		len;

	troll2 =
	"\n	|||oo__ooo|_____oo|_____||ooo|_o__|oo_____o||\n\
	||||o__oo|ooo|___o___|oooo|____ooooo_____oo||\n\
	||||o__o_|__ooooooooo||__o__|ooo|_o_____oo|||\n\
	||||o|_ooo__|___o___|____ooooo|o_oo____oo||||\n\
	||||o|_ooooooo|oo||oo|ooooo|___|oo_____o|||||\n\
	||||o|_ooooooooooooooooo|_o____oo_____oo|||||\n\
	||||o|_oooooooooooo|o|____o__|oo______o||||||\n\
	||||o__|oo_o_o__o___||____|ooo______|o|||||||\n\
	||||o___oo|o_||_||__|o__|ooo|___||_|o||||||||\n\
	||||o_____ooooooooooooooo|___|||||oo|||||||||\n\
	||||o__________|||||_______|||_|oo|||||||||||\n\
	||||o_|__||____________||||__|oo|||||||||||||\n\
	||||o__||__|________||||___|oo|||||||||||||||\n\
	||||o___||||_____________|oo|||||||||||||||||\n\
	||||oo_______________||ooo|||||||||||||||||||\n\
	|||||oo__________|ooooo||||||||||||||||||||||\n\
	|||||||ooooooooooo|||||||||||||||||||||||||||\n";
	len = ft_strlen(troll2);
	write(spec->fd, troll2, len);
	spec->bytes += len;
}

static void		print_troll(t_spec *spec)
{
	char	*troll;
	int		len;

	troll =
	"	|||||||||||||||||||||||||||||||||||||||||||||\n\
	||||||||||||oooooooooooooooooooooo|||||||||||\n\
	||||||||||ooooo|||_________________oo||||||||\n\
	||||||||oo|_______||||______|||_____oo|||||||\n\
	||||||oo______||_________||||||||____o|||||||\n\
	||||||o____||___|_____||______||||___|o||||||\n\
	|||||o|___|_____|_____|_________|_____o||||||\n\
	|||||o__________________|oooo|________|o|||||\n\
	||||oo_____oooo|______|oo_ooooo|_______oo||||\n\
	|||oo_|_|_ooooooo_|___o__|oooooo|||____|oo|||\n\
	|||o_|________||oo|___ooo|__|_____|ooo|__|o||\n\
	||o|__|oo|______||_____|____oo__|oo|__oo__|o|\n\
	||o|__|||oooo___o|___________|oo|___o__o|__o|\n\
	||o|____|_||___oo_____|o|_________ooo|__o__o|\n\
	|||o_|__o____|oo______||o|_____|oo|_ooo|o__o|\n\
	|||o|__oo___||oo____ooo_o___|ooo|___o__o___o|";
	len = ft_strlen(troll);
	write(spec->fd, troll, len);
	second_pt(spec);
	spec->bytes += len;
}

static void		print_42(t_spec *spec)
{
	char	*pr42;
	int		len;

	pr42 =
	"______:::______::::::::__\n\
	____:+::____:+:____:+:___\n\
	__+:+_+:+_________+:+____\n\
	_+#+__+:+_______+#+______\n\
	+#+#+#+#+#+___+#+________\n\
	___#+#____#+#____________\n\
	__###___########________\n";
	len = ft_strlen(pr42);
	write(spec->fd, pr42, len);
	spec->bytes += len;
}

void			print_q(t_spec *spec, t_flag *flag)
{
	int		type;
	char	*face;

	if ((type = (int)va_arg(spec->ap, int)))
	{
		if (flag->width == 42)
			print_42(spec);
		else if (flag->width == 1337)
			print_troll(spec);
		else if (type == 1)
			face = ":)\n";
		else if (type == 2)
			face = ":(\n";
		else if (type == 3)
			face = "xD\n";
		if (flag->width != 42 && flag->width != 1337)
			spec->bytes += flag->width * 3;
		while (flag->width--)
			write(spec->fd, face, 3);
	}
}
