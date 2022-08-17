/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 18:24:47 by ljerk             #+#    #+#             */
/*   Updated: 2021/02/14 18:24:53 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void	skip_whitespaces(const char *row, t_parser *parser)
{
	while (is_whitespace(row[parser->col]))
		parser->col++;
}

void	skip_comment(t_parser *parser, const char *row)
{
	if (row[parser->col] == COMMENT_CHAR ||
			row[parser->col] == ALT_COMMENT_CHAR)
		while (row[parser->col] && row[parser->col] != '\n')
			parser->col++;
}
