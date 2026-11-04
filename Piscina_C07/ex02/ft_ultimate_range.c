/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kardoso <kardoso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 23:42:26 by kardoso           #+#    #+#             */
/*   Updated: 2026/10/27 19:02:43 by kardoso          ###   ########.fr       */
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
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr (nb / 10);
	}
	ft_putchar ((nb % 10) + '0');
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
		result = result * 10 + ( str[i] - '0');
		i++;
	}
	return ( result * sign);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*result;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	i = max - min;
	result = malloc(sizeof(int) * (i));
	if (result == 0)
	{
		*range = 0;
		return (-1);
	}
	*range = result;
	i = 0;
	while (max > min)
	{
		result[i] = min;
		min++;
		i++;
	}
	return (i);
}

int	main(int argc, char *argv[])
{
	int max;
	int min;
	int *range;
	int size;
	int i;

	if (argc != 3)
	{
		ft_putstr("Uso: ./a.out <min> <max>\n");
		return (1);
	}
	min = ft_atoi(argv[1]);
	max = ft_atoi(argv[2]);
	size = ft_ultimate_range(&range, min, max);

	if (size == -1)
	{
		ft_putstr("erro de alocacao\n");
		return (1);
	}
	else if (size == 0)
	{
		ft_putstr("range vazio\n");
		return (0);
	}
	i = 0;
	while (i < size)
	{
		ft_putnbr(range[i]);
		if (i < size - 1)
		{
			ft_putchar(' ');
		}
		i++;
	}
	ft_putchar('\n');
	free(range);
	return (0);
}