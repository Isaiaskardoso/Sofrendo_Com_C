/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IsaiasKardoso <isaiaskardososilva@gmail    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 14:44:10 by IsaiasKardo       #+#    #+#             */
/*   Updated: 2026/07/01 15:16:16 by IsaiasKardo      ###   ########.fr       */
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

int	ft_str_is_uppercase(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
		{
			return (0);
		}
		i++;	
	}
	return  (1);
}

int	main(int argc, char *argv[])
{
	int i;
	int result;

	i = 1;
	while (i < argc)
	{
		result = ft_str_is_uppercase(argv[i]);
		ft_putnbr(result);
		if (i < argc - 1)
		{
			ft_putchar(' ');
		}
		i++;		
	}
	ft_putchar('\n');
	return (0);	
}