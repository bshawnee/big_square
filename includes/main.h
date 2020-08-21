#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int		g_pos[4];
char	g_params[14];
int		g_s;
int		g_wid;
int		g_len;

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);

#endif
