NAME_ASM = asm
NAME_VM = corewar

.PHONY: all clean fclean re

SRC_ASM := 	src/asm/asm.c src/asm/asm_arg.c src/asm/asm_beg.c src/asm/asm_code.c \
			src/asm/asm_code_help1.c src/asm/asm_code_help2.c \
            src/asm/errors1.c src/asm/errors2.c src/asm/free_parser.c src/asm/help1.c \
			src/asm/help2.c src/asm/init.c src/asm/label.c src/asm/parser_asm.c \
            src/asm/parser_funcs.c src/asm/row_get.c src/asm/token.c src/asm/write.c

SRC_VM	:=	src/vm/alg.c src/vm/act_cursor.c src/vm/menu.c src/vm/fun12_fork.c \
			src/vm/fun10_ldi.c src/vm/fun1_live.c src/vm/fun14_lldi.c src/vm/fun3_st.c \
			src/vm/fun5_sub.c src/vm/fun9_zjmp.c src/vm/init_champs.c src/vm/print_err.c \
			src/vm/fun4_add.c src/vm/fun6_and.c src/vm/fun2_ld.c src/vm/fun15_lfork.c \
			src/vm/fun13_lld.c src/vm/fun7_or.c src/vm/fun11_sti.c src/vm/fun8_xor.c \
			src/vm/corewar.c src/vm/fun16_aff.c src/vm/tools.c src/vm/lib.c src/vm/lib2.c \
			src/vm/distribc.c src/vm/valid.c

LIB_DIR = ./ft_printf/
LIBFT = $(LIB_DIR)libftprintf.a

FLAGS = -Wall -Wextra -Werror

OBJ_ASM = $(patsubst %.c,%.o,$(SRC_ASM))
OBJ_VM = $(patsubst %.c,%.o,$(SRC_VM))

INCLUDE_ASM = ./includes/asm.h
INCLUDE_VM = ./includes/vm.h

all: $(NAME_ASM) $(NAME_VM)

%.o: %.c $(INCLUDE_ASM) $(INCLUDE_VM)

$(NAME_ASM): $(LIBFT) $(OBJ_ASM)
	gcc -o $(NAME_ASM) $(FLAGS) $(OBJ_ASM) $(LIBFT)

$(NAME_VM): $(LIBFT) $(OBJ_VM) 
	gcc -o $(NAME_VM) $(FLAGS) $(OBJ_VM) $(LIBFT)

$(LIBFT):
	$(MAKE) -C $(LIB_DIR)

clean:
	@$(MAKE) clean -C $(LIB_DIR)
	@/bin/rm -f $(OBJ_ASM) $(OBJ_VM)

fclean: clean
	@$(MAKE) fclean -C $(LIB_DIR)
	@/bin/rm -f $(NAME_ASM) $(NAME_VM)
	
re: fclean all