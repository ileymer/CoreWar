/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 18:16:04 by dyoung            #+#    #+#             */
/*   Updated: 2021/02/21 19:26:25 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int		check_dump(char *s)
{
	int l;

	l = ft_strlen(s);
	if (l == 1 && s[0] == '0')
		return (1);
	return (0);
}

void	flag_dump(t_dataall *inf, int ac, char **av)
{
	int i;

	i = 0;
	while (++i < ac)
	{
		if (ft_strequ(av[i], "-dump") && ac > i)
		{
			inf->dump_valid = 1;
			if (check_dump(av[i + 1]) == 1)
				inf->dump = 0;
			else if (ft_atoi(av[i + 1]) == 0)
				inf->dump_valid = -1;
			else if (ft_atoi(av[i + 1]) > 0)
				inf->dump = ft_atoi(av[i + 1]);
			else
				inf->dump_valid = 0;
		}
		if (inf->dump_valid == -1)
			display();
	}
}

void	flag_n(t_dataall *inf, int ac, char **av)
{
	int i;
	int numb;

	i = 0;
	numb = 1;
	while (++i < ac)
	{
		if (ft_strequ(av[i], "-n") && ac > i)
		{
			numb = ft_atoi(av[i + 1]);
			if (numb > 4 || numb < 1 || inf->n[numb - 1] == numb)
				err_exit("Invalid argument for flag -n");
			else
				inf->n[numb - 1] = numb;
		}
	}
}

int		isnumber(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			count++;
		i++;
	}
	return (count);
}

void	valid(t_dataall *inf, int ac, char **av)
{
	int	i;
	int	count;

	i = 0;
	while (++i < ac)
	{
		count = 0;
		if (ft_strstr(av[i], ".cor"))
			count++;
		else if (ft_strequ(av[i], "-dump"))
		{
			if (isnumber(av[++i]))
				count++;
		}
		else if (ft_strequ(av[i], "-n"))
		{
			if (isnumber(av[++i]))
				count++;
		}
		if (count == 0)
			display();
	}
	flag_dump(inf, ac, av);
	flag_n(inf, ac, av);
}
