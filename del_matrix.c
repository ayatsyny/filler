#include "filler.h"

void	del_matrix_int(int **matrix)
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