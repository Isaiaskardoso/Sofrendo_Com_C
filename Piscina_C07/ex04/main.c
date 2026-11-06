/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kardoso <kardoso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:12:15 by kardoso           #+#    #+#             */
/*   Updated: 2026/11/04 16:16:23 by kardoso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_len(str));
}

int	main(int argc, char *argv[])
{
	char	*result;

	if (argc != 4)
	{
		ft_putstr("Uso: ./convert nbr base_from base_to\n");
		return (1);
	}
	result = ft_convert_base(argv[1], argv[2], argv[3]);
	if (result == 0)
	{
		ft_putstr("\0\n");
		return (1);
	}
	ft_putstr(result);
	write(1, "\n", 1);
	free(result);
	return (0);
}