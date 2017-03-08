//
// Created by Andriy Yatsynyak on 3/7/17.
//

#include "filler.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>


void	init_y_and_x(char *line, int *y, int *x)
{
	*y = ft_atoi(ft_strchr(line, ' '));
	*x = ft_atoi(ft_strrchr(line, ' '));
}

void	create_map(t_bot *bot, char *line)
{
	int i;

	while (get_next_line(0, &line) && !ft_strstr(line, "Plateau"))
		;
	init_y_and_x(line, &bot->y, &bot->x);
	bot->map = (char **)malloc((bot->y + 1) * sizeof(char*));
	i = -1;
	while (++i < bot->y)
		bot->map[i] = ft_strnew((size_t)bot->x);
	bot->map[i] = NULL;
}

void	init_piece(t_piece *piece, char *line)
{
	int i;

	i = -1;
	init_y_and_x(line, &piece->y, &piece->x);
	if (!(piece->piece = (char **)malloc((piece->y + 1) * sizeof(char*))))
		return ;
	while (++i < piece->y)
	{
		get_next_line(0, &line);
		piece->piece[i] = ft_strnew((size_t)piece->x);
		ft_strcpy(piece->piece[i], line);
		free(line);
	}
	piece->piece[i] = NULL;
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

char	find_player(char *line)
{
	get_next_line(0, &line);
	if (!ft_strstr(line, "/filler"))
		return (0);
	if (ft_strstr(line, "p1"))
		return ('O');
	return ('X');
}


void	read_maps(t_bot *bot, t_piece *piece, char *line)
{
	int flag_read_piece;
	int i;

	i = -1;
	flag_read_piece = 1;
	while (flag_read_piece && get_next_line(0, &line))
	{
		if (line[0] == '0')
			ft_strcpy(bot->map[++i], line + 4);
		else if (ft_strstr(line, "Piece"))
		{
			init_piece(piece, line);
			flag_read_piece = 0;
		}
	}
}


void	output_res(char *file_name, char **matrix, int x, int y)
{
	int fout;
	int i = -1;

	fout = open(file_name, O_WRONLY | O_CREAT | O_APPEND, S_IWRITE | S_IREAD);
	if (fout == -1)
		perror(strerror(errno));
	ft_putstr_fd("\ny = ", fout);
	ft_putnbr_fd(y, fout);
	ft_putstr_fd("\nx = ", fout);
	ft_putnbr_fd(x, fout);
	ft_putchar_fd('\n', fout);
	while (matrix[++i] && ft_strlen(matrix[i]))
		ft_putendl_fd(matrix[i], fout);
	close(fout);
}

void	init_piece_x_y(t_piece *piece)
{
	piece->x = 0;
	piece->y = 0;
}

void	run_bot(t_bot *bot, t_piece *piece, char *line)
{
	t_coordinates yx;

	while (1)
	{
		if (piece->x || piece->y)
			del_matrix_str(piece->piece);
		read_maps(&bot, &piece, line);


	}
}


int		main(void)
{
	char *line;
//	int f;

	t_bot bot;
	t_piece piece;

	init_piece_x_y(&piece);
	line = NULL;
//	f = open("log.txt", O_WRONLY | O_CREAT | O_APPEND, S_IWRITE | S_IREAD);
//	if (f == -1)
//		write(1, "error", 5);
	bot.player = find_player(line);
//	line = NULL;
	create_map(&bot, line);
	output_res("./log_bot.txt", bot.map, bot.x, bot.y);

//	int test;
//	test = open("log_test_pars.txt", O_WRONLY | O_CREAT, S_IWRITE | S_IREAD);

	read_maps(&bot, &piece, line);
	output_res("./log_bot.txt", bot.map, bot.x, bot.y);
	output_res("./log_piece.txt", piece.piece, piece.x, piece.y);
//	get_next_line(0, &line);
//	create_map(&bot, line);
//	write(f, line, sizeof(line));
//	ft_putendl_fd(line, f);
	free(line);
	//write(1, "[0, 5]", 6);
//	close(f);
//	close(test);
	del_matrix_str(piece.piece);
	del_matrix_str(bot.map);
	//sleep(100);
	return (0);
}