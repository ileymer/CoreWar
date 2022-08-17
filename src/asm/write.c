/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icanker <icanker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:55:39 by icanker           #+#    #+#             */
/*   Updated: 2021/02/20 14:55:41 by icanker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"
#include <fcntl.h>
#include <unistd.h>

void		write_bytes(int fd, t_parser *parser)
{
	int		len;
	int		pos;
	char	*bytecode;

	pos = 0;
	len = 4 + NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4 + parser->pos;
	if (!(bytecode = ft_strnew((size_t)len)))
		kill("Error: Initializing string error");
	int_to_bytecode(bytecode, pos, COREWAR_EXEC, 4);
	pos += 4;
	ft_memcpy(&bytecode[pos], parser->name, ft_strlen(parser->name));
	pos += NAME_LENGTH + 4;
	int_to_bytecode(bytecode, pos, parser->pos, 4);
	pos += 4;
	ft_memcpy(&bytecode[pos], parser->comment, ft_strlen(parser->comment));
	pos += COMMENT_LENGTH + 4;
	ft_memcpy(&bytecode[pos], parser->code, (size_t)parser->pos);
	write(fd, bytecode, (size_t)len);
	free(bytecode);
}
