/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IsaiasKardoso <isaiaskardososilva@gmail    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 00:39:48 by IsaiasKardo       #+#    #+#             */
/*   Updated: 2026/06/28 02:02:17 by IsaiasKardo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
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
		ft_putnbr( nb / 10);
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
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign *= -1;
		}
		i++;		
	}
	while (str[i] >= '0' && str[i] <='9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return ( result * sign);	
}

void ft_rev_int_tab(int *tab, int size)
{
	int temp;
	int i;

	i = 0;
	while (i < (size / 2))
	{
		temp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = temp;
		
		i++;
	}	
}

int main(int argc, char *argv[])
{
	int tab[100];
	int size;
	int i;

	if (argc != 2)
		return (0);

	size = 0;
	while (argv[1][size])
		size++;

	i = 0;
	while (i < size)
	{
		tab[i] = argv[1][i] - '0';
		i++;
	}

	ft_rev_int_tab(tab, size);

	i = 0;
	while (i < size)
	{
		ft_putnbr(tab[i]);
		if (i < size - 1)
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
	return (0);
}
