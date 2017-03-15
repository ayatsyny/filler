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

	if (bot.yx.x < b.x + piece.yx.x || bot.yx.y < b.y + piece.yx.y)
		return (0);
	p.x = -1;
	count = 0;
	while (++p.x < piece.yx.x)
	{
//		b.x += p.x;
		p.y = -1;
		while (++p.y < piece.yx.y)
		{
//			b.y += p.y;
			if (piece.map[p.x][p.y] == '.')
				continue ;
			else if (b.x + p.x > bot.yx.x || b.y + p.y > bot.yx.y || count > 1
					 || bot.pc_player == bot.map[b.x + p.x][b.y + p.y])
				return (0);
			else if (piece.map[p.x][p.y] == '*' && (bot.player == bot.map[b.x + p.x][b.y + p .y]))
				count++;
//			count += bot.player == bot.map[b.x][b.y] || bot.player - 32
//						 == bot.map[b.x][b.y] ? 1 : 0;
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

//void	wave_matrix(t_bot	*bot, t_coordinates yx)
//{
//	int i;
//	int j;
//	int d;
//	int k;
//	int rt_end;
//	int lf_end;
//
//	d = 1;
//	lf_end = 0;
//	int t = yx.x + 1;
//	while (d < M(yx.x, A(bot->yx.x - yx.x)) || d < M(yx.y, A(bot->yx.y - yx.y)))
//	{
//		i = t - d;
//		j = yx.y - d;
//		k = 0;
//		printf("\n \t test: \t %d\n", d);
//		lf_end += 2 + d;
////		lf_end += d > 1 ? 1 : 0;
//		while (lf_end--)
//		{
//			if (i >= 0 && j >= 0 && i < bot->yx.x && bot->wt_path[i][j] == MAX_INT_MAP)
//			bot->wt_path[i][j] = d;
//			if (i >= 0 && j >= 0 && j < bot->yx.y && bot->wt_path[i + k][yx.y - d] == MAX_INT_MAP)
//				bot->wt_path[i + k][yx.y - d] = d;
//			printf("\n lf_end\n");
//			write_weither_matrix(*bot);
//			sleep(3);
//			k++;
//			j++;
//		}
//		lf_end += 1 + d;
//		j = yx.y + d;
//		i = t + d;
//		k = 0;
//		rt_end = (2 << (d - 1)) + 1;
//		while (--rt_end)
//		{
//			if (i >= 0 && j >= 0 && i < bot->yx.x && j < bot->yx.y && bot->wt_path[i][j] == MAX_INT_MAP)
//				bot->wt_path[i][j] = d;
//			if (i >= 0 && j >= 0 && j < bot->yx.y && i < bot->yx.x && bot->wt_path[i - k][yx.y + d] == MAX_INT_MAP)
//				bot->wt_path[i - k][yx.y + d] = d;
//			printf("\n rt_end\n");
//			write_weither_matrix(*bot);
//			sleep(3);
//			j--;
//			k++;
//		}
//		d++;
//	}
//}

void 	wave_matrix(t_bot *bot)
{
	int i;
	int j;
	int d;
	int k;
	int t;

	k = -1;
	t = 0;
	while (++k < bot->yx.x + bot->yx.y)
	{
		i = -1;
		while (++i < bot->yx.x)
		{
			j = -1;
			while (++j < bot->yx.y)
				if (bot->wt_path[i][j] <= ++t && bot->wt_path[i][j] != -2)
				{
//					d = bot->wt_path[i][j] + 1;
//					i + 1 < bot->yx.x && bot->wt_path[i + 1][j] != -2 &&
//					bot->wt_path[i + 1][j] > d ? bot->wt_path[i + 1][j] = d : 0;
//					j + 1 < bot->yx.y && bot->wt_path[i][j + 1] != -2 &&
//					bot->wt_path[i][j + 1] > d ? bot->wt_path[i][j + 1] = d : 0;
//					i - 1 >= 0 && bot->wt_path[i - 1][j] != -2 &&
//					bot->wt_path[i - 1][i] > d ? bot->wt_path[i - 1][j] = d : 0;
//					j - 1 >= 0 && bot->wt_path[i][j - 1] != -2 &&
//					bot->wt_path[i][j - 1] > d ? bot->wt_path[i][j - 1] = d : 0;


					d = bot->wt_path[i][j] + 1;
					i + 1 < bot->yx.x && bot->wt_path[i + 1][j] != -2 &&
							(bot->wt_path[i + 1][j] > d || bot->wt_path[i + 1][j] == MAX_INT_MAP) ? bot->wt_path[i + 1][j] = d : 0;
					j + 1 < bot->yx.y && bot->wt_path[i][j + 1] != -2 &&
							(bot->wt_path[i][j + 1] > d || bot->wt_path[i][j + 1] == MAX_INT_MAP) ? bot->wt_path[i][j + 1] = d : 0;
					i - 1 >= 0 && bot->wt_path[i - 1][j] != -2 &&
							(bot->wt_path[i - 1][i] > d || bot->wt_path[i - 1][j] == MAX_INT_MAP) ? bot->wt_path[i - 1][j] = d : 0;
					j - 1 >= 0 && bot->wt_path[i][j - 1] != -2 &&
							(bot->wt_path[i][j - 1] > d || bot->wt_path[i][j - 1] == MAX_INT_MAP)? bot->wt_path[i][j - 1] = d : 0;

//					printf("test k = %d  i = %d  j = %d\n\n", k, i, j);
//					write_weither_matrix(*bot);
//					sleep(3);
// 	if (i + 1 < bot->yx.x)
//		bot->wt_path[i + 1][j] > 0 || (bot->wt_path[i + 1][j] != -2 &&
//				bot->wt_path[i + 1][j] > d) ? bot->wt_path[i + 1][j] = d : 0;
//	if (j + 1 < bot->yx.y)
//		bot->wt_path[i][j + 1] > 0 || (bot->wt_path[i][j + 1] != -2 &&
//				bot->wt_path[i][j + 1] > d) ? bot->wt_path[i][j + 1] = d : 0;
//	if (i - 1 >= 0)
//		bot->wt_path[i - 1][j] > 0 || (bot->wt_path[i - 1][j] != -2 &&
//				bot->wt_path[i - 1][j] > d) ? bot->wt_path[i - 1][j] = d : 0;
//	if (j - 1 >= 0)
//		bot->wt_path[i][j - 1] > 0 || (bot->wt_path[i][j - 1] != -2 &&
//				bot->wt_path[i][j - 1] > d) ? bot->wt_path[i][j - 1] = d : 0;
				}
//			printf("test k = %d  i = %d\n\n", k, i);
//			write_weither_matrix(*bot);
//			sleep(1);
		}
	}
}



//	if (i + 1 < bot->yx.x)
//		bot->wt_path[i + 1][j] == 0 || (bot->wt_path[i + 1][j] != -2 &&
//				bot->wt_path[i + 1][j] > d) ? bot->wt_path[i + 1][j] = d : 0;
//	if (j + 1 < bot->yx.y)
//		bot->wt_path[i][j + 1] == 0 || (bot->wt_path[i][j + 1] != -2 &&
//				bot->wt_path[i][j + 1] > d) ? bot->wt_path[i][j + 1] = d : 0;
//	if (i - 1 >= 0)
//		bot->wt_path[i - 1][j] == 0 || (bot->wt_path[i - 1][j] != -2 &&
//				bot->wt_path[i - 1][j] > d) ? bot->wt_path[i - 1][j] = d : 0;
//	if (j - 1 >= 0)
//		bot->wt_path[i][j - 1] == 0 || (bot->wt_path[i][j - 1] != -2 &&
//				bot->wt_path[i][j - 1] > d) ? bot->wt_path[i][j - 1] = d : 0;

//
//t_coordinates find_pc_bot(t_bot bot)
//{
//	int i;
//	int j;
//	char pc_player;
//	t_coordinates res;
//
//	i = -1;
//	pc_player = ft_strchr("oO", bot.player) ? 'x' : 'o';
//	res = zero_coordinates();
//	while (++i < bot.yx.x)
//	{
//		j = -1;
//		while (++j < bot.yx.y)
//			if (pc_player == bot.map[i][j] || pc_player - 32 == bot.map[i][j])
//			{
//				res.x = i;
//				res.y = j;
//				return (res);
//			}
//	}
//	return (res);
//}


//void wave_matrix(int x, int y, t_bot *bot, int d)
//{
//	bot->wt_path[x][y] = d;
//	if (x + 1 < bot->yx.x)
//		bot->wt_path[x + 1][y] == d || (bot->wt_path[x + 1][y] != -2 &&
//				bot->wt_path[x + 1][y] > d) ? wave_matrix(++x, y, bot, ++d) : 0;
//	if (y + 1 < bot->yx.y)
//		bot->wt_path[x][y + 1] == d || (bot->wt_path[x][y + 1] != -2 &&
//				bot->wt_path[x][y + 1] > d) ? wave_matrix(x, ++y, bot, ++d) : 0;
//	if (x - 1 >= 0)
//		bot->wt_path[x - 1][y] == d || (bot->wt_path[x - 1][y] != -2 &&
//				bot->wt_path[x - 1][y] > d) ? wave_matrix(--x, y, bot, ++d) : 0;
//	if (y - 1 >= 0)
//		bot->wt_path[x][y - 1] == d || (bot->wt_path[x][y - 1] != -2 &&
//				bot->wt_path[x][y - 1] > d) ? wave_matrix(x, --y, bot, ++d) : 0;
//	return ;
//}

unsigned	sum_weight(t_bot bot, t_piece piece, t_coordinates yx)
{
	int i; // row  y
	int j; // colum x
	unsigned weight;

	weight = 0;
	i = yx.x - 1;
	while (++i < yx.x + piece.yx.x)
	{
		j = yx.y - 1;
		while (++j < yx.y + piece.yx.y)
			weight += bot.wt_path[i][j] != MAX_INT_MAP && bot.wt_path[i][j] != -2 ?
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
	int 			f;

	yx.x = -1;
	res = zero_coordinates();
	weight = MAX_INT_MAP;
	init_bot_wt_matrix(bot);
//	printf("init matrix \n");
//	write_weither_matrix(*bot);
//	sleep(3);
//	printf("wave matrix \n");
	wave_matrix(bot);
//	test = find_pc_bot(*bot);
//	wave_matrix(test.x, test.y, bot, 1);
//	write_weither_matrix(*bot);
//	sleep(20);
	f = 1;
	while (++yx.x < bot->yx.x)
	{
		yx.y = -1;
		while (++yx.y < bot->yx.y)
		{
 			if (!check_put_piece(*bot, piece, yx))
				continue ;
			if (f)
			{
				res = yx;
				f = 0;
			}
//			init_bot_wt_matrix(bot);
//			printf("init matrix \n");
//			write_weither_matrix(*bot);
////			sleep(1);
//			wave_matrix(bot, yx);
//			printf("wave matrix \n");
//			write_weither_matrix(*bot);
//			sleep(10);
			temp = sum_weight(*bot, piece, yx);
			if ((weight > temp ? weight = temp : 0))
			{
				res.x = yx.x;
				res.y = yx.y;
			}
		}
	}
	return (res);
}