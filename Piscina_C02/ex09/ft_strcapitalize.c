/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IsaiasKardoso <isaiaskardososilva@gmail    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 00:10:28 by IsaiasKardo       #+#    #+#             */
/*   Updated: 2026/07/02 23:57:54 by IsaiasKardo      ###   ########.fr       */
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

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 || !((str[i - 1] >= 'a' && str[i - 1] <= 'z') ||
						(str[i - 1] >= 'A' && str[i - 1] <= 'Z') ||
						(str[i - 1] >= '0' && str[i - 1] <= '9') ))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				str[i] -=32;
			}			
		}
		else
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				str[i] += 32;
			}			
		}
		i++;		
	}
	return (str);	
}

int	main(int argc, char *argv[])
{
	char *modifica;
	int i;

	i = 1;
	while (i < argc)
	{
		modifica = ft_strcapitalize(argv[i]);
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
