/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 16:11:52 by dgeonosi          #+#    #+#             */
/*   Updated: 2021/02/21 18:41:08 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "../ft_printf/includes/ft_printf.h"

# define REG				1
# define IND				2
# define DIR				4

# define REG_CODE			1
# define DIR_CODE			2
# define IND_CODE			3

# define MAX_PLAYERS		4
# define MEM_SIZE			(4*1024)
# define IDX_MOD			(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE		(MEM_SIZE / 6)
# define REG_NUMBER			16

# define CYCLE_TO_DIE		1536
# define CYCLE_DELTA		50
# define NBR_LIVE			21
# define MAX_CHECKS			10

# define PROG_NAME_LENGTH	(128)
# define COMMENT_LENGTH		(2048)
# define COREWAR_EXEC_MAGIC	0xea83f3

typedef struct			s_cursor
{
	int					pc;
	int					carry;
	int					pl_id;
	unsigned int		reg[REG_NUMBER + 1];
	int					command;
	int					waiting_cycle;
	int					numb;
	int					cycle_live;
	struct s_cursor		*next;
}						t_cursor;

typedef struct			s_player
{
	char				name[PROG_NAME_LENGTH + 1];
	char				comment[COMMENT_LENGTH + 1];
	unsigned char		exec_code[CHAMP_MAX_SIZE + 1];
	unsigned int		size;
	int					id;
	int					numb;
	int					alive;
}						t_player;

typedef struct			s_dataall
{
	t_player			p_mas[4];
	int					step;
	int					p_kol;
	int					last;
	int					cycles_to_die;
	int					cycles;
	int					curs_qty;
	int					number;
	t_cursor			*cursors;
	unsigned char		map[MEM_SIZE + 1];
	int					dump;
	int					dump_valid;
	int					lives;
	int					n[4];
}						t_dataall;

void					last_live(t_dataall *inf, int num);
void					algo(t_dataall *inf);
int						get_value(t_dataall *inf, int place, int len);
void					make_cursor(int pl_numb, t_dataall *inf, int pos);
void					del_cursors(t_dataall *inf);
void					err_exit(char *str);
void					run_live(t_cursor *curs, t_dataall *inf, int cycles);
void					run_zjmp(t_cursor *curs, t_dataall *inf, int cycles);
void					run_fork(t_cursor *curs, t_dataall *inf, int cycles);
void					run_lfork(t_cursor *curs, t_dataall *inf, int cycles);
void					run_aff(t_cursor *curs, t_dataall *inf, int cycles);
void					exe_dump(t_dataall *inf);
void					write_map(t_dataall *inf, int pos, int src, size_t len);
void					del_all(t_dataall *inf);
void					output_win(t_dataall *inf);
void					check_cursor(t_dataall *inf);
void					distribc(t_cursor *curs, t_dataall *inf);
void					distribc_continued(t_cursor *curs, t_dataall *inf);
void					run_ld(t_cursor *curs, t_dataall *inf, int cycles);
void					run_and(t_cursor *curs, t_dataall *inf, int cycles);
int						end_arg(t_cursor *curs, t_dataall *inf, int targ[5],
						int place);
void					run_or(t_cursor *curs, t_dataall *inf, int cycles);
void					run_xor(t_cursor *curs, t_dataall *inf, int cycles);
void					run_add(t_cursor *curs, t_dataall *inf, int cycles);
void					run_sub(t_cursor *curs, t_dataall *inf, int cycles);
void					run_ldi(t_cursor *curs, t_dataall *inf, int cycles);
void					run_sti(t_cursor *curs, t_dataall *inf, int cycles);
void					run_lldi(t_cursor *curs, t_dataall *inf, int cycles);
void					run_lld(t_cursor *curs, t_dataall *inf, int cycles);
int						arg_one(unsigned int num);
int						arg_two(unsigned int num);
int						arg_three(unsigned int num);
int						arg_size(int num, int f);
int						memory_belay(int place);
int						check_reg(int n);
void					make_cursor2(t_dataall *inf, int pos, t_cursor *curs);
void					check_place2(t_cursor *curs);
int						to_wait(t_cursor *curs, int cycles);
void					run_st(t_cursor *curs, t_dataall *inf, int cycles);
int						ft_abs(int n);
void					display(void);
void					free_cursor(t_dataall *inf);
void					valid(t_dataall *inf, int ac, char **av);
void					init_champs(t_dataall *inf, int ac, char **av);
void					*ft_memalloc(size_t size);
void					*ft_memcpy(void *dest, const void *src, size_t n);
int						ft_atoi(const char *str);
void					ft_bzero(void *s, size_t n);
int						ft_strequ(char const *s1, char const *s2);
char					*ft_strstr(const char *str, const char *to_find);
size_t					ft_strlen(const char *str);
int						ft_strcmp(const char *s1, const char *s2);

#endif
