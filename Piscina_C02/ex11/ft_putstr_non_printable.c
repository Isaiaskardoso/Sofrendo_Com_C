/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IsaiasKardoso <isaiaskardososilva@gmail    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 00:06:08 by IsaiasKardo       #+#    #+#             */
/*   Updated: 2026/07/06 02:08:45 by IsaiasKardo      ###   ########.fr       */
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

void	ft_puthex(unsigned char c)
{
	char hex[] = "0123456789abcdef";
	
	ft_putchar(hex[c / 16]);
	ft_putchar(hex[c % 16]);
}

void ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
		{
			ft_putchar(str[i]);
		}
		else
		{
			ft_putchar('\\');
			ft_puthex((unsigned char) str[i]);
		}
		i++;
	}	
}

int	main(void)
{
	char str1[] = "Ola\n42";
	char str2[] = "ABC\tDEF";
	char str3[] = "Oi\r\n42";
	char str4[] = "42\vSP";
	char str5[] = "42 SP";

	ft_putstr_non_printable(str1);
	ft_putchar('\n');

	ft_putstr_non_printable(str2);
	ft_putchar('\n');

	ft_putstr_non_printable(str3);
	ft_putchar('\n');

	ft_putstr_non_printable(str4);
	ft_putchar('\n');

	ft_putstr_non_printable(str5);
	ft_putchar('\n');

	return (0);
}