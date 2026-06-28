/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IsaiasKardoso <isaiaskardososilva@gmail    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:42:56 by IsaiasKardo       #+#    #+#             */
/*   Updated: 2026/06/26 16:00:24 by IsaiasKardo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
	while ((str[i] >= 9 && str[i] <= 13 ) || str[i] == 32)
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
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 +(str[i] - '0');
		i++;
	}
	return (result * sign);	
}

void	ft_swap(int *a, int *b)
{
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

int main(int argc, char *argv[])
{
	int a;
	int b;
	
	if (argc != 3)
	{
		return (1);
	}

	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[2]);

	ft_swap(&a, &b);
	ft_putstr("Valor de a: ");
	ft_putnbr(a);
	ft_putchar('\n');
	ft_putstr("Valor de b: ");
	ft_putnbr(b);
	ft_putchar('\n');
	
	
	return (0);
}