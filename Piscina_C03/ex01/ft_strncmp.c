/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IsaiasKardoso <isaiaskardososilva@gmail    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 13:16:50 by IsaiasKardo       #+#    #+#             */
/*   Updated: 2026/07/15 16:49:48 by IsaiasKardo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != '\0')
	{
		write(1,&str[i], 1);
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
		write(1,"-", 1);
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
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32 )
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

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned	int	i;
	
	i = 0;
	if (n == 0)
	{
		return (0);
	}
	
	while (i < n - 1 && s1[i] != '\0' && s1[i] == s2[i] )
	{
		i++;
	}
	return ((unsigned char) s1[i] - (unsigned	char) s2[i]);	
}

int	main(int argc, char *argv[])
{
	int result;
	unsigned	int n;
	
	if (argc == 4)
	{
		n = ft_atoi(argv[3]);
		result = ft_strncmp(argv[1], argv[2], n);
		ft_putstr("Result: ");
		ft_putnbr(result);
	}
	else
	{
		ft_putstr("Uso: ./a.out str1 str2 n ");
	}
	write(1, "\n", 1);
	return (0);
	
}