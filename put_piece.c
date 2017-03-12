#include "filler.h"

int		check_put_piece(t_bot bot, t_piece piece, t_coordinates yx)
{
	t_coordinates b;
	t_coordinates p;
	int count;
	char pc_player;

	if (t_bot.x < yx.x + piece.x || t_bot.y < yx.y + piece.y)
		return (0);
	pc_player = ft_strchr("oO", bot.player) ? 'x' : 'o';
	b.y = yx.y - 1;
	p.y = -1;
	count = 0;
	while (++b.y < bot.y && ++p.y < piece.y)
	{
		b.x = yx.x - 1;
		p.x = -1;
		while (++b.x < bot.x && ++p.x < piece.x)
		{
			if (piece.piece[p.y][p.x] == '.')
				continue ;
			else if (count > 1 || bot.map[b.y][b.x] == pc_player)
				return (0);
			count += bot.player == bot.map[b.y][b.x] || bot.player - 32
						 == bot.map[b.y][b.x] ? 1 : 0;
		}
	}
	return (count);
}

void 	wave_matrix(t_bot *bot, t_coordinates yx)
{
	int i; // y - row
	int j; // x - colum
	int d;

	d = 1;
	while ((yx.y + d < bot->y ^ yx.y - d >= 0) &&
			(yx.x + d < bot->x ^ yx.x - d >= 0))
	{
		j = bot->x - d - 1;
		i = bot->y - d;
		while (++j < (2 << d) + 1)
		{
			if (i >= 0 && j >= 0 && bot->map[i][j] == MAX_INT_MAP)
				bot->map[j][i] = d;
			if (i >= 0 && j >= 0 && j < bot->y && bot->map[j][i] == MAX_INT_MAP)
				bot->map[j][i] = d;
		}
		j = bot->x + d;
		i = bot->y + d;
		while ((2 << d) - j)
		{
			if (i < bot->y && j < bot->x && bot->map[i][j] == MAX_INT_MAP)
				bot->map[j][i] = d;
			if (i < bot->x && j < bot->y && bot->map[j][i] == MAX_INT_MAP)
				bot->map[j][i] = d;
			j--;
		}
	}
}

unsigned	sum_weight(t_bot bot, t_piece piece, t_coordinates yx)
{
	int i; // row  y
	int j; // colum x
	unsigned weight;

	weight = 0;
	i = yx.y - 1;
	while (++i < yx.y + piece.y)
	{
		j = yx.x - 1;
		while (++j < yx.x + piece.x)
			weight += bot.map[i][j] != -1 || bot.map[i][j] != MAX_INT_MAP ?
						  bot.wt_path[i][j] : 0;
	}
	return (weight);
}

t_coordinates	zero_coordinates(void)
{
	t_coordinates yx;

	yx.x = 0;
	yx.y = 0;
	return (yx);
}


t_coordinates	fight(t_bot *bot, t_piece piece)
{
	t_coordinates	yx;
	t_coordinates	res;
	unsigned		weight;
	unsigned		temp;

	yx.y = -1;
	res = zero_coordinates();
	weight = MAX_INT_MAP;
	while (++yx.y < bot->y)
	{
		yx.x = -1;
		while (++yx.x < bot->x)
		{
			if (!check_put_piece(bot, piece, yx))
				return (res);
			init_bot_wt_matrix(bot);
			wave_matrix(bot, yx);
			temp = sum_weight(bot, piece, yx);
			if ((weight > temp ? weight = temp : 0))
				res = yx;
		}
	}
	return (res);
}