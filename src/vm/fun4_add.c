/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun4_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 16:10:08 by dgeonosi          #+#    #+#             */
/*   Updated: 2021/02/21 18:37:05 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	add_helper(t_cursor *curs, t_dataall *inf, int arg[4])
{
	arg[1] = (unsigned char)get_value(inf, curs->pc + 2, REG);
	arg[2] = (unsigned char)get_value(inf, curs->pc + 2 + REG, REG);
	arg[3] = (unsigned char)get_value(inf, curs->pc + 2 + REG + REG, REG);
	if (check_reg(arg[1]) && check_reg(arg[2]) && check_reg(arg[3]))
	{
		curs->reg[arg[3]] = curs->reg[arg[1]] + curs->reg[arg[2]];
		if (curs->reg[arg[3]] == 0)
			curs->carry = 1;
		else
			curs->carry = 0;
	}
}

void	run_add(t_cursor *curs, t_dataall *inf, int cycles)
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
	targ[3] = arg_three(num);
	if (targ[1] == 1 && targ[2] == 1 && targ[3] == 1)
	{
		add_helper(curs, inf, arg);
	}
	curs->pc = curs->pc + 2 + arg_size(targ[1], 0) + arg_size(targ[2], 0) +
				arg_size(targ[3], 0);
	check_place2(curs);
}
