#include "filler.h"
#include <stdio.h>

//int		check_put_piece(t_bot bot, t_piece piece, t_coordinates yx)
//{
//	t_coordinates b;
//	t_coordinates p;
//	int count;
//	char pc_player;
//
//	if (bot.yx.x < yx.x + piece.yx.x || bot.yx.y < yx.y + piece.yx.y)
//		return (0);
//	pc_player = ft_strchr("oO", bot.player) ? 'x' : 'o';
//	b.x = yx.x - 1;
//	p.x = -1;
//	count = 0;
//	while (++b.x < bot.yx.x && ++p.x < piece.yx.x)
//	{
//		b.y = yx.y - 1;
//		p.y = -1;
//		while (++b.y < bot.yx.y && ++p.y < piece.yx.y)
//		{
//			if (piece.map[p.x][p.y] == '.')
//				continue ;
//			else if (count > 1 || bot.map[b.x][b.y] == pc_player)
//				return (0);
//			count += bot.player == bot.map[b.x][b.y] || bot.player - 32
//						 == bot.map[b.x][b.y] ? 1 : 0;
//		}
//	}
//	return (count);
//}

void	write_weither_matrix(t_bot bot)
{
	for(int i = 0; i < bot.yx.x; i++)
	{
		for(int j = 0; j < bot.yx.y; j++)
			printf("\t%4d ", bot.wt_path[i][j]);
		printf("\n");
	}
	printf("\n\n\n");
}

int		check_put_piece(t_bot bot, t_piece piece, t_coordinates b)
{
	t_coordinates p;
	int count;
	char pc_player;

	if (bot.yx.x < b.x + piece.yx.x || bot.yx.y < b.y + piece.yx.y)
		return (0);
	pc_player = ft_strchr("oO", bot.player) ? 'x' : 'o';
	p.x = -1;
	count = 0;
	while (++p.x < piece.yx.x)
	{
		b.x += p.x;
		p.y = -1;
		while (++p.y < piece.yx.y)
		{
			b.y += p.y;
			if (piece.map[p.x][p.y] == '.')
				continue ;
			else if (b.x > bot.yx.x || b.y > bot.yx.y || count > 1
					 || bot.map[b.x][b.y] == pc_player)
				return (0);
			count += bot.player == bot.map[b.x][b.y] || bot.player - 32
						 == bot.map[b.x][b.y] ? 1 : 0;
		}
	}
	return (count == 1 ? 1 : 0);
}

//void 	wave_matrix(t_bot *bot, t_coordinates yx)
//{
//	int i; // y - row
//	int j; // x - colum
//	int d;
//
//	d = 1;
//
////	while ((yx.y + d < bot->yx.y ^ yx.y - d >= 0) ||
////			(yx.x + d < bot->yx.x ^ yx.x - d >= 0))
//	while (d < M(yx.x, A(bot->yx.x - yx.x)) || d < M(yx.y, A(bot->yx.y - yx.y)))
//	{
//		j = bot->yx.x - d - 1;
//		i = bot->yx.y - d;
//		while (++j < (2 << d) + 1)
//		{
//			if (i >= 0 && j >= 0 && bot->wt_path[i][j] == MAX_INT_MAP)
//				bot->wt_path[j][i] = d;
//			if (i >= 0 && j >= 0 && j < bot->yx.y && bot->wt_path[j][i] == MAX_INT_MAP)
//				bot->wt_path[j][i] = d;
//		}
//		j = bot->yx.x + d;
//		i = bot->yx.y + d;
//		while ((2 << d) - j)
//		{
//			if (i < bot->yx.y && j < bot->yx.x && bot->wt_path[i][j] == MAX_INT_MAP)
//				bot->wt_path[j][i] = d;
//			if (i < bot->yx.x && j < bot->yx.y && bot->wt_path[j][i] == MAX_INT_MAP)
//				bot->wt_path[j][i] = d;
//			j--;
//		}
//	}
//}

void	wave_matrix(t_bot	*bot, t_coordinates yx)
{
	int i;
	int j;
	int d;
	int k;
	int rt_end;
	int lf_end;

	d = 1;
	while (d < M(yx.x, A(bot->yx.x - yx.x)) || d < M(yx.y, A(bot->yx.y - yx.y)))
	{
		i = yx.x - d;
		j = yx.y - d - 1;
		lf_end = 2 << (d - 1);
		k = 0;
		printf("\n \t test: \t %d\n", d);
		while (++j <= lf_end + 1)
		{
			if (i >= 0 && j >= 0 && i < bot->yx.x && bot->wt_path[i][j] == MAX_INT_MAP)
			bot->wt_path[i][j] = d;
			if (i >= 0 && j >= 0 && j < bot->yx.y && bot->wt_path[i + k][yx.y - d] == MAX_INT_MAP)
				bot->wt_path[i + k][yx.y - d] = d;
//			printf("\n lf_end\n");
//			write_weither_matrix(*bot);
//			sleep(3);
			k++;
		}
		j = yx.y + d;
		i = yx.x + d;
		k = 0;
		rt_end = (2 << (d - 1)) + 1;
		while (--rt_end)
		{
			if (i >= 0 && j >= 0 && i < bot->yx.x && j < bot->yx.y && bot->wt_path[i][j] == MAX_INT_MAP)
				bot->wt_path[i][j] = d;
			if (i >= 0 && j >= 0 && j < bot->yx.y && i < bot->yx.x && bot->wt_path[i - k][yx.y + d] == MAX_INT_MAP)
				bot->wt_path[i - k][yx.y + d] = d;
//			printf("\n rt_end\n");
//			write_weither_matrix(*bot);
//			sleep(3);
			j--;
			k++;
		}
		d++;
	}
}

unsigned	sum_weight(t_bot bot, t_piece piece, t_coordinates yx)
{
	int i; // row  y
	int j; // colum x
	unsigned weight;

	weight = 0;
	i = yx.y - 1;
	while (++i < yx.y + piece.yx.y)
	{
		j = yx.x - 1;
		while (++j < yx.x + piece.yx.x)
			weight += bot.wt_path[i][j] != -1 || bot.wt_path[i][j] != MAX_INT_MAP ?
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

	yx.x = -1;
	res = zero_coordinates();
	weight = MAX_INT_MAP;
	while (++yx.x < bot->yx.x)
	{
		yx.y = -1;
		while (++yx.y < bot->yx.y)
		{
			if (!check_put_piece(*bot, piece, yx))
				continue ;
			init_bot_wt_matrix(bot);
			printf("init matrix \n");
			write_weither_matrix(*bot);
//			sleep(1);
			wave_matrix(bot, yx);
			printf("wave matrix \n");
			write_weither_matrix(*bot);
			sleep(10);
			temp = sum_weight(*bot, piece, yx);
			if ((weight > temp ? weight = temp : 0))
				res = yx;
		}
	}
	return (res);
}