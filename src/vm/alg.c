/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 16:09:11 by dgeonosi          #+#    #+#             */
/*   Updated: 2021/02/21 19:15:01 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	moving_cursor(t_dataall *inf)
{
	t_cursor *curs;

	curs = inf->cursors;
	while (curs)
	{
		if (curs->waiting_cycle == 0)
			curs->command = inf->map[curs->pc];
		distribc(curs, inf);
		curs = curs->next;
	}
}

void	main_cycle(t_dataall *inf, int *count, int *cycles)
{
	moving_cursor(inf);
	if (*cycles == inf->cycles_to_die)
	{
		*cycles = 0;
		check_cursor(inf);
		if (inf->lives >= NBR_LIVE || *count == MAX_CHECKS)
		{
			*count = 1;
			inf->cycles_to_die -= CYCLE_DELTA;
		}
		else
			(*count)++;
		inf->lives = 0;
	}
}

void	algo(t_dataall *inf)
{
	int				cycles;
	int				count;

	count = 1;
	cycles = 1;
	inf->cycles = 1;
	if (inf->dump == 0 && inf->dump_valid == 1)
	{
		del_all(inf);
		return ;
	}
	while (inf->cycles_to_die > 0 && inf->curs_qty > 0)
	{
		main_cycle(inf, &count, &cycles);
		cycles++;
		inf->cycles++;
		if (inf->dump_valid == 1 && inf->cycles == inf->dump + 1)
			break ;
	}
	if (!inf->dump)
	{
		main_cycle(inf, &count, &cycles);
	}
	if (inf->curs_qty > 0)
		del_all(inf);
}
