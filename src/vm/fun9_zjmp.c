/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun9_zjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 18:05:38 by dgeonosi          #+#    #+#             */
/*   Updated: 2021/02/21 18:37:05 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	run_zjmp(t_cursor *curs, t_dataall *inf, int cycles)
{
	int	num;

	if (curs->waiting_cycle == 0)
		curs->command = inf->map[curs->pc];
	if (to_wait(curs, cycles))
		return ;
	num = (short)get_value(inf, curs->pc + 1, DIR - 2);
	if (curs->carry == 1)
	{
		curs->pc += (num % IDX_MOD);
	}
	else if (curs->carry == 0)
	{
		curs->pc += (DIR - 2 + 1);
	}
	check_place2(curs);
}
