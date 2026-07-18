/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IsaiasKardoso <isaiaskardososilva@gmail    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 12:21:34 by IsaiasKardo       #+#    #+#             */
/*   Updated: 2026/07/17 12:36:57 by IsaiasKardo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}	
}

char *ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	if (to_find[0] == '\0')
	{
		return (str);
	}
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] && str[i + j] == to_find[j])
		{
			j++;
		}
		if (to_find[j] == '\0')
		{
			return (&str[i]);
		}
		i++;		
	}
	return (0);	
}

int	main(int argc, char **argv)
{
	char	*resultado;

	// Precisamos de 3 argumentos: [0]nome_do_prog, [1]string_grande, [2]palavra_procurada
	if (argc == 3)
	{
		resultado = ft_strstr(argv[1], argv[2]);

		if (resultado != 0) // Se encontrou (ponteiro não é nulo)
		{
			ft_putstr("Encontrado a partir de: ");
			ft_putstr(resultado);
			ft_putchar('\n');
		}
		else
		{
			ft_putstr("Não encontrado.\n");
		}
	}
	else
	{
		ft_putstr("Uso: ./a.out \"string grande\" \"palavra\"\n");
		ft_putstr("Exemplo: ./a.out \"42 Lisboa\" \"Lis\"\n");
	}
	return (0);
}