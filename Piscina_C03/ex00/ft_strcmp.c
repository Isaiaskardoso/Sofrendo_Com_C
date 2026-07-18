/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IsaiasKardoso <isaiaskardososilva@gmail    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 12:08:04 by IsaiasKardo       #+#    #+#             */
/*   Updated: 2026/07/13 13:11:46 by IsaiasKardo      ###   ########.fr       */
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

int ft_strcmp(char *s1, char *s2)
{
	int i;
	
	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);	
}

int	main(int argc, char *argv[])
{
	int i;
	int result;

	if (argc < 3)
	{
		ft_putstr("Uso: ./a.out string1 string2...\n");
		return (0);
	}
	i = 2;
	while (i < argc)
	{
		result = ft_strcmp(argv[1], argv[i]);
		ft_putstr(" /Comparando ");
		ft_putstr(argv[1]);
		ft_putstr(" com ");
		ft_putstr(argv[i]);
		if (result == 0)
		{
			ft_putstr(" -> Iguais");
		}
		else
		{
			ft_putstr(" -> Diferentes ");
		}
		i++;		
	}
	ft_putchar('\n');
	return (0);	
}