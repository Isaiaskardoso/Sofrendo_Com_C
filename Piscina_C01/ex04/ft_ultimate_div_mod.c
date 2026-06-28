/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IsaiasKardoso <isaiaskardososilva@gmail    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 12:51:43 by IsaiasKardo       #+#    #+#             */
/*   Updated: 2026/06/27 15:24:57 by IsaiasKardo      ###   ########.fr       */
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
	while ((str[i] >= 13 && str[i] <= 9) || str[i] == 32)
	{
		i++;
	}
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign = -1;			
		}
		i++;		
	}
	while (str[i] >= '0'&& str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;		
	}
	return (result * sign);	
}

void ft_ultimate_div_mod(int *a, int *b)
{
	int temp;
	if (*b != 0)
	{
		temp = *a;
		*a = temp / *b;
		*b = temp % *b;
	}
}

int	main(int argc, char *argv[])
{
	int a;
	int b;

	if (argc == 3)
	{
		a = ft_atoi(argv[1]);
		b = ft_atoi(argv[2]);

		ft_ultimate_div_mod(&a, &b);

		ft_putnbr(a);
		ft_putchar('\n');
		ft_putnbr(b);
		ft_putchar('\n');
	}
	return (0);
}	
