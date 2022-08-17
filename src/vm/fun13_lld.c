/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun13_lld.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 16:10:28 by dgeonosi          #+#    #+#             */
/*   Updated: 2021/02/21 18:37:05 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	lld_helper(t_cursor *curs, t_dataall *inf, int type_arg[4], int arg[4])
{
	arg[1] = (unsigned char)get_value(inf, curs->pc + 2,
				arg_size(type_arg[1], 0));
	if (type_arg[1] == 3)
		arg[1] = (unsigned int)get_value(inf, curs->pc + arg[1], 4);
	arg[2] = (unsigned char)get_value(inf, curs->pc + 2 +
				arg_size(type_arg[1], 0), arg_size(type_arg[2], 0));
	if (check_reg(arg[2]) == 1)
	{
		curs->reg[arg[2]] = arg[1];
		if (arg[1] == 0)
			curs->carry = 1;
		else
			curs->carry = 0;
	}
}

void	run_lld(t_cursor *curs, t_dataall *inf, int cycles)
{
	int num;
	int type_arg[4];
	int arg[4];

	if (curs->waiting_cycle == 0)
		curs->command = inf->map[curs->pc];
	if (to_wait(curs, cycles))
		return ;
	num = (unsigned char)get_value(inf, curs->pc + 1, 1);
	type_arg[1] = arg_one(num);
	type_arg[2] = arg_two(num);
	if ((type_arg[1] == 2 || type_arg[1] == 3) && type_arg[2] == 1)
	{
		lld_helper(curs, inf, type_arg, arg);
	}
	curs->pc = curs->pc + 2 + arg_size(type_arg[1], 0) +
				arg_size(type_arg[2], 0);
	check_place2(curs);
}
