/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kardoso <kardoso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 12:42:14 by kardoso           #+#    #+#             */
/*   Updated: 2026/11/12 21:46:17 by kardoso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);	
}

char	*ft_strcopy(char *str)
{
	char	*buf;
	int	len;
	int i;
	
	i = 0;
	len = ft_strlen(str);
	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (!buf)
	{
		return (0);	
	}
		while (str[i] != '\0')
	{
		buf[i] = str[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);	
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	int	i;
	t_stock_str *tab;

	tab = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!tab)
	{
		return (0);
	}
	
	i = 0;
	while (++i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strcopy(av[i]);
		i++;
	}
	// compos da struct
	tab[i].size = 0;
	tab[i].str = 0;
	tab[i].copy = 0;
	return (tab);	
}
