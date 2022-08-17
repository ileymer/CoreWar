/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_champs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 18:46:09 by dyoung            #+#    #+#             */
/*   Updated: 2021/02/21 18:37:05 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void		read_name_and_header(t_player *champ, int fd)
{
	unsigned char	header[4];
	unsigned int	magic;

	if (read(fd, header, 4) != 4)
		err_exit("Possible read error");
	magic = (header[1] << 16) | (header[2] << 8) | header[3];
	if (magic != COREWAR_EXEC_MAGIC)
		err_exit("Header is wrong");
	if (read(fd, champ->name, PROG_NAME_LENGTH) != PROG_NAME_LENGTH)
		err_exit("Name is wrong");
	champ->name[PROG_NAME_LENGTH] = '\0';
}

void		read_comment_and_code(t_player *champ, int fd)
{
	char			space[4];
	unsigned char	size_code[4];
	char			null[4];
	int				i;

	i = -1;
	champ->size = 0;
	ft_bzero(&space, sizeof(char) * 4);
	ft_bzero(&size_code, sizeof(char) * 4);
	ft_bzero(&null, sizeof(char) * 4);
	if (read(fd, null, 4) != 4 || !ft_strequ((const char *)null, space))
		err_exit("First null is wrong");
	if (read(fd, size_code, 4) != 4)
		err_exit("Champion exec code size is wrong");
	if (read(fd, champ->comment, COMMENT_LENGTH) != COMMENT_LENGTH)
		err_exit("Champion comment is wrong");
	champ->comment[COMMENT_LENGTH] = '\0';
	while (++i < 4)
		champ->size = (champ->size << 8) | size_code[i];
	if (champ->size == 0 || champ->size > CHAMP_MAX_SIZE)
		err_exit("Champion exec code size is wrong");
	if (read(fd, null, 4) != 4 || !ft_strequ((const char *)null, space))
		err_exit("Second null is wrong");
}

t_player	read_champ(char *av, t_dataall *inf, int numb, int id)
{
	int				fd;
	t_player		champ;

	if ((fd = open(av, O_RDONLY)) < 0)
		err_exit("Cannot open file");
	ft_bzero(&champ, sizeof(t_player));
	read_name_and_header(&champ, fd);
	read_comment_and_code(&champ, fd);
	read(fd, champ.exec_code, CHAMP_MAX_SIZE);
	champ.id = id;
	champ.numb = numb;
	inf->n[numb * (-1) - 1] = numb * (-1);
	return (champ);
}

int			check_n(t_dataall *inf)
{
	int i;

	i = 1;
	while (inf->n[i - 1] != 0)
		i++;
	return (i);
}

void		init_champs(t_dataall *inf, int ac, char **av)
{
	int	i;
	int	id;

	i = 0;
	id = -1;
	while (++i < ac)
	{
		if (ft_strstr(av[i], ".cor"))
		{
			++id;
			if (i > 2 && ft_strequ(av[i - 2], "-n") && ft_atoi(av[i - 1]))
			{
				inf->p_mas[id] = read_champ(av[i], inf,
				ft_atoi(av[i - 1]) * (-1), id);
			}
			else
			{
				inf->p_mas[id] = read_champ(av[i], inf,
				check_n(inf) * (-1), id);
			}
		}
	}
}
