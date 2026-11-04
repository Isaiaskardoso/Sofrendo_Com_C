/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kardoso <kardoso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 23:14:51 by kardoso           #+#    #+#             */
/*   Updated: 2026/10/22 23:54:00 by kardoso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include	<unistd.h>
#include	<stdlib.h>

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
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar((nb % 10) + '0');
}

int	ft_atoi(char *str)
{
	int i;
	int sign;
	int result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	*ft_range(int min, int max)
{
	int *buf;
	int	i;

	if (min >= max)
	{
		return (0);
	}

	buf = (int *)malloc(sizeof(int) * (max - min));
	if (!buf)
	{
		return (0);
	}
	i = 0;
	while (min < max)
	{
		buf[i] = min;
		i++;
		min++;
	}
	return (buf);
}

int	main(int argc, char *argv[])
{
	int max;
	int min;
	int *range;
	int i;

	if (argc != 3)
	{
		ft_putstr("Uso: ./a.out <min> <max>\n");
		return (1);
	}
	min = ft_atoi(argv[1]);
	max = ft_atoi(argv[2]);
	range = ft_range(min, max);

	if (!range)
	{
		ft_putstr("range vazio ou erro de alocacao\n");
		return (1);
	}
	i = 0;
	while (i < max - min)
	{
		ft_putnbr(range[i]);
		if (i < max - min - 1)
		{
			ft_putchar(' ');
		}
		i++;
	}
	ft_putchar('\n');
	free(range);
	return (0);
}
