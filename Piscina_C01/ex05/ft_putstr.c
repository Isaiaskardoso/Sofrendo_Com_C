/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IsaiasKardoso <isaiaskardososilva@gmail    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 15:37:26 by IsaiasKardo       #+#    #+#             */
/*   Updated: 2026/06/27 23:48:51 by IsaiasKardo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}	
}

int	main(int argc, char *argv[])
{

	int i;

	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		if (argc - 1)
		{
			ft_putchar(' ');
		}		
		i++;
		
	}
	ft_putchar('\n');
	return (0);	
}