/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IsaiasKardoso <isaiaskardososilva@gmail    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 23:23:08 by IsaiasKardo       #+#    #+#             */
/*   Updated: 2026/07/01 23:46:17 by IsaiasKardo      ###   ########.fr       */
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
 
char	*ft_strupcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			str[i] = str[i] - 32;
		}
		i++;		
	}
	return (str);	
}

int	main(int argc, char *argv[])
{
	int i;
	char *modifica;

	i = 1;
	while (i < argc)
	{
		modifica = ft_strupcase(argv[i]);
		ft_putstr(modifica);
		if (i < argc - 1)
		{
			ft_putchar(' ');
		}
		i++;		
	}
	ft_putchar('\n');
	return (0);	
}
