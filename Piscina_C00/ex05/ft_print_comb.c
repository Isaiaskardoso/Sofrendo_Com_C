/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IsaiasKardoso <isaiaskardososilva@gmail    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:00:40 by IsaiasKardo       #+#    #+#             */
/*   Updated: 2026/06/25 19:06:13 by IsaiasKardo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_print(char i, char j, char y)
{
	ft_putchar(i);
	ft_putchar(j);
	ft_putchar(y);
	if (i != 55 || j != 56 || y != 57)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	char	i;
	char	j;
	char	y;

	i = '0';
	while (i <= 55)
	{
		j = i + 1;
		while (j <= 56)
		{
			y = j + 1;
			while (y <= 57)
			{
				ft_print(i, j, y);
				y++;
			}
			j++;
		}
		i++;
	}
}

int	main(void)
{
	ft_print_comb();
	ft_putchar('\n');
	return (0);
}
