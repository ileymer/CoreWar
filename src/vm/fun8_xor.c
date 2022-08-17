/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun8_xor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 12:37:56 by dgeonosi          #+#    #+#             */
/*   Updated: 2021/02/21 18:37:05 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	xor_helper(t_cursor *curs, t_dataall *inf, int targ[5], int arg[4])
{
	if ((targ[1] == 1 && check_reg(arg[1])) || targ[1] != 1)
	{
		if (targ[1] == 1)
			arg[1] = curs->reg[arg[1]];
		targ[0] = targ[2];
		arg[2] = end_arg(curs, inf, targ, curs->pc + 2 + arg_size(targ[1], 0));
		if ((targ[2] == 1 && check_reg(arg[2])) || targ[2] != 1)
		{
			if (targ[2] == 1)
				arg[2] = curs->reg[arg[2]];
			arg[3] = get_value(inf, curs->pc + 2 + arg_size(targ[1], 0) +
									arg_size(targ[2], 0), REG);
			if (check_reg(arg[3]))
			{
				curs->reg[arg[3]] = (unsigned int)(arg[1] ^ arg[2]);
				if (curs->reg[arg[3]] == 0)
					curs->carry = 1;
				else
					curs->carry = 0;
			}
		}
	}
}

void	run_xor(t_cursor *curs, t_dataall *inf, int cycles)
{
	int num;
	int targ[5];
	int arg[4];

	if (curs->waiting_cycle == 0)
		curs->command = inf->map[curs->pc];
	if (to_wait(curs, cycles))
		return ;
	num = (unsigned char)get_value(inf, curs->pc + 1, 1);
	targ[1] = arg_one(num);
	targ[2] = arg_two(num);
	targ[3] = arg_three(num);
	targ[4] = 0;
	if ((targ[1] == 1 || targ[1] == 2 || targ[1] == 3) &&
		(targ[2] == 1 || targ[2] == 2 || targ[2] == 3) && targ[3] == 1)
	{
		targ[0] = targ[1];
		arg[1] = end_arg(curs, inf, targ, curs->pc + 2);
		xor_helper(curs, inf, targ, arg);
	}
	curs->pc = curs->pc + 2 + arg_size(targ[1], 0) +
				arg_size(targ[2], 0) + arg_size(targ[3], 0);
	check_place2(curs);
}
