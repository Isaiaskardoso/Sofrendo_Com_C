/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IsaiasKardoso <isaiaskardososilva@gmail    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 00:17:34 by IsaiasKardo       #+#    #+#             */
/*   Updated: 2026/07/06 01:55:17 by IsaiasKardo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_pustr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}	
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar((nb % 10) + '0');	
}

unsigned	int ft_strlcpy(char *dest, char *src, unsigned int size)
{

	unsigned	int	len;
	unsigned	int	i;

	len = 0;
	while (src[len])
	{
		len++;
	}
	i = 0;
	if (size != 0)
	{
		while (i < (size - 1) && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);	
}

int	main(int argc, char *argv[])
{
	char			dest[100] = "O que erá";
	unsigned int	len;

	if (argc != 2)
	{
		ft_pustr("Uso: ./a.out \"texto\"\n");
		return (1);
	}

	len = ft_strlcpy(dest, argv[1], sizeof(dest));

	ft_pustr("SRC : ");
	ft_pustr(argv[1]);
	ft_putchar('\n');

	ft_pustr("DEST: ");
	ft_pustr(dest);
	ft_putchar('\n');

	ft_pustr("RET : ");
	ft_putnbr(len);
	ft_putchar('\n');

	return (0);
}