/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IsaiasKardoso <isaiaskardososilva@gmail    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 10:36:12 by IsaiasKardo       #+#    #+#             */
/*   Updated: 2026/07/17 11:41:16 by IsaiasKardo      ###   ########.fr       */
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

char *ft_strcat(char *dest, char *src)
{
	int i;
	int j;
	
	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);	
}

int	main(int argc, char *argv[])
{
	char dest[50];// = "Que comece o ";
	int i;
	
	if (argc < 2)
	{
		ft_putstr("digite algo para concatenar? ");
		ft_putchar('\n');
		return (0);
	}

	i = 1;
	while (i < argc)
	{
		ft_strcat(dest, argv[i]);
		i++;
	}
	ft_putstr(dest);
	ft_putchar('\n');
	return (0);	
}