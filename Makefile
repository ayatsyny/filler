# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/15 20:21:23 by ayatsyny          #+#    #+#              #
#    Updated: 2017/03/15 21:23:25 by ayatsyny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler
LIBFT = libft.a
LIBFTPATH = ./libft
FLAGS = -Wall -Wextra -Werror

SRCS = pars_data.c \
	   put_piece.c \
	   del_matrix.c

HDR = filler.h

OBJS = $(SRCS:.c=.o)

.PNONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFTPATH)
	gcc $^ -o $(NAME) $(LIBFTPATH)/$(LIBFT)

.c.o: $(SRCS)
	gcc $(FLAGS) -c $<

clean:
		make clean -C $(LIBFTPATH)
		rm -f $(OBJS)
		@echo OBJ_files is DEAD!!!

fclean: clean
		make fclean -C $(LIBFTPATH)
		rm -f $(NAME)
		@echo lib_files is DESTROYED!!!

re: fclean all
		@echo ALL DAMM is DESTROYED!!!

norm:
		make norm -C $(LIBFTPATH)
		norminette $(SRC) $(HDR) | grep -B 1 "Error"
