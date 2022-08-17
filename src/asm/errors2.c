/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icanker <icanker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:54:57 by icanker           #+#    #+#             */
/*   Updated: 2021/02/20 14:54:58 by icanker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void	error_malloc(void)
{
	ft_printf("Malloc error\n", 2);
	exit(1);
}

void	error_fd(void)
{
	ft_printf("Fd error\n", 2);
	exit(1);
}

void	error_lex(t_parser *parser)
{
	ft_printf("Lexical error at %03u:%03u\n", parser->row, parser->col + 1);
	exit(1);
}

void	error_token(t_token *token)
{
	ft_printf("Unexpected token at %03u:%03u\n", token->row, token->col + 1);
	exit(1);
}
