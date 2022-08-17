/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun11_sti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 12:14:57 by dgeonosi          #+#    #+#             */
/*   Updated: 2021/02/21 18:37:05 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	sti_helper2(t_cursor *curs, t_dataall *inf, int targ[4], int arg[4])
{
	if ((targ[2] == 1 && check_reg(arg[2])) || targ[2] != 1)
	{
		if (targ[2] == 1)
			arg[2] = curs->reg[arg[2]];
		if (targ[3] == 2)
			arg[3] = (short)get_value(inf, curs->pc + 2 + 1 +
				arg_size(targ[2], 1), DIR - 2);
		else if (targ[3] == 1)
		{
			arg[3] = (unsigned char)get_value(inf, curs->pc + 2 + 1 +
				arg_size(targ[2], 1), REG);
		}
		if ((targ[3] == 1 && check_reg(arg[3])) || targ[3] != 1)
		{
			if (targ[3] == 1)
				arg[3] = curs->reg[arg[3]];
			write_map(inf, curs->pc + (arg[2] + arg[3]) % IDX_MOD,
				curs->reg[arg[1]], 4);
		}
	}
}

void	sti_helper(t_cursor *curs, t_dataall *inf, int targ[4], int arg[4])
{
	if (check_reg(arg[1]))
	{
		if (targ[2] == 2)
			arg[2] = (short)get_value(inf, curs->pc + 2 + 1, DIR - 2);
		else if (targ[2] == 1)
			arg[2] = (unsigned char)get_value(inf, curs->pc + 2 + 1, REG);
		else if (targ[2] == 3)
		{
			arg[2] = (short)get_value(inf, curs->pc + 2 + 1, IND);
			arg[2] = get_value(inf, curs->pc + (arg[2] % IDX_MOD), DIR);
		}
		sti_helper2(curs, inf, targ, arg);
	}
}

void	run_sti(t_cursor *curs, t_dataall *inf, int cycles)
{
	int num;
	int targ[4];
	int arg[4];

	if (curs->waiting_cycle == 0)
		curs->command = inf->map[curs->pc];
	if (to_wait(curs, cycles))
		return ;
	num = (unsigned char)get_value(inf, curs->pc + 1, 1);
	if (inf->cycles == 140)
		arg[0] = 0;
	targ[1] = arg_one(num);
	targ[2] = arg_two(num);
	targ[3] = arg_three(num);
	if ((targ[1] == 1) && (targ[2] == 1 || targ[2] == 2 || targ[2] == 3)
					&& (targ[3] == 1 || targ[3] == 2))
	{
		arg[1] = (unsigned char)get_value(inf, curs->pc + 2, REG);
		sti_helper(curs, inf, targ, arg);
	}
	curs->pc = curs->pc + 2 + arg_size(targ[1], 1) +
			arg_size(targ[2], 1) + arg_size(targ[3], 1);
	check_place2(curs);
}
