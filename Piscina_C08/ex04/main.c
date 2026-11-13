/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kardoso <kardoso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 18:59:17 by kardoso           #+#    #+#             */
/*   Updated: 2026/11/12 21:55:00 by kardoso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_stock_str.h"

t_stock_str	*ft_strs_to_tab(int ac, char **av);

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	t_stock_str	*tab;
	int			i;

	tab = ft_strs_to_tab(argc, argv);
	if (!tab)
		return (1);
	i = 0;
	while (i < argc)
	{
		ft_putstr("size: ");
		ft_putnbr(tab[i].size);
		ft_putstr(" | str: ");
		ft_putstr(tab[i].str);
		ft_putstr(" | copy: ");
		ft_putstr(tab[i].copy);
		ft_putstr("\n");
		i++;
	}
	i = 0;
	while (i < argc)
	{
		free(tab[i].copy);
		i++;
	}
	free(tab);
	return (0);
}