/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 18:34:21 by dgeonosi          #+#    #+#             */
/*   Updated: 2021/02/21 18:37:05 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	distribc_continued(t_cursor *curs, t_dataall *inf)
{
	if (curs->command == 7)
		run_or(curs, inf, 6);
	else if (curs->command == 8)
		run_xor(curs, inf, 6);
	else if (curs->command == 9)
		run_zjmp(curs, inf, 20);
	else if (curs->command == 10)
		run_ldi(curs, inf, 25);
	else if (curs->command == 11)
		run_sti(curs, inf, 25);
	else if (curs->command == 12)
		run_fork(curs, inf, 800);
	else if (curs->command == 13)
		run_lld(curs, inf, 10);
	else if (curs->command == 14)
		run_lldi(curs, inf, 50);
	else if (curs->command == 15)
		run_lfork(curs, inf, 1000);
	else if (curs->command == 16)
		run_aff(curs, inf, 2);
}

void	distribc(t_cursor *curs, t_dataall *inf)
{
	if (curs->command <= 0 || curs->command > 16)
	{
		curs->pc = memory_belay(++curs->pc);
		curs->command = inf->map[curs->pc];
	}
	else if (curs->command == 1)
		run_live(curs, inf, 10);
	else if (curs->command == 2)
		run_ld(curs, inf, 5);
	else if (curs->command == 3)
		run_st(curs, inf, 5);
	else if (curs->command == 4)
		run_add(curs, inf, 10);
	else if (curs->command == 5)
		run_sub(curs, inf, 10);
	else if (curs->command == 6)
		run_and(curs, inf, 6);
	else
		distribc_continued(curs, inf);
}
