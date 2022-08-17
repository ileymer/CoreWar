/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icanker <icanker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:55:34 by icanker           #+#    #+#             */
/*   Updated: 2021/02/20 14:55:35 by icanker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void		add_token(t_token **chain, t_token *new)
{
	t_token	*cur;

	if (chain)
	{
		if (*chain)
		{
			cur = *chain;
			while (cur->next)
				cur = cur->next;
			if (cur->type == NEW_LINE && new->type == NEW_LINE)
				ft_memdel((void **)&new);
			else
				cur->next = new;
		}
		else
		{
			if (new->type == NEW_LINE)
				ft_memdel((void **)&new);
			else
				*chain = new;
		}
	}
}
