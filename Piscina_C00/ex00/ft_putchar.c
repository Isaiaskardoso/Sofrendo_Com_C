/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kardoso <kardoso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 13:38:53 by IsaiasKardo       #+#    #+#             */
/*   Updated: 2026/11/12 22:07:13 by kardoso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


/*int	main(void)
{
	ft_putchar(64);
	return (0);
}*/

/*Função que escreve um unico caracter com saida padrão */

int	main(int argc, char *argv[])
{
	if(argc == 2)
	{		
		ft_putchar (argv[1][0]);
	}
	ft_putchar('\n'); 	
	return (0);
}