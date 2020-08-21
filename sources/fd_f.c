#include "../includes/main.h"

int		take_params(char *file)
{
	int fd;
	int i;
	char buf[BUFFSIZE];

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (read(fd, buf, BUFFSIZE) && buf[0] != '\n')
	{
		g_params[i] = buf[0];
		i++;
	}
	g_params[i] = '\0';
	while (read(fd, buf, BUFFSIZE) && buf[0] != '\n')
			g_wid++;
	close(fd);
	return (0);
}

int		**fill_matrix(char *file)
{
	int **matrix;
	int fd;
	char buf[BUFFSIZE];
	int j;

	matrix = take_memory();
	fd = open(file, O_RDONLY);
	while (read(fd, buf, BUFFSIZE) && buf[0] != '\n')
		;
	for (int i = 0; i < g_len; i++)
	{
		j = 0;
		while (read(fd, buf, BUFFSIZE) && buf[0] != '\n')
		{
			if (buf[0] == g_params[0])
				matrix[i][j] = 1;
			else if (buf[0] == g_params[1])
				matrix[i][j] = 0;
			else
			{
				free_mem(matrix);
				return (NULL);
			}
			j++;
		}
		if (j != g_wid)
		{
			free_mem(matrix);
			return (NULL);
		}
	}
	return (matrix);
}
