/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 18:22:30 by ljerk             #+#    #+#             */
/*   Updated: 2021/02/14 18:22:32 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

int		check_name(char *filename)
{
	int len;

	len = ft_strlen(filename);
	return (filename && filename[len - 2] == '.'
		&& filename[len - 1] == 's') ? 1 : 0;
}

char	*make_out_file(char *filename, char *old_expansion, char *new_expansion)
{
	char *name;

	name = ft_strsub(filename, 0,
						ft_strlen(filename) - ft_strlen(old_expansion));
	if (!name || !(filename = ft_strjoin(name, new_expansion)))
		kill("Error: Initializing string error");
	ft_strdel(&name);
	return (filename);
}

void	assemble(char *filename)
{
	int			fd;
	t_parser	*parser;
	t_token		*cur;

	if ((fd = open(filename, O_RDONLY)) == -1)
		error_fd();
	parser = init_parser(fd);
	parse_asm(parser);
	cur = parser->tokens;
	asm_comment_name(parser, &cur);
	asm_code(parser, &cur);
	replace_tags(parser);
	filename = make_out_file(filename, ".s", ".cor");
	if ((fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0600)) == -1)
		kill("Error: Can\'t create file");
	write_bytes(fd, parser);
	free_asm_parser(&parser);
	free(filename);
}

void	print_help(void)
{
	ft_printf("Error in file openning. \nUsage: ./asm filename.s\n");
}

int		main(int argc, char **argv)
{
	if (argc == 2 && check_name(*(argv + 1)))
		assemble(*(argv + 1));
	else
		print_help();
	return (0);
}
