#include "main.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	unsigned int nbr;

	if (nb < 0)
	{
		nbr = -nb;
		ft_putchar('-');
	}
	else
		nbr = nb;
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else if (nbr < 10)
		ft_putchar(nbr + '0');
}

int		ft_atoi(char *str)
{
	int		i;
	int		n;
	int		nbr;

	i = 0;
	nbr = 0;
	while ((str[i] == ' ' || str[i] == '\t' ||
			str[i] == '\n') && str[i] != '\0')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	if (n == 1)
		nbr = -nbr;
	return (nbr);
}

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

void	clear_params(void)
{
	g_len = 0;
	g_wid = 0;
	g_s = 0;
	for (int i = 0; i < 14; i++)
		g_params[i] = 0;
	for (int i = 0; i < 4; i++)
		g_pos[i] = 0;
}

int		update_params(void)
{
	int i;
	char tmp;

	i = 0;
	while (g_params[i])
		i++;
	tmp = g_params[i - 3];
	g_params[i - 3] = '\0';
	for (int k = 0; g_params[k] && k < i - 3; k++)
		if (!(g_params[k] >= '0' && g_params[k] <= '9') || g_params[0] == '0')
			return (-1);
	g_len = ft_atoi(g_params);
	g_params[0] = tmp;
	g_params[1] = g_params[i - 2];
	g_params[2] = g_params[i - 1];
	g_params[3] = '\0';
	return (0);
}

int		**take_memory(void)
{
	int **map;
	int i;

	i = 0;
	map = (int**)malloc(sizeof(int*) * g_len + 1);
	if (!map)
		return (NULL);
	while (i < g_len)
	{
		map[i] = (int*)malloc(sizeof(int) * g_wid + 1);
		if (!map[i])
			return (NULL);
		i++;
	}
	return (map);
}

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

void	find_pos(int **map, int i, int j)
{
	g_pos[0];
}

void	find_bsq(int **map)
{
	for (int i = 1; i < g_len; i++)
	{
		for (int j = 1; j < g_wid; j++)
		{
			if (map[i][j] == 1 && map[i][j] > g_s)
			{
				map[i][j] = min(map[i][j - 1], map[i - 1][j], map[i - 1][j - 1]) + 1;
				g_s = map[i][j];
				find_pos(map, i, j);
			}
		}
	}
}

void	print_matrix(int **mtx)
{
	for (int i = 0; i < g_len; i++)
	{
		for (int j = 0; j < g_wid; j++)
			ft_putnbr(mtx[i][j]);
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
	//print_matrix(map);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		for (int i = 1; i <= argc - 1; i++)
		{
			clear_params();
			if (bsq(argv[i]) == -1)
				ft_putstr("Map error.\n");
		}
	}
	return (0);
}
