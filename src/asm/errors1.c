/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 18:21:48 by ljerk             #+#    #+#             */
/*   Updated: 2021/02/14 18:21:50 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void	error_name(void)
{
	ft_printf("Champion name length > max length %u\n", NAME_LENGTH);
	exit(1);
}

void	error_comment(void)
{
	ft_printf("Champion comment length > max length %u\n", COMMENT_LENGTH);
	exit(1);
}

void	error_operator(t_token *token)
{
	ft_printf("Invalid operator \"%s\" at %03u:%03u\n",
		token->data, token->row, token->col + 1);
	exit(1);
}

void	error_arg_type(t_token *token)
{
	ft_printf("Invalid type of parameter at %03u:%03u\n",
				token->row, token->col + 1);
	exit(1);
}

void	error_label(t_label *label)
{
	t_tag	*tag;

	ft_printf("Undeclared label \"%s\" is taged at:\n", label->name);
	tag = label->tag;
	while (tag)
	{
		ft_printf("\t— %03u:%03u\n", tag->row, tag->col + 1);
		tag = tag->next;
	}
	exit(1);
}
