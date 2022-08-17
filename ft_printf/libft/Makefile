# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/07 20:46:48 by ljerk             #+#    #+#              #
#    Updated: 2020/09/04 18:58:50 by ljerk            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_lstdelone.c ft_putendl.c ft_strequ.c ft_strrchr.c ft_lstiter.c \
ft_putendl_fd.c ft_striter.c ft_strrev.c ft_abs.c ft_lstmap.c ft_putnbr.c \
ft_striteri.c ft_strsplit.c ft_atoi.c ft_lstnew.c ft_putnbr_fd.c ft_strjoin.c \
ft_strstr.c ft_bzero.c ft_memalloc.c ft_putstr.c ft_strlcat.c ft_strsub.c \
ft_isalnum.c ft_memccpy.c ft_putstr_fd.c ft_strlen.c ft_strtrim.c ft_isalpha.c \
ft_memchr.c ft_sqrt.c ft_strmap.c ft_swap.c ft_isascii.c ft_memcmp.c \
ft_strcat.c ft_strmapi.c ft_tolower.c ft_isdigit.c ft_memcpy.c ft_strchr.c\
ft_strncat.c ft_toupper.c ft_isprint.c ft_memdel.c ft_strclr.c ft_strncmp.c \
ft_itoa.c ft_memmove.c ft_strcmp.c ft_strncpy.c ft_lstadd.c \
ft_memset.c ft_strcpy.c ft_strnequ.c ft_lstadd_end.c ft_putchar.c \
ft_strdel.c ft_strnew.c ft_lstdel.c ft_putchar_fd.c ft_strdup.c ft_strnstr.c \
ft_freestrarr.c ft_lstfree.c get_next_line.c

OBJ = $(SRC:.c=.o)

NAME = libft.a

OPTION = -I libft.h -c

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c libft.h
	@gcc $(FLAG) $(OPTION) $<

clean:
	@/bin/rm -f $(OBJ)
	
fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
