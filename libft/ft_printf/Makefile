# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/15 20:51:56 by ayatsyny          #+#    #+#              #
#    Updated: 2017/03/06 17:32:15 by ayatsyny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

G = gcc

FLAG = -Wall -Wextra -Werror

SRC = ft_printf.c \
    init_struct.c \
    parser.c \
    convert_to_data.c \
    itoa_base.c \
    write_specifier_cs.c \
    write_specifier_ox.c \
    write_specifier_pidu.c \
    count_letters.c \
    convert_to_char.c \
    fix_center_flag.c \
    check_flag_zero.c \
    init_memory.c

HDR = ft_printf.h

OBJ = $(SRC:.c=.o)

DEL = rm -f

all: $(NAME)

$(NAME) : $(OBJ)
		make -C ../libft
		ar -cru $(NAME) $(OBJ) ../libft/*.o
		ranlib $(NAME)
		@echo libftprintf.a is ALIVE!!!

%.o: %.c
		$(G) $(CFLAGS) -c -o $@ $<

clean:
		make clean -C ../libft
		$(DEL) $(OBJ)
		@echo OBJ_libftprintf is DEAD!!!

fclean: clean
		$(DEL) ../libft/libft.a
		rm -f $(NAME)
		@echo libftprintf.a is DESTROYED!!!

re: fclean all
		@echo ALL DAMM FPS is DESTROYED!!!

norm:
		make norm -C ../libft
		norminette $(SRC) $(HDR) | grep -B 1 "Error"
