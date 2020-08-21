#include "../includes/main.h"

void	print_matrix(int **mtx)
{
	for (int i = 0; i < g_len; i++)
	{
		for (int j = 0; j < g_wid; j++)
			ft_putnbr(mtx[i][j]);
		ft_putchar('\n');
	}
}

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		for (int i = 1; i <= argc - 1; i++)
		{
			clear_params();
			if (bsq(argv[i]) == -1)
				ft_putstr("Map error\n");
			if (i != argc - 1)
				ft_putchar('\n');
		}
	}
	else
	{
		if (save_map() == -1)
			ft_putstr("Map error\n");
		open(".tmp_file.tmp", O_TRUNC);
	}
	return (0);
}
