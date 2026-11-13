/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kardoso <kardoso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 15:23:19 by kardoso           #+#    #+#             */
/*   Updated: 2026/11/10 18:06:42 by kardoso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_abs.h"
#include	<unistd.h>

void	ft_putnbr(int nb)
{
	char c;
	
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

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
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

/*void	ft_is_negative(int n)
{
	if (n < 0)
	{
		write(1, "N", 1);
	}
	else
	{
		write(1, "P", 1);
	}
}*/

/*int	main(int argc, char *argv[])
{
	int	n;

	if (argc == 2)
	{
		n = ft_atoi(argv[1]);
		ft_putnbr(n);
		write(1, "\n", 1);
	}
	return (0);
}*/

int	main(int argc, char *argv[])
{
	int	n;
	
	if (argc == 2)
	{
		n = ft_atoi(argv[1]);
		n = ABS(n);
		ft_putnbr(n);
		write(1, "\n", 1);		
	}
	else
	{
		n = ft_atoi(argv[1]);
		n = ABS(n);
		ft_atoi(n);
	}
	return (0);
}
