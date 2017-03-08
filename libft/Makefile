# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/15 20:51:56 by ayatsyny          #+#    #+#              #
#    Updated: 2017/03/06 21:04:34 by ayatsyny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftall.a

LIBFT = libft.a
LBP = ./libft/
PRINTF = ./ft_printf/
GNL = ./get_next_line/
G = gcc


CFLAGS = -Wall -Wextra -Werror

SRC = $(./libft/*.c) $(./get_next_line/*.c) $(./ft_printf/*.c)

OBJ = $(./libft/*.o) $(./get_next_line/*.o) $(./ft_printf/*.o)


OBJS = $(SRC:.c=.o)

HDR = ftall.h

DEL = rm -f

all: $(NAME)

$(NAME) : $(OBJS)
		make -C libft
		make -C ft_printf
	#	ar -cru $(LBP) $(OBJS), $(PRINTF)$(OBJS), ./get_next_line/$(OBJS)
#		LIST_FILE = find -name '*.c' -o -name '*.o'
		ar -cru $(NAME) $(OBJS)
		ranlib $(NAME)
		@echo libftall.a is CREATED!!!

$(OBJS): $(HDR)

%.o: %.c
		$(G) $(CFLAGS) -c -o $@ $<

clean:
		find . -name \*.o -type f -delete
		@echo objects_files is DELETE!!!

fclean: clean
		find . -name \*.a -type f -delete
		@echo libftall.a is DELETE!!!

re: fclean all
		@echo ALL DAMM FPS is DESTROYED!!!

norm:
		make norm -C ./get_next_line
		make norm -C ./ft_printf
