/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IsaiasKardoso <isaiaskardososilva@gmail    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 11:33:51 by IsaiasKardo       #+#    #+#             */
/*   Updated: 2026/06/30 16:20:09 by IsaiasKardo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*void	ft_putchar(char c)
{
	write(1, &c, 1);
}*/

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}	
}

void	ft_putnbr(int nb)
{
	char c;
	
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
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
			sign *= - 1;
		}
		i++;		
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return ( result * sign);	
}

void ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;
	int temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
			
		}
		i++;		
	}	
}

int	main(int argc, char *argv[])
{
	int numbers[100];
	int i;
	int size;
	
	if (argc < 2)
	{
		ft_putstr("Uso: ./a.out numero1 numero2...\n");
		return (0);
	}

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i] != '\0')
		{
			numbers[i] = argv[1][i] - '0';
			i++;
		}
		size = i;		
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			numbers[i - 1] = ft_atoi(argv[i]);
			i++;
		}
		size = argc -1;		
	}	
	
	ft_sort_int_tab(numbers, size);
	
	ft_putstr("Array ordenado:\n");

	i = 0;
	while (i < size)
	{
		ft_putnbr(numbers[i]);
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);	
}
