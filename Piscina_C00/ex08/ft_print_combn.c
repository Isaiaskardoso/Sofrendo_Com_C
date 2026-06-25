/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IsaiasKardoso <isaiaskardososilva@gmail    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 00:25:38 by IsaiasKardo       #+#    #+#             */
/*   Updated: 2026/06/25 19:15:58 by IsaiasKardo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_number(int *tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(tab[i] + '0');
		i++;
	}
	if ((tab[0]) != 10 - n)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	backtrack(int *tab, int index, int n)
{
	int	i;
	int	max;

	i = 0;
	if (index == n)
	{
		ft_print_number(tab, n);
		return;
	}
	if (index == 0)
	{
		i = 0;
	}
	else
	{
		i = tab[index - 1] + 1;
	}
	max = 10 - (n - index);
	while (i <= max)
	{
		tab[index] = i;
		backtrack(tab, index + 1, n);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	tab[10];
	if(n <= 0 || n>= 10)
	{
		return;
	}
	backtrack(tab, 0, n);
}

int	main()
{
	ft_print_combn(2);
	ft_putchar('\n');
	return (0);
}
