/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 18:23:11 by dyoung            #+#    #+#             */
/*   Updated: 2021/02/21 18:37:05 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	exe_dump(t_dataall *inf)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 128)
	{
		j = -1;
		ft_printf("0x%.4x : ", i * 32);
		while (++j < 32)
			ft_printf("%.2x ", inf->map[i * 32 + j]);
		ft_printf("\n");
	}
}

void	display(void)
{
	ft_printf("usage: ./corewar [-dump nbr_cycles] [[-n number]");
	ft_printf(" champion1.cor] ...\n");
	exit(0);
}

void	free_cursor(t_dataall *inf)
{
	t_cursor *tmp;

	while (inf->cursors != NULL)
	{
		tmp = inf->cursors;
		inf->cursors = inf->cursors->next;
		free(tmp);
	}
}

void	err_exit(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}
