#include "../includes/main.h"

int		min(int n1, int n2, int n3)
{
	int tmp;
	int ar[3] = {n1, n2, n3};

	tmp = n1;
	for (int i = 0; i < 3; i++)
		if (tmp > ar[i])
			tmp = ar[i];
	return (tmp);
}

void	find_bsq(int **map)
{
	for (int i = 1; i < g_len; i++)
		for (int j = 1; j < g_wid; j++)
			if (map[i][j] == 1)
			{
				map[i][j] = min(map[i][j - 1], map[i - 1][j], map[i - 1][j - 1]) + 1;
				if (map[i][j] > g_s)
				{
					g_s = map[i][j];
					g_pos[0] = i - g_s;
					g_pos[1] = j - g_s;
					g_pos[2] = i;
					g_pos[3] = j;
				}
			}
}

void	print_one_rowcol(int **map)
{
	int one;

	one = 1;
	for (int i = 0; i < g_len; i++)
	{
		for (int j = 0; j <  g_wid; j++)
		{
			if (map[i][j] == 0)
				ft_putchar(g_params[1]);
			else if (map[i][j] == 1 && one)
			{
				one = 0;
				ft_putchar(g_params[2]);
			}
			else
				ft_putchar(g_params[0]);
		}
		ft_putchar('\n');
	}
}

void	print_bsq(int **map)
{
	int one_sq;

	one_sq = 0;
	if (g_s == 1)
		one_sq = 1;
	if (g_len == 1 || g_wid == 1)
	{
		print_one_rowcol(map);
		return ;
	}
	for (int i = 0; i < g_len; i++)
	{
		for (int j = 0; j < g_wid; j++)
		{
			if (map[i][j] == 0)
				ft_putchar(g_params[1]);
			else if (one_sq == 1 && map[i][j] == 1)
			{
				ft_putchar(g_params[2]);
				one_sq++;
			}
			else if (j > g_pos[1] && j <= g_pos[3] &&
					 i > g_pos[0] && i <= g_pos[2] && !one_sq)
				ft_putchar(g_params[2]);
			else
				ft_putchar(g_params[0]);
		}
		ft_putchar('\n');
	}
}

int		bsq(char *file)
{
	int	**map;
	if (take_params(file) == -1)
		return (-1);
	if (update_params() == -1)
		return (-1);
	map = fill_matrix(file);
	if (!map)
		return (-1);
	find_bsq(map);
	print_bsq(map);
	free_mem(map);
	return (0);
}
