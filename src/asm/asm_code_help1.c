/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_code_help1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icanker <icanker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:54:35 by icanker           #+#    #+#             */
/*   Updated: 2021/02/20 14:54:36 by icanker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void			int_to_bytecode(char *data, int pos,
									int value, size_t size)
{
	int			i;

	i = 0;
	while (size)
	{
		data[pos + size - 1] = (value >> i) & 0xFF;
		i += 8;
		size--;
	}
}

void			update_code_buff(t_parser *parser)
{
	parser->code_size += CHAMP_MAX_SIZE;
	if (!(parser->code = (char *)realloc(parser->code,
				((size_t)parser->code_size + MAX_STATEMENT_SIZE))))
		kill("Error: Initializing string error");
}

t_op			*get_op(char *name)
{
	unsigned	i;

	i = 0;
	while (i <= 15)
	{
		if (!ft_strcmp(g_op[i].name, name))
			return (&g_op[i]);
		i++;
	}
	return (NULL);
}

static int		get_arg_code(int type)
{
	if (type == T_DIR)
		return (DIR_CODE);
	return (type == T_REG) ? REG_CODE : IND_CODE;
}

void			update_types_code(int *types_code, int type, int arg_num)
{
	(*types_code) |= (get_arg_code(type) << 2 * (4 - arg_num - 1));
}
