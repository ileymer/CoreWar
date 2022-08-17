/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 18:12:36 by dyoung            #+#    #+#             */
/*   Updated: 2021/02/21 18:37:05 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	introducing(t_dataall *inf)
{
	int	i;

	i = -1;
	ft_printf("Introducing contestants...\n");
	while (++i < inf->p_kol)
	{
		ft_printf("* Player %d, ", ft_abs(inf->p_mas[i].numb));
		ft_printf("weighing %u bytes, ", inf->p_mas[i].size);
		ft_printf("\"%s\" ", inf->p_mas[i].name);
		ft_printf("(\"%s\") !\n", inf->p_mas[i].comment);
	}
}

void	init_map(t_dataall *inf)
{
	int	i;
	int	id;

	i = 0;
	id = -1;
	while (i++ < inf->p_kol)
	{
		++id;
		ft_memcpy(&inf->map[inf->step * id], inf->p_mas[id].exec_code,
		(size_t)inf->p_mas[id].size);
		make_cursor(inf->p_mas[id].id, inf, inf->step * id);
		inf->cursors->reg[1] = (unsigned int)inf->p_mas[id].numb;
		inf->curs_qty++;
	}
	introducing(inf);
}

void	sort(t_dataall *inf)
{
	int			flag;
	int			i;
	t_player	swap_arr;
	int			swap_id;

	flag = 0;
	while (flag == 0)
	{
		i = 0;
		flag = 1;
		while (i < inf->p_kol - 1)
		{
			if (inf->p_mas[i].numb < inf->p_mas[i + 1].numb)
			{
				flag = 0;
				swap_id = inf->p_mas[i].id;
				inf->p_mas[i].id = inf->p_mas[i + 1].id;
				inf->p_mas[i + 1].id = swap_id;
				swap_arr = inf->p_mas[i];
				inf->p_mas[i] = inf->p_mas[i + 1];
				inf->p_mas[i + 1] = swap_arr;
			}
			i++;
		}
	}
}

int		p_kol(int ac, char **av)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (++i < ac)
	{
		if (ft_strstr(av[i], ".cor"))
			count++;
	}
	if (count > MAX_PLAYERS)
		err_exit("Players more than 4");
	return (count);
}

int		main(int ac, char **av)
{
	t_dataall	inf;

	if (ac > 1)
	{
		ft_bzero(&inf, sizeof(t_dataall));
		inf.cycles_to_die = CYCLE_TO_DIE;
		inf.p_kol = p_kol(ac, av);
		if (inf.p_kol > 1)
			inf.step = MEM_SIZE / inf.p_kol;
		if (inf.p_kol)
		{
			valid(&inf, ac, av);
			init_champs(&inf, ac, av);
			sort(&inf);
			init_map(&inf);
			algo(&inf);
			output_win(&inf);
		}
		else
			display();
	}
	else
		display();
	free_cursor(&inf);
	return (0);
}
