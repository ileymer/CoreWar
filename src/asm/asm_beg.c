/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_beg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icanker <icanker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:54:29 by icanker           #+#    #+#             */
/*   Updated: 2021/02/20 14:54:30 by icanker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

static void	asm_name(t_parser *parser, t_token **cur)
{
	if ((*cur)->type == STRING)
	{
		if (!(parser->name = ft_strsub((*cur)->data,
			1, ft_strlen((*cur)->data) - 2)))
			kill("Error: Initializing string error");
		if (ft_strlen(parser->name) > NAME_LENGTH)
			error_name();
		(*cur) = (*cur)->next;
	}
	else
		error_token(*cur);
}

static void	asm_comment(t_parser *parser, t_token **cur)
{
	if ((*cur)->type == STRING)
	{
		if (!(parser->comment = ft_strsub((*cur)->data,
									1, ft_strlen((*cur)->data) - 2)))
			kill("Error: Initializing string error");
		if (ft_strlen(parser->comment) > COMMENT_LENGTH)
			error_comment();
		(*cur) = (*cur)->next;
	}
	else
		error_token(*cur);
}

void		asm_comment_name(t_parser *parser, t_token **cur)
{
	while (!parser->name || !parser->comment)
	{
		if ((*cur)->type == COMMAND
				&& !ft_strcmp((*cur)->data, NAME_CMD_STRING)
				&& !parser->name)
		{
			(*cur) = (*cur)->next;
			asm_name(parser, cur);
			if ((*cur)->type != NEW_LINE)
				error_token(*cur);
		}
		else if ((*cur)->type == COMMAND
					&& !ft_strcmp((*cur)->data, COMMENT_CMD_STRING)
					&& !parser->comment)
		{
			(*cur) = (*cur)->next;
			asm_comment(parser, cur);
			if ((*cur)->type != NEW_LINE)
				error_token(*cur);
		}
		else
			error_token(*cur);
		(*cur) = (*cur)->next;
	}
}
