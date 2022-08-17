/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icanker <icanker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:12:24 by icanker           #+#    #+#             */
/*   Updated: 2021/02/20 19:12:25 by icanker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H

# define ASM_H

# include "../ft_printf/includes/ft_printf.h"
# include "op.h"
# include <errno.h>
# define MAX_STATEMENT_SIZE 14

typedef enum
{
	COMMAND,
	STRING,
	LABEL,
	OPERATOR,
	REGISTER,
	DIRECT,
	DIRECT_LABEL,
	INDIRECT,
	INDIRECT_LABEL,
	SEPARATOR,
	NEW_LINE,
	END
}	t_type;

static char				*g_type[] = {
	"COMMAND",
	"STRING",
	"LABEL",
	"OPERATOR",
	"REGISTER",
	"DIRECT",
	"DIRECT_LABEL",
	"INDIRECT",
	"INDIRECT_LABEL",
	"SEPARATOR",
	"NEW_LINE",
	"END"
};

typedef struct			s_token
{
	char				*data;
	t_type				type;
	unsigned int		row;
	unsigned int		col;
	struct s_token		*next;
}						t_token;

typedef struct			s_op
{
	char				*name;
	int					code;
	int					args_num;
	int					isargs;
	int					args_types[3];
	int					t_dir_size;
}						t_op;

typedef struct			s_tag
{
	unsigned			row;
	unsigned			col;
	int					pos;
	int					op_pos;
	size_t				size;
	struct s_tag		*next;
}						t_tag;

typedef struct			s_label
{
	char				*name;
	int					op_pos;
	t_tag				*tag;
	struct s_label		*next;
}						t_label;

typedef struct			s_parser
{
	int					fd;
	char				*name;
	char				*comment;
	unsigned int		row;
	unsigned int		col;
	t_token				*tokens;
	int					pos;
	int					op_pos;
	char				*code;
	int					code_size;
	t_label				*labels;
}						t_parser;

static t_op		g_op[16] =
{
	{
		.name = "live",
		.code = 0x01,
		.args_num = 1,
		.isargs = 0,
		.args_types = {T_DIR, 0, 0},
		.t_dir_size = 4,
	},
	{
		.name = "ld",
		.code = 0x02,
		.args_num = 2,
		.isargs = 1,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.t_dir_size = 4,
	},
	{
		.name = "st",
		.code = 0x03,
		.args_num = 2,
		.isargs = 1,
		.args_types = {T_REG, T_REG | T_IND, 0},
		.t_dir_size = 4,
	},
	{
		.name = "add",
		.code = 0x04,
		.args_num = 3,
		.isargs = 1,
		.args_types = {T_REG, T_REG, T_REG},
		.t_dir_size = 4,
	},
	{
		.name = "sub",
		.code = 0x05,
		.args_num = 3,
		.isargs = 1,
		.args_types = {T_REG, T_REG, T_REG},
		.t_dir_size = 4,
	},
	{
		.name = "and",
		.code = 0x06,
		.args_num = 3,
		.isargs = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.t_dir_size = 4,
	},
	{
		.name = "or",
		.code = 0x07,
		.args_num = 3,
		.isargs = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.t_dir_size = 4,
	},
	{
		.name = "xor",
		.code = 0x08,
		.args_num = 3,
		.isargs = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.t_dir_size = 4,
	},
	{
		.name = "zjmp",
		.code = 0x09,
		.args_num = 1,
		.isargs = 0,
		.args_types = {T_DIR, 0, 0},
		.t_dir_size = 2,
	},
	{
		.name = "ldi",
		.code = 0x0A,
		.args_num = 3,
		.isargs = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.t_dir_size = 2,
	},
	{
		.name = "sti",
		.code = 0x0B,
		.args_num = 3,
		.isargs = 1,
		.args_types = {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR},
		.t_dir_size = 2,
	},
	{
		.name = "fork",
		.code = 0x0C,
		.args_num = 1,
		.isargs = 0,
		.args_types = {T_DIR, 0, 0},
		.t_dir_size = 2,
	},
	{
		.name = "lld",
		.code = 0x0D,
		.args_num = 2,
		.isargs = 1,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.t_dir_size = 4,
	},
	{
		.name = "lldi",
		.code = 0x0E,
		.args_num = 3,
		.isargs = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.t_dir_size = 2,
	},
	{
		.name = "lfork",
		.code = 0x0F,
		.args_num = 1,
		.isargs = 0,
		.args_types = {T_DIR, 0, 0},
		.t_dir_size = 2,
	},
	{
		.name = "aff",
		.code = 0x10,
		.args_num = 1,
		.isargs = 1,
		.args_types = {T_REG, 0, 0},
		.t_dir_size = 4,
	}
};

t_parser				*init_parser(int fd);
void					parse_asm(t_parser *parser);
t_token					*init_token(t_parser *parser, t_type type);
void					add_token(t_token **chain, t_token *new);
void					skip_whitespaces(const char *row, t_parser *parser);
void					skip_comment(t_parser *parser, const char *row);
int						is_register(const char *arg);
int						is_delimiter(int c);
int						is_whitespace(int c);
void					kill(char *s);
int						get_row(const int fd, char **row);
void					parse_num(t_parser *parser, char *row,
							unsigned int start, t_token *token);
void					parse_string(t_parser *parser, char **row,
							unsigned start, t_token *token);
void					parse_symbols(t_parser *parser, char *row,
							unsigned start, t_token *token);
void					update_parser_position(t_parser *parser,
							const char *row);
char					*join_str(char **str1, char **str2);
char					*get_token_content(t_parser *parser,
							const char *row, unsigned start);

void					error_lex(t_parser *parser);
void					upgrade_row(char **row, char *ptr);

t_label					*init_label(char *name, int op_pos);
t_tag					*init_tag(t_parser *parser, t_token *token,
							size_t size);

void					asm_comment_name(t_parser *parser, t_token **cur);
void					asm_code(t_parser *parser, t_token **cur);
int						asm_arg(t_parser *parser, t_token **cur,
							t_op *op, int arg_num);
void					replace_tags(t_parser *file);
void					int_to_bytecode(char *data, int pos,
							int value, size_t size);
void					write_bytes(int fd, t_parser *parser);
void					update_types_code(int *types_code, int type,
							int arg_num);
t_op					*get_op(char *name);
void					update_code_buff(t_parser *parser);
void					add_label(t_label **list, t_label *new);
void					add_tag(t_tag **list, t_tag *new);
t_label					*find_label(t_label *list, char *name);

void					error_label(t_label *label);
void					error_token(t_token *token);
void					error_operator(t_token *token);
void					error_name(void);
void					error_comment(void);
void					error_arg_type(t_token *token);
void					free_asm_parser(t_parser **parser);
void					error_fd(void);
void					error_malloc(void);
char					*ft_strchrs(const char *s, int c);
unsigned long			ft_atoi32(const char *str);

#endif
