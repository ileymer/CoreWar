/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 18:20:02 by ljerk             #+#    #+#             */
/*   Updated: 2021/02/14 18:55:54 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void	parse_symbols(t_parser *parser,
					char *row,
					unsigned start,
					t_token *token)
{
	unsigned col;

	token->col = start;
	col = parser->col;
	while (row[parser->col]
		&& ft_strchr(LABEL_CHARS, row[parser->col]))
		parser->col++;
	if ((parser->col - col) && row[parser->col] == LABEL_CHAR
		&& ++parser->col)
	{
		token->data = get_token_content(parser, row, start);
		token->type = LABEL;
		add_token(&parser->tokens, token);
	}
	else if ((parser->col - col) && is_delimiter(row[parser->col]))
	{
		token->data = get_token_content(parser, row, start);
		if (token->type == INDIRECT)
			token->type = (is_register(token->data)) ? REGISTER : OPERATOR;
		add_token(&parser->tokens, token);
	}
	else
		error_lex(parser);
}

char	*join_str(char **str1, char **str2)
{
	char *result;

	if (!(result = ft_strjoin(*str1, *str2)))
		kill("Error: Initializing string error");
	ft_strdel(str1);
	ft_strdel(str2);
	return (result);
}

void	parse_num(t_parser *parser, char *row, unsigned start, t_token *token)
{
	unsigned int col;

	token->col = start;
	if (row[parser->col] == '-')
		parser->col++;
	col = parser->col;
	while (ft_isdigit(row[parser->col]))
		parser->col++;
	if ((parser->col - col)
		&& (token->type == DIRECT || is_delimiter(row[parser->col])))
	{
		token->data = get_token_content(parser, row, start);
		add_token(&parser->tokens, token);
	}
	else if (token->type != DIRECT)
	{
		parser->col = start;
		parse_symbols(parser, row, start, token);
	}
	else
		error_lex(parser);
}

void	update_parser_position(t_parser *parser, const char *row)
{
	unsigned i;

	i = ++(parser->col);
	while (row[i] && row[i] != '\"')
	{
		if (row[i] == '\n')
		{
			parser->row++;
			parser->col = 0;
		}
		else
			parser->col++;
		i++;
	}
}

void	parse_string(t_parser *parser, char **row,
							unsigned start, t_token *token)
{
	char	*end;
	ssize_t	size;
	char	*str;

	token->col = start;
	size = 1;
	while (!(end = ft_strchr(&((*row)[start + 1]), '\"'))
		&& (size = get_row(parser->fd, &str)) > 0)
		*row = join_str(row, &str);
	update_parser_position(parser, *row);
	if (size == 0)
		error_lex(parser);
	if (size == -1)
		kill("Error: Can\'t read file");
	if (!(token->data = ft_strsub(*row, start, end + 1 - &((*row)[start]))))
		kill("Error: Initializing string error");
	if (end - parser->col != *row)
		upgrade_row(row, end - parser->col);
	parser->col++;
	add_token(&parser->tokens, token);
}
