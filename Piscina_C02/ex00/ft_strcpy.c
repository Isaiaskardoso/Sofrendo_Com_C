/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IsaiasKardoso <isaiaskardososilva@gmail    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 22:32:35 by IsaiasKardo       #+#    #+#             */
/*   Updated: 2026/06/30 23:52:10 by IsaiasKardo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}	
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);	
}

int	main(int argc, char *argv[])
{
	char dest[100];
	int i;

	i = 0;
	while (i < argc)
	{
		ft_strcpy(dest, argv[i]);
		ft_putstr(dest);
		if (i != argc - 1)
		{
			ft_putchar(' ');
		}
		i++;		
	}
	ft_putchar('\n');
	return (0);	
}
