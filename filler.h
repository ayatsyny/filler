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
#include <stdio.h>
#include "./libft/ft_printf/ft_printf.h"
#include "./libft/get_next_line/get_next_line.h"
//#include "./libft/ftall.h"

struct		s_bot
{
	int 	x;
	int 	y;
	char 	player;
	char 	**map;
}typedef	t_bot;

struct		s_piece
{
	int 	x;
	int		y;
	char 	**piece;
}typedef	t_piece;

struct		s_coordinates
{
	int 	x;
	int 	y;
}typedef	t_coordinates;


#endif
