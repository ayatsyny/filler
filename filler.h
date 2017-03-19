/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 21:05:12 by ayatsyny          #+#    #+#             */
/*   Updated: 2017/03/06 21:06:05 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H
#define MAX_INT_MAP 9999
#include <stdio.h>
#include "./libft/libft.h"
#include "./libft/get_next_line.h"

typedef struct		s_coordinates
{
	int 	x;
	int 	y;
}	t_coordinates;

typedef struct		s_bot
{
	t_coordinates yx;
	char		player;
	char		pc_player;
	unsigned	pc_elemts;
	int			pc_game_over;
	char		**map;
	int			**wt_path;
}	t_bot;

typedef struct	s_piece
{
	t_coordinates yx;
	char 	**map;
}	t_piece;

t_coordinates	fight(t_bot *bot, t_piece piece);
void	init_bot_wt_matrix(t_bot *bot);

void	del_matrix_str(char **matrix);
void	del_matrix_int(int **matrix);
t_coordinates	zero_coordinates(void);

unsigned    count_pc_elemets(t_bot *bot);

#endif
