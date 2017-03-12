//
// Created by Andriy Yatsynyak on 3/9/17.
//

#include "filler.h"

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