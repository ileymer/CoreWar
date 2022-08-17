/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun1_live.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:30:19 by dgeonosi          #+#    #+#             */
/*   Updated: 2021/02/21 18:37:05 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int		to_wait(t_cursor *curs, int cycles)
{
	if (curs->waiting_cycle < cycles - 1)
	{
		curs->waiting_cycle++;
		return (1);
	}
	return (0);
}

void	last_live(t_dataall *inf, int num)
{
	int	i;

	i = -1;
	while (++i < inf->p_kol)
	{
		if (inf->p_mas[i].numb == num)
		{
			inf->last = inf->p_mas[i].id;
			inf->p_mas[i].alive++;
		}
	}
}

void	run_live(t_cursor *curs, t_dataall *inf, int cycles)
{
	int	num;

	if (curs->waiting_cycle == 0)
		curs->command = inf->map[curs->pc];
	if (to_wait(curs, cycles))
		return ;
	inf->lives++;
	curs->cycle_live = inf->cycles;
	num = (unsigned int)get_value(inf, curs->pc + 1, DIR);
	last_live(inf, num);
	curs->pc += (DIR + 1);
	check_place2(curs);
}
