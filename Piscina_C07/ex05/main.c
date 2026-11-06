/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kardoso <kardoso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 15:19:07 by kardoso           #+#    #+#             */
/*   Updated: 2026/11/05 23:05:32 by kardoso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	**ft_split(char *str, char *charset);

static void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

int	main(int argc, char **argv)
{
	char	**res;
	int		i;

	if (argc != 3)
	{
		ft_putstr("Uso: ./ft_split \"string\" \"charset\"\n");
		return (1);
	}
	res = ft_split(argv[1], argv[2]);
	if (!res)
	{
		ft_putstr("Erro: falha na alocacao\n");
		return (1);
	}
	i = 0;
	while (res[i])
	{
		ft_putstr("[");
		ft_putstr(res[i]);
		ft_putstr("]\n");
		free(res[i]);
		i++;
	}
	free(res);
	return (0);
}
