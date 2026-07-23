/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IsaiasKardoso <isaiaskardososilva@gmail    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 07:33:32 by IsaiasKardo       #+#    #+#             */
/*   Updated: 2026/07/23 01:28:42 by IsaiasKardo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*int	ft_table(char c)
{
	if (c >= 48 && c <= 57) // numerico
	{
		return (1);
	}
	else if (c >= 97 && c <= 122) // abc
	{
		return (2);
	}
	else if (c >= 65 && c <= 90) // ABC
	{
		return (3);
	}
	else
	{
		return (0);
	}
}*/

int	ft_verifica(char *base)
{
	int len;
	int i;

	len = 0;
	while (base[len])
	{
		if (base[0] == '\0'
			|| base[len] == '+'
			|| base[len] == '-'
			|| (base[len] >= 9 && base[len] <= 13)
			|| base[len] == 32)
		{
			return (0);
		}
		i = 0;
		while (base[i])
		{
			if (i != len && base[i] == base[len])
			{
				return (0);
			}
			i++;
		}
		len++;
	}
	return (len);
}

int	ft_spaces(char *str, int *ptr_i)
{
	int i;
	int sign_cont;

	i = 0;
	sign_cont = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	while ((str[i] == 43 || str[i] == 45))
	{
		if (str[i] == 45)
		{
			sign_cont *= -1;
		}
		i++;
	}
	*ptr_i = i;
	return (sign_cont);
}

int	ft_index_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	len;
	int	result;
	int	index;

	len = ft_verifica(base);
	if (len == 1 || len == 0)
	{
		return (0);
	}
	i = 0;
	sign = ft_spaces(str, &i);
	result = 0;
	index = ft_index_base(str[i], base);
	while (str[i] && index != -1)
	{		
		result *= len;
		result += index;
		i++;
		index = ft_index_base(str[i], base);
	}
	result *= sign;
	return (result);
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	int	result;

	if (argc != 3)
		return (1);
	result = ft_atoi_base(argv[1], argv[2]);
	ft_putnbr(result);
	write(1, "\n", 1);
	return (0);
}

/*#include <unistd.h>

int	ft_table(char c)
{
	if (c >= 48 && c <= 57)// numerico
	{
		return (1);
	}
	else if (c >= 97 && c <= 122)// abc 
	{
		return (2);
	}
	else if (c >= 65 && c <= 90)// ABC
	{
		return (3);
	}
	else
	{
		return (0);
	}	
}

int	ft_verifica(char *base)
{
	int len;
	int i;

	len = 0;
	while (base[len])
	{
		if (base[0] == '\0' || base[len] == 43 || base[len] == 45)
		{
			return (0);
		}
		i = 0;
		while (base[i])
		{
			if (i != len && base[i] == base[len])
			{
				return (0);
			}
			i++;		
		}
		len++;		
	}
	return (len);	
}

int	ft_spaces(char *str, int *ptr_i)
{
	int i;
	int sign_cont;

	i = 0;
	sign_cont = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	while ((str[i] == 43 || str[i] == 45))
	{
		if (str[i] == 45)
		{
			sign_cont *= -1;
		}
		i++;		
	}
	*ptr_i = i;
	return (sign_cont);	
}

int ft_atoi_base(char *str, char *base)
{
	int i;
	int sign;
	int len;
	int result;

	len = ft_verifica(base);
	if (len == 1 || len == 0)
	{
		return (0);
	}
	
	i = 0;
	sign = ft_spaces(str, &i);
	result = 0;
	while (str[i] && ft_table(str[i]))
	{
		result *= len;
		if (ft_table(str[i]) == 3)
		{
			result += str[i] - 7 - 48;			
		}
		else if (ft_table(str[i]) == 2)
		{
			result += str[i] - 39 - 48;
		}
		else if (ft_table(str[i]) == 1)
		{
			result += str[i] - 48;
		}
		i++;		
	}
	result *= sign;
	return (result);	
}

void	ft_putnbr(int nb)
{
	char c;
	
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	c = (nb % 10) + '0';
	write(1, &c, 1);	
}

int	main(int argc, char *argv[])
{
	int result;

	if (argc != 3)
		return (1);
	result = ft_atoi_base(argv[1], argv[2]);
	ft_putnbr(result);
	write(1, "\n", 1);
	return (0);
}*/