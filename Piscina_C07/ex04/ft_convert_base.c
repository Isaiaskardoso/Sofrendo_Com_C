/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kardoso <kardoso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 14:35:08 by kardoso           #+#    #+#             */
/*   Updated: 2026/11/05 14:35:11 by kardoso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		ft_check_base(char *base);
long	ft_atoi_base(char *str, char *base);

int	ft_nbr_len(long n, int base_len)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= base_len)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

void	ft_fill(char *res, long n, char *base, int len)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	res[len] = '\0';
	len--;
	res[len] = base[n % base_len];
	n /= base_len;
	while (n > 0)
	{
		len--;
		res[len] = base[n % base_len];
		n /= base_len;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	n;
	int		len;
	char	*result;

	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (0);
	n = ft_atoi_base(nbr, base_from);
	len = ft_nbr_len(n, ft_strlen(base_to));
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	ft_fill(result, n, base_to, len);
	return (result);
}