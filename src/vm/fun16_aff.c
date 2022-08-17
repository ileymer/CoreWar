/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun16_aff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 16:10:43 by dgeonosi          #+#    #+#             */
/*   Updated: 2021/02/21 18:37:05 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	run_aff(t_cursor *curs, t_dataall *inf, int cycles)
{
	int	num;
	int	targ;

	if (curs->waiting_cycle == 0)
		curs->command = inf->map[curs->pc];
	if (to_wait(curs, cycles))
		return ;
	num = (unsigned char)get_value(inf, curs->pc + 1, 1);
	targ = arg_one(num);
	if (targ == 1)
	{
		num = (unsigned char)get_value(inf, curs->pc + 2, REG);
		if (check_reg(num) == 1)
		{
			ft_printf("%d %c\n", curs->numb, curs->reg[num] % 256);
		}
	}
	curs->pc = curs->pc + 2 + arg_size(targ, 0);
	check_place2(curs);
}
