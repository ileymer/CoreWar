/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icanker <icanker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:54:23 by icanker           #+#    #+#             */
/*   Updated: 2021/02/20 14:56:14 by icanker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

static int		get_type(t_type type)
{
	if (type == DIRECT || type == DIRECT_LABEL)
		return (T_DIR);
	else if (type == INDIRECT || type == INDIRECT_LABEL)
		return (T_IND);
	else if (type == REGISTER)
		return (T_REG);
	else
		return (0);
}

static void		asm_tags(t_parser *parser, t_token *cur, t_op *op)
{
	t_label		*label;
	char		*name;
	unsigned	start;
	size_t		size;

	start = (cur->type == DIRECT_LABEL) ? 2 : 1;
	size = (cur->type == DIRECT_LABEL) ? op->t_dir_size : IND_SIZE;
	if (!(name = ft_strsub(cur->data,
						start, ft_strlen(cur->data) - start)))
		kill("Error: Initializing string error");
	if (!(label = find_label(parser->labels, name)))
	{
		label = init_label(name, -1);
		add_label(&(parser->labels), label);
	}
	ft_strdel(&name);
	add_tag(&label->tag, init_tag(parser, cur, size));
	parser->pos += size;
}

static void		asm_num(t_parser *parser, t_token *cur, t_op *op)
{
	unsigned	start;
	size_t		size;

	start = (cur->type == DIRECT) ? 1 : 0;
	size = (cur->type == DIRECT) ? op->t_dir_size : IND_SIZE;
	int_to_bytecode(parser->code, parser->pos,
						ft_atoi32(&cur->data[start]), size);
	parser->pos += size;
}

static void		asm_register(t_parser *parser, t_token *cur)
{
	int_to_bytecode(parser->code,
					parser->pos,
					ft_atoi(&cur->data[1]),
					1);
	parser->pos += 1;
}

int				asm_arg(t_parser *parser, t_token **cur, t_op *op, int arg_num)
{
	int	type;

	type = get_type((*cur)->type);
	if (!(op->args_types[arg_num] & type))
		error_arg_type(*cur);
	if ((*cur)->type == INDIRECT || (*cur)->type == DIRECT)
		asm_num(parser, *cur, op);
	else if ((*cur)->type == INDIRECT_LABEL || (*cur)->type == DIRECT_LABEL)
		asm_tags(parser, *cur, op);
	else
		asm_register(parser, *cur);
	return (type);
}
