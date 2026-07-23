/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IsaiasKardoso <isaiaskardososilva@gmail    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 20:15:52 by IsaiasKardo       #+#    #+#             */
/*   Updated: 2026/07/22 00:44:26 by IsaiasKardo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* Protótipo porque ft_putstr_base usa ft_putnbr_base */
void	ft_putnbr_base(int nbr, char *base);

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	ft_verifica(char *base)
{
	int	len;
	int	i;

	len = 0;
	while (base[len])
	{
		if (base[len] == 43 || base[len] == 45)
			return (0);
		i = len + 1;
		while (base[i])
		{
			if (base[i] == base[len])
				return (0);
			i++;
		}
		len++;
	}
	if (len < 2)
		return (0);
	return (len);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;

	len = ft_verifica(base);
	if (!len)
		return ;

	if (nbr < 0)
	{
		write(1, "-", 1);
		ft_putnbr_base(-nbr, base);
	}
	else if (nbr >= len)
	{
		ft_putnbr_base(nbr / len, base);
		ft_putnbr_base(nbr % len, base);
	}
	else
		write(1, &base[nbr], 1);
}

void	ft_putstr_base(char *str, char *base)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putnbr_base((unsigned char)str[i], base);
		if (str[i + 1])
			write(1, " ", 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 4)
		return (0);

	if (argv[3][0] == 'n')
		ft_putnbr_base(ft_atoi(argv[1]), argv[2]);
	else if (argv[3][0] == 's')
		ft_putstr_base(argv[1], argv[2]);

	write(1, "\n", 1);
	return (0);
}