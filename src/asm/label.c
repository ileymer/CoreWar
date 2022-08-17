/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icanker <icanker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:55:26 by icanker           #+#    #+#             */
/*   Updated: 2021/02/20 14:55:27 by icanker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void		add_label(t_label **list, t_label *new)
{
	t_label	*cur;

	if (list)
	{
		if (*list)
		{
			cur = *list;
			while (cur->next)
				cur = cur->next;
			cur->next = new;
		}
		else
			*list = new;
	}
}

void		add_tag(t_tag **list, t_tag *new)
{
	t_tag	*cur;

	if (list)
	{
		if (*list)
		{
			cur = *list;
			while (cur->next)
				cur = cur->next;
			cur->next = new;
		}
		else
			*list = new;
	}
}

t_label		*find_label(t_label *list, char *name)
{
	t_label	*label;

	label = list;
	while (label)
	{
		if (!ft_strcmp(label->name, name))
			return (label);
		label = label->next;
	}
	return (label);
}

void		replace_tags(t_parser *file)
{
	t_label		*label;
	t_tag		*tag;

	label = file->labels;
	while (label)
	{
		if (label->op_pos == -1)
			error_label(label);
		else
		{
			tag = label->tag;
			while (tag)
			{
				int_to_bytecode(file->code, tag->pos,
									label->op_pos - tag->op_pos, tag->size);
				tag = tag->next;
			}
		}
		label = label->next;
	}
}
