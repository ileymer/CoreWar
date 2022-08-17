/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 16:11:11 by dgeonosi          #+#    #+#             */
/*   Updated: 2021/02/21 18:37:05 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int		ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	del_all(t_dataall *inf)
{
	t_cursor	*tmp;

	while (inf->cursors)
	{
		tmp = inf->cursors;
		inf->curs_qty--;
		inf->cursors = inf->cursors->next;
		free(tmp);
	}
}

void	check_place2(t_cursor *curs)
{
	curs->pc = memory_belay(curs->pc);
	curs->waiting_cycle = 0;
}

void	output_win(t_dataall *inf)
{
	if (inf->dump_valid && inf->cycles >= inf->dump)
		exe_dump(inf);
	else if (!(inf->cycles >= inf->dump))
	{
		ft_printf("Contestant %d ", ft_abs(inf->p_mas[inf->last].numb));
		ft_printf("\"%s\", has won !\n", inf->p_mas[inf->last].name);
	}
	if (!inf->dump_valid)
	{
		ft_printf("Contestant %d ", ft_abs(inf->p_mas[inf->last].numb));
		ft_printf("\"%s\", has won !\n", inf->p_mas[inf->last].name);
	}
}

void	write_map(t_dataall *inf, int pos, int src, size_t len)
{
	int				i;
	unsigned char	a[5];

	a[0] = (unsigned char)(src >> 24);
	a[1] = (unsigned char)(src >> 16);
	a[2] = (unsigned char)(src >> 8);
	a[3] = (unsigned char)src;
	a[4] = '\0';
	i = -1;
	while (++i < (int)len)
		inf->map[memory_belay(pos + i)] = a[i];
}
