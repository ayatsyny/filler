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
#include "./libft/ft_printf/ft_printf.h"
#include "./libft/get_next_line/get_next_line.h"
//#include "./libft/ftall.h"

struct		s_coordinates
{
	int 	x;
	int 	y;
}typedef	t_coordinates;

struct		s_bot
{
	t_coordinates *yx;
	char 	player;
	char 	**map;
	int 	**wt_path;
}typedef	t_bot;

struct		s_piece
{
	t_coordinates *yx;
	char 	**piece;
}typedef	t_piece;

t_coordinates	fight(t_bot *bot, t_piece piece);


void	init_bot_wt_matrix(t_bot *);
void	del_wave_matrix(int **matrix);

#endif
