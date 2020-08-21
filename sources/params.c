#include "../includes/main.h"

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
