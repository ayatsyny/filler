//
// Created by Andriy Yatsynyak on 3/9/17.
//

#include "filler.h"

void create_wave_matrix(t_bot *bot)
{
	int i;
	int j;

	i = -1;
	if ((bot->wt_path = (int**)malloc(bot->y * sizeof(int*))))
		return ;
	while (++i < bot->y)
		if ((bot->wt_path[i] = (int *)malloc(bot->x * sizeof(int))))
			return ;
	i = -1;
	j = -1;
	while (++i < bot->y)
		while (++j < bot->x)
			bot->wt_path[i][j] = 1000;
}

void	del_wave_matrix(int **matrix)
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

