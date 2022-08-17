/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun3_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 12:03:10 by dgeonosi          #+#    #+#             */
/*   Updated: 2021/02/21 18:37:05 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	st_helper(t_cursor *curs, t_dataall *inf, int targ[4], int arg[4])
{
	if (check_reg(arg[1]) == 1)
	{
		if (targ[2] == 3)
			arg[2] = (short)get_value(inf, curs->pc + 2 +
					arg_size(targ[1], 0), arg_size(targ[2], 0));
		else
			arg[2] = (unsigned char)get_value(inf, curs->pc + 2 +
					arg_size(targ[1], 0), arg_size(targ[2], 0));
		if (targ[2] == 1 && check_reg(arg[2]) == 1)
		{
			curs->reg[arg[2]] = curs->reg[arg[1]];
		}
		else if (targ[2] == 3)
		{
			arg[2] = arg[2] % IDX_MOD;
			write_map(inf, curs->pc + arg[2], curs->reg[arg[1]],
					sizeof(curs->reg[arg[1]]));
		}
	}
}

void	run_st(t_cursor *curs, t_dataall *inf, int cycles)
{
	int num;
	int targ[4];
	int arg[4];

	if (curs->waiting_cycle == 0)
		curs->command = inf->map[curs->pc];
	if (to_wait(curs, cycles))
		return ;
	num = (unsigned char)get_value(inf, curs->pc + 1, 1);
	targ[1] = arg_one(num);
	targ[2] = arg_two(num);
	if (targ[1] == 1 && (targ[2] == 1 || targ[2] == 3))
	{
		arg[1] = (unsigned char)get_value(inf, curs->pc + 2,
					arg_size(targ[1], 0));
		st_helper(curs, inf, targ, arg);
	}
	curs->pc = curs->pc + 2 + arg_size(targ[1], 0) + arg_size(targ[2], 0);
	check_place2(curs);
}
