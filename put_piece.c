//
// Created by Andriy Yatsynyak on 3/8/17.
//

#include "filler.h"

int		check_put_piece(t_bot *bot, t_piece *piece, t_coordinates *yx)
{
	int i;
	int j;
	int k;
	int kk;



}

t_cordinates	start_piece(t_piece *piece)
{
	t_coordinates res;
	int i;
	int j;

	i = -1;
	res.x = 0;
	res.y = 0;
	while (++i < piece->y)
	{
		j = -1;
		while (++j < piece->x)
			if (piece->piece[i][j] == '*')
				{
					res.y = i;
					res.x = j;
					return (res);
				}
	}
	return (res);
}

int		ckeck_falig_piece(t_bot bot, t_piece piece)
{
	if (piece.x > bot.x || piece.y > bot.y)
		return (1);
	return (0);
}