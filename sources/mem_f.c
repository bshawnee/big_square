#include "../includes/main.h"

void	free_mem(int **matrix)
{
	int i;

	i = 0;
	while (i <= g_len)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int		**take_memory(void)
{
	int **map;
	int i;

	i = 0;
	map = (int**)malloc(sizeof(int*) * g_len + 1);
	if (!map)
		return (NULL);
	while (i <= g_len)
	{
		map[i] = (int*)malloc(sizeof(int) * g_wid + 1);
		if (!map[i])
			return (NULL);
		i++;
	}
	return (map);
}
