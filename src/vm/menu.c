/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 16:09:48 by dgeonosi          #+#    #+#             */
/*   Updated: 2021/02/21 18:37:05 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int	arg_one(unsigned int num)
{
	num = num >> 6;
	if (num == DIR_CODE)
		return (DIR_CODE);
	else if (num == IND_CODE)
		return (IND_CODE);
	else if (num == REG_CODE)
		return (REG_CODE);
	return (0);
}

int	arg_two(unsigned int num)
{
	num = num << 26;
	num = num >> 30;
	if (num == DIR_CODE)
		return (DIR_CODE);
	else if (num == IND_CODE)
		return (IND_CODE);
	else if (num == REG_CODE)
		return (REG_CODE);
	return (0);
}

int	arg_three(unsigned int num)
{
	num = num << 28;
	num = num >> 30;
	if (num == DIR_CODE)
		return (DIR_CODE);
	else if (num == IND_CODE)
		return (IND_CODE);
	else if (num == REG_CODE)
		return (REG_CODE);
	return (0);
}

int	arg_size(int num, int f)
{
	if (num == DIR_CODE)
	{
		if (f == 0)
			return (DIR);
		else if (f == 1)
			return (DIR - 2);
	}
	else if (num == IND_CODE)
		return (IND);
	else if (num == REG_CODE)
		return (REG);
	return (0);
}

int	check_reg(int n)
{
	if (n >= 1 && n <= 16)
		return (1);
	return (0);
}
