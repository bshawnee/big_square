#include "../includes/main.h"

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
