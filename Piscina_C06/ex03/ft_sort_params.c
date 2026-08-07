/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IsaiasKardoso <isaiaskardososilva@gmail    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 01:02:24 by IsaiasKardo       #+#    #+#             */
/*   Updated: 2026/08/06 14:27:52 by IsaiasKardo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int i;
	
	i = 0;
	while (s2[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] > s2[i])
		{
			return (s1[i] - s2[i]);
		}
		else if (s1[i] < s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;		
	}
	return (0);	
}

void	ft_swap_str(char **argv, int index1, int index2)
{
	char *temp;
	
	temp = argv[index1];
	argv[index1] = argv[index2];
	argv[index2] = temp;
}

void	ft_print_argv(char **argv, int j)
{
	int k;// caracter por caracter
	
	k = 0;
	while (argv[j][k])
	{
		write(1, &argv[j][k], 1);
		k++;
	}
	//j++;
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	int etapa;
	int i;
	int j;

	etapa = 0;
	while (etapa < argc - etapa - 1)
	{
		i = 1;
		while (i < argc - etapa - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				ft_swap_str(argv, i, i + 1);
			}
			i++;			
		}
		etapa++;		
	}
	j = 1;
	while (j < argc)
	{
		ft_print_argv(argv, j);
		j++;
	}
	return (0);	
}
