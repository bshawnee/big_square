#include "../includes/main.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	if (*str)
	{
		ft_putchar(*str);
		ft_putstr(str + 1);
	}
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
