/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c, ft_convert_base2.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kardoso <kardoso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 01:16:07 by kardoso           #+#    #+#             */
/*   Updated: 2026/11/04 01:38:35 by kardoso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_index(char c, char **base)
{
	int i;
	
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
		{
			return (i);
		}
		i++;		
	}
	return (-1);
}

long	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	base_len;
	long	result;

	i = 0;
	sign = 1;
	base_len = ft_strlen(base);//pecorre o tamanho da string
	result = 0;// tipo long
	while (str[i] >= 9 && str[i] <= 13 || str[i] == 32)
	{
		i++;
	}
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			sign = -sign;			
		}
		i++;
	}
	while (ft_index(str[i], base) != -1)
	{
		result = result * base_len + ft_index(str[i], base);
		i++;
	}
	return (result * sign);	
}


