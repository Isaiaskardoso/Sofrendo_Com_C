/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kardoso <kardoso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 14:34:57 by kardoso           #+#    #+#             */
/*   Updated: 2026/11/05 14:35:15 by kardoso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_check_base(char *base)
{
	int	i;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-'
			|| (base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
			return (0);
		if (ft_index(base[i], base + i + 1) != -1)
			return (0);
		i++;
	}
	return (i);
}

long	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		sign;
	int		base_len;
	long	result;

	i = 0;
	sign = 1;
	base_len = ft_strlen(base);
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_index(str[i], base) != -1)
	{
		result = result * base_len + ft_index(str[i], base);
		i++;
	}
	return (result * sign);
}
