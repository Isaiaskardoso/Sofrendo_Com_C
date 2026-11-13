/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kardoso <kardoso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 23:20:10 by kardoso           #+#    #+#             */
/*   Updated: 2026/11/07 23:20:15 by kardoso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"

int	main(void)
{
	int		a;
	int		b;
	int		len;

	/* Teste 1: ft_putchar */
	write(1, "Teste ft_putchar: ", 18);
	ft_putchar('A');
	write(1, "\n", 1);

	/* Teste 2: ft_swap */
	a = 10;
	b = 20;
	ft_swap(&a, &b);
	if (a == 20 && b == 10)
		write(1, "ft_swap: OK\n", 12);
	else
		write(1, "ft_swap: ERRO\n", 14);

	/* Teste 3: ft_putstr */
	write(1, "Teste ft_putstr: ", 17);
	ft_putstr("Ola, Isaías!");
	write(1, "\n", 1);

	/* Teste 4: ft_strlen */
	len = ft_strlen("Banabe");
	if (len == 6)
		write(1, "ft_strlen: OK\n", 14);
	else
		write(1, "ft_strlen: ERRO\n", 16);

	/* Teste 5: ft_strcmp */
	if (ft_strcmp("abc", "abc") == 0)
		write(1, "ft_strcmp igualdade: OK\n", 24);
	else
		write(1, "ft_strcmp igualdade: ERRO\n", 26);

	if (ft_strcmp("abc", "abd") < 0)
		write(1, "ft_strcmp menor: OK\n", 20);
	else
		write(1, "ft_strcmp menor: ERRO\n", 22);

	if (ft_strcmp("abd", "abc") > 0)
		write(1, "ft_strcmp maior: OK\n", 20);
	else
		write(1, "ft_strcmp maior: ERRO\n", 22);

	return (0);
}
