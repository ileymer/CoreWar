/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icanker <icanker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:55:08 by icanker           #+#    #+#             */
/*   Updated: 2021/02/20 14:55:11 by icanker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

static void	free_tokens(t_token **list)
{
	t_token	*cur;
	t_token	*del;

	cur = *list;
	while (cur)
	{
		del = cur;
		cur = cur->next;
		ft_strdel(&(del->data));
		ft_memdel((void **)&del);
	}
}

static void	free_tags(t_tag **list)
{
	t_tag	*cur;
	t_tag	*del;

	cur = *list;
	while (cur)
	{
		del = cur;
		cur = cur->next;
		ft_memdel((void **)&del);
	}
}

static void	free_labels(t_label **list)
{
	t_label	*cur;
	t_label	*del;

	cur = *list;
	while (cur)
	{
		del = cur;
		cur = cur->next;
		ft_strdel(&(del->name));
		free_tags(&(del->tag));
		ft_memdel((void **)&del);
	}
}

void		free_asm_parser(t_parser **parser)
{
	free_labels(&((*parser)->labels));
	free_tokens(&((*parser)->tokens));
	ft_strdel(&((*parser)->name));
	ft_strdel(&((*parser)->comment));
	ft_strdel(&((*parser)->code));
	ft_memdel((void **)parser);
}
