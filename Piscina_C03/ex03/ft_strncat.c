/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IsaiasKardoso <isaiaskardososilva@gmail    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 11:51:19 by IsaiasKardo       #+#    #+#             */
/*   Updated: 2026/07/17 12:10:09 by IsaiasKardo      ###   ########.fr       */
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
char *ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned	int	i;
	unsigned	int j;
	
	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0' && j < nb)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int	main(int argc, char *argv[])
{
	char dest[50];
	int i;

	if (argc < 2)
	{
		ft_putstr("Digite algo para concatenar?");
		ft_putchar('\n');
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		unsigned	int n = 2;
		
		ft_strncat(dest, argv[i], n);
		i++;
	}
	ft_putstr(dest);
	ft_putchar('\n');
	return (0);
}