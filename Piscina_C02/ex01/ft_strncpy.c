/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IsaiasKardoso <isaiaskardososilva@gmail    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 07:04:42 by IsaiasKardo       #+#    #+#             */
/*   Updated: 2026/07/01 08:07:39 by IsaiasKardo      ###   ########.fr       */
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

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;
	
	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);	
}

int	main(int argc, char *argv[])
{
	char dest[100] = "String antes";
	int i;

	i = 0;
	while (i < argc)
	{
		dest[0] = '\0'; // ---> limpa o dest do resto de memoria
		ft_strncpy(dest, argv[i], 10); 
		dest[5] = '\0'; // ---> garante o tamanho
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