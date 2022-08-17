/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_code.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icanker <icanker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:54:47 by icanker           #+#    #+#             */
/*   Updated: 2021/02/20 14:54:48 by icanker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

static void		asm_label(t_parser *parser, t_token **cur)
{
	t_label	*label;
	char	*name;

	if (!(name = ft_strsub((*cur)->data, 0, ft_strlen((*cur)->data) - 1)))
		kill("Error: Initializing string error");
	if (!(label = find_label(parser->labels, name)))
		add_label(&(parser->labels), init_label(name, parser->op_pos));
	if (label && label->op_pos == -1)
		label->op_pos = parser->pos;
	ft_strdel(&name);
}

static int		asm_args(t_parser *parser, t_token **cur, t_op *op)
{
	int		arg_num;
	int		types_code;
	int		type;

	arg_num = 0;
	types_code = 0;
	while (arg_num < op->args_num)
	{
		if ((*cur)->type >= REGISTER && (*cur)->type <= INDIRECT_LABEL)
		{
			type = asm_arg(parser, cur, op, arg_num);
			update_types_code(&types_code, type, arg_num);
			(*cur) = (*cur)->next;
		}
		else
			error_token((*cur));
		if (arg_num++ != op->args_num - 1)
		{
			if ((*cur)->type != SEPARATOR)
				error_token((*cur));
			(*cur) = (*cur)->next;
		}
	}
	return (types_code);
}

static void		asm_operator(t_parser *parser, t_token **cur)
{
	t_op	*op;
	int		types_code;

	if ((op = get_op((*cur)->data)))
	{
		parser->code[parser->pos++] = op->code;
		(*cur) = (*cur)->next;
		if (op->isargs)
			parser->pos++;
		types_code = asm_args(parser, cur, op);
		if (op->isargs)
			parser->code[parser->op_pos + 1] = types_code;
	}
	else
		error_operator((*cur));
}

void			asm_code(t_parser *parser, t_token **cur)
{
	while ((*cur)->type != END)
	{
		if (parser->pos >= parser->code_size)
			update_code_buff(parser);
		parser->op_pos = parser->pos;
		if ((*cur)->type == LABEL)
		{
			asm_label(parser, cur);
			(*cur) = (*cur)->next;
		}
		if ((*cur)->type == OPERATOR)
			asm_operator(parser, cur);
		if ((*cur)->type == NEW_LINE)
			(*cur) = (*cur)->next;
		else
			error_token((*cur));
	}
}
