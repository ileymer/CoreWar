/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun15_lfork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 18:16:49 by dgeonosi          #+#    #+#             */
/*   Updated: 2021/02/21 18:37:05 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	run_lfork(t_cursor *curs, t_dataall *inf, int cycles)
{
	int			num;
	int			pos;

	if (to_wait(curs, cycles))
		return ;
	curs->waiting_cycle = 0;
	num = (short)get_value(inf, curs->pc + 1, DIR - 2);
	pos = memory_belay(curs->pc + num);
	make_cursor2(inf, pos, curs);
	inf->cursors->carry = curs->carry;
	inf->cursors->pl_id = curs->pl_id;
	ft_memcpy(&inf->cursors->reg, &curs->reg, sizeof(curs->reg));
	inf->curs_qty++;
	curs->pc += 3;
	check_place2(curs);
}
