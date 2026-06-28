/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IsaiasKardoso <isaiaskardososilva@gmail    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 23:55:08 by IsaiasKardo       #+#    #+#             */
/*   Updated: 2026/06/28 00:36:56 by IsaiasKardo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_puchar(char c)
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
		ft_puchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb/ 10);
	}
	ft_puchar((nb % 10) + '0');	
}

int	ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);	
}

int	main(int argc, char *argv[])
{
	int a;
	int i;

	i = 1;
	while (i < argc)
	{
		a = ft_strlen(argv[i]);
		ft_putnbr(a);
		if (1 < argc - 1)
		{
			ft_puchar(' ');
		}
		i++;
	}
	ft_puchar('\n');
	return (0);
}
