/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_cursor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:17:28 by dgeonosi          #+#    #+#             */
/*   Updated: 2021/02/21 18:37:05 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	check_cursor(t_dataall *inf)
{
	t_cursor	*curs;
	int			i;

	del_cursors(inf);
	curs = inf->cursors;
	while (curs)
	{
		if (curs->cycle_live > 0)
			curs->cycle_live = 0;
		curs = curs->next;
	}
	i = -1;
	while (++i < 4)
		inf->p_mas[i].alive = 0;
}

void	del_cursors(t_dataall *inf)
{
	t_cursor	*tmp;
	t_cursor	*i;

	while (inf->cursors && ((inf->cycles - inf->cycles_to_die) >=
		inf->cursors->cycle_live))
	{
		tmp = inf->cursors;
		inf->cursors = inf->cursors->next;
		free(tmp);
		inf->curs_qty--;
	}
	i = inf->cursors;
	while (i && i->next)
	{
		if (((inf->cycles - inf->cycles_to_die) >= i->next->cycle_live))
		{
			tmp = i->next;
			i->next = tmp->next;
			free(tmp);
			inf->curs_qty--;
		}
		else
			i = i->next;
	}
}

void	make_cursor(int pl_id, t_dataall *inf, int place)
{
	t_cursor	*cursor;

	place = memory_belay(place);
	if (!(cursor = (t_cursor*)ft_memalloc(sizeof(t_cursor))))
	{
		del_all(inf);
		exit(1);
	}
	if (!inf->cursors)
	{
		inf->cursors = cursor;
		cursor->next = NULL;
	}
	else
	{
		cursor->next = inf->cursors;
		inf->cursors = cursor;
	}
	cursor->numb = ++(inf->number);
	cursor->pc = place;
	cursor->pl_id = pl_id;
	cursor->cycle_live = inf->cycles;
	cursor->command = inf->map[place];
}

void	make_cursor2(t_dataall *inf, int place, t_cursor *curs)
{
	t_cursor	*cursor;

	place = memory_belay(place);
	if (!(cursor = (t_cursor*)ft_memalloc(sizeof(t_cursor))))
	{
		del_all(inf);
		exit(1);
	}
	if (!inf->cursors)
	{
		inf->cursors = cursor;
		cursor->next = NULL;
	}
	else
	{
		cursor->next = inf->cursors;
		inf->cursors = cursor;
	}
	cursor->numb = ++(inf->number);
	cursor->pc = place;
	cursor->pl_id = curs->pl_id;
	cursor->cycle_live = curs->cycle_live;
	cursor->command = inf->map[place];
}
