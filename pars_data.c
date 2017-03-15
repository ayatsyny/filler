//
// Created by Andriy Yatsynyak on 3/7/17.
//

#include "filler.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int g_fd;

//
//void write_strs(char **strs)
//{
//	int i = -1;
//	while (strs[++i])
//		printf("%s\n", strs[i]);
//}

void	init_y_and_x(char *line, int *y, int *x)
{
	if (!line || ft_strlen(line) == 0)
		return ;
	*x = ft_atoi(ft_strchr(line, ' '));
	*y = ft_atoi(ft_strrchr(line, ' '));
}

void	create_map(t_bot *bot, char *line)
{
	int i;

	while (get_next_line(g_fd, &line) && !ft_strstr(line, "Plateau"))
		;
	init_y_and_x(line, &bot->yx.y, &bot->yx.x);
	bot->wt_path = (int **)malloc(bot->yx.x * sizeof(int *));
	bot->map = (char **)malloc((bot->yx.x + 1) * sizeof(char*));
	i = -1;
	while (++i < bot->yx.x)
		bot->map[i] = ft_strnew((size_t) bot->yx.y);
	bot->map[i] = NULL;
	i = -1;
	while (++i <= bot->yx.x)
		bot->wt_path[i] = (int *)malloc(bot->yx.y * sizeof(int));
}

void	init_bot_wt_matrix(t_bot *bot)
{
	int i;
	int j;

	i = -1;
	bot->p_yx = zero_coordinates();
	while (++i < bot->yx.x)
	{
		j = -1;
		while (++j < bot->yx.y)
			if (bot->map[i][j] == '.')
				bot->wt_path[i][j] = MAX_INT_MAP;
			else
				bot->wt_path[i][j] = bot->player == bot->map[i][j] ? -2 : 0;
	}
}



void	init_piece(t_piece *piece, char *line)
{
	int i;

	i = -1;
	while (get_next_line(g_fd, &line) && !ft_strstr(line, "Piece"))
		;
	init_y_and_x(line, &piece->yx.y, &piece->yx.x);
	if (!(piece->map = (char **)malloc((piece->yx.x + 1) * sizeof(char*))))
		return ;
	while (++i < piece->yx.x)
	{
		get_next_line(g_fd, &line);
		piece->map[i] = ft_strnew((size_t)piece->yx.y);
		ft_strcpy(piece->map[i], line);
	}
	piece->map[i] = NULL;
}

void	del_matrix_str(char **matrix)
{
	int i;

	i = -1;
	 while (matrix[++i] != NULL)
	 {
		 free(matrix[i]);
		 matrix[i] = NULL;
	 }
	free(matrix);
	matrix = NULL;
}

void	find_players(t_bot *bot, char *line)
{
	get_next_line(g_fd, &line);
	while (!(ft_strstr(line, "$$$") && ft_strstr(line, "/filler")))
		get_next_line(g_fd, &line);
	if (!ft_strstr(line, "/filler"))
		return ;
	if (ft_strstr(line, "p1"))
		bot->player = 'O';
	else
		bot->player = 'X';
	bot->pc_player = bot->player == 'O' ? 'X' : 'O';
}


void	read_map_bot(t_bot *bot, char *line)
{
	int i;

	i = -1;
	while (i + 1 < bot->yx.x && get_next_line(g_fd, &line))
		if (line[0] == '0')
			ft_strcpy(bot->map[++i], line + 4);
}


void	output_res(char *file_name, t_bot bot, t_piece piece, t_coordinates yx)
{
	int fout;
	int i;
	char *x;
	char *y;

	x = NULL;
	y = NULL;
	fout = open(file_name, O_WRONLY | O_CREAT | O_APPEND, S_IWRITE | S_IREAD);
	if (fout == -1)
		perror(strerror(errno));
//	ft_putstr_fd("\ny = ", fout);
//	ft_putnbr_fd(y, fout);
//	ft_putstr_fd("\nx = ", fout);
//	ft_putnbr_fd(x, fout);
//	ft_putchar_fd('\n', fout);
	i = -1;
	while (bot.map[++i] && ft_strlen(bot.map[i]))
		ft_putendl_fd(bot.map[i], fout);
	i = -1;
	while (piece.map[++i] && ft_strlen(piece.map[i]))
		ft_putendl_fd(piece.map[i], fout);


	write(fout, "\ncordinat: ", 11);
	x = ft_itoa(yx.x);
	y = ft_itoa(yx.y);
	write(fout, x, ft_strlen(x));
	ft_putchar_fd(' ', fout);
	ft_putendl_fd(y, fout);
//	close(fout);
}
void output_player(char *file_name, t_bot bot)
{
	int fout;

	fout = open(file_name, O_WRONLY | O_CREAT, S_IWRITE | S_IREAD);
	if (fout == -1)
		perror(strerror(errno));
	ft_putstr_fd("User player: ", fout);
	ft_putchar_fd(bot.player, fout);
	ft_putchar_fd('\n', fout);
	ft_putstr_fd("PC player: ", fout);
	ft_putchar_fd(bot.pc_player, fout);
	ft_putchar_fd('\n', fout);
	//close(fout);
}


void	ft_write(t_coordinates yx)
{
	char *x;
	char *y;

	x = ft_itoa(yx.x);
	y = ft_itoa(yx.y);
	write(1, x, ft_strlen(x));
	write(1, " ", 1);
	write(1, y, ft_strlen(y));
	write(1, "\n", 1);
	free(x);
	free(y);
}

void	run_bot(t_bot *bot, t_piece *piece, char *line)
{
	int i;
	t_coordinates res;


//	read_maps(bot, piece, line);
//	write_strs(piece->map);
	i = 9902; // magic number (max map 100 * 99 ~ 9900 + 2)
	while (--i)
	{
		read_map_bot(bot, line);
//		write_strs(bot->map);
		init_piece(piece, line);
//		read_maps(bot, piece, line);
		res = zero_coordinates();
//		output_res("./log_bot.txt", *bot, *piece, res);
//		output_res("./log_bot.txt", bot->map);
//		output_res("./log_bot.txt", piece->map);
		//sleep(30);
		res = fight(bot, *piece);
		del_matrix_str(piece->map);
//		output_res("./log_bot.txt", piece->map);
		ft_write(res);
//		printf("%d %d\n", res.x, res.y);
	}
}

//int		main(void)
//{
//	char *line;
//	t_bot bot;
//	t_piece map;
//
//	line = NULL;
//	bot.player = find_player(line);
//	create_map(&bot, line);
//	run_bot(&bot, &map, line);
//	del_wave_matrix(bot.wt_path);
//	del_matrix_str(bot.map);
//	return (0);
//}




int		main(void)
{
	char *line;
	t_bot bot;
	t_piece piece;

	line = NULL;
//	g_fd = open("./test2.txt", O_RDONLY, S_IREAD);
//	if (g_fd == -1)
//	{
//		write(1, "error open test file\n", 21);
//		return (0);
//	}
	g_fd = 0;
	find_players(&bot, line);
//	output_player("./log_player.txt", bot);
	create_map(&bot, line);
	run_bot(&bot, &piece, line);
	del_wave_matrix(bot.wt_path);
	del_matrix_str(bot.map);
	return (0);
}

//
//int		main(void)
//{
//	char *line;
////	int f;
//
//	t_bot bot;
//	t_piece map;
//
//	line = NULL;
////	f = open("log_player.txt", O_WRONLY | O_CREAT | O_APPEND, S_IWRITE | S_IREAD);
////	if (f == -1)
////		write(1, "error", 5);
//	bot.player = find_player(line);
//	create_map(&bot, line);
//	output_res("./log_bot.txt", bot.map, bot.yx.x, bot.yx.y);
////	get_next_line(0, &line);
//
////	int test;
////	test = open("log_test_pars.txt", O_WRONLY | O_CREAT, S_IWRITE | S_IREAD);
//
////	output_res("./log_bot.txt", bot.map, bot.yx.x, bot.yx.y);
////	output_res("./log_piece.txt", piece.piece, piece.yx.x, piece.yx.y);
////	get_next_line(0, &line);
////	create_map(&bot, line);
////	write(f, line, sizeof(line));
////	ft_putendl_fd(line, f);
////	free(line);
//	//write(1, "[0, 5]", 6);
////	close(f);
////	close(test);
//	del_matrix_str(map.map);
//	del_matrix_str(bot.map);
//	sleep(100);
//	return (0);
//}