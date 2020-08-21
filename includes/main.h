#ifndef __MAIN_H__
#define __MAIN_H__
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#define BUFFSIZE 1
#define TRUE	1

int		g_pos[4];
char	g_params[14];
int		g_s;
int		g_wid;
int		g_len;

void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);
void	ft_putstr(char *str);

int		save_map(void);
void	free_mem(int **matrix);
int		**take_memory(void);

void	clear_params(void);
int		update_params(void);
int		take_params(char *file);
int		**fill_matrix(char *file);

int		min(int n1, int n2, int n3);
void	print_matrix(int **mtx);
void	find_bsq(int **map);
void	print_bsq(int **map);
int		bsq(char *file);

#endif
