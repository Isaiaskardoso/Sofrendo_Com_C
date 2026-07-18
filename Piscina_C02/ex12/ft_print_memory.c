/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IsaiasKardoso <isaiaskardososilva@gmail    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 02:13:27 by IsaiasKardo       #+#    #+#             */
/*   Updated: 2026/07/11 14:28:57 by IsaiasKardo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_puthex(unsigned char c)// calculo de hex
{
	char hex[] = "0123456789abcdef";
	
	write(1, &hex[c / 16], 1);
	write(1 ,&hex[c % 16], 1);
}

void	ft_putaddress(unsigned long address)// Imprime um endereço de memória em hexadecimal (16 dígitos)
{
	const	char	*hex;
	char	buffer[16];
	int		i;

	hex = "0123456789abcdef";
	i = 15;
	while (i >= 0)
	{
		buffer[i] = hex[address % 16];//buffer → onde montamos o endereço antes de imprimir
		address /= 16;
		i--;
	}
	i = 0;
	while (i < 16)
	{
		write(1, &buffer[i], 1);
		i++;
	}
}

void	ft_print_hex_line(unsigned char *memory, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (i < size)
		{
			ft_puthex(memory[i]);
		}
		else
		{
			write(1," ", 1);
			write(1," ", 1);
		}
		write(1," ", 1);
		if (i == 7)//espaço no 8byte
		{
			write(1," ", 1);
		}		
		i++;
	}
}

void	ft_print_char_line(unsigned char *memory, unsigned int size)
{
	unsigned	int i;

	i = 0;
	while (i < size)
	{
		if (memory[i] >= 32 && memory[i] <= 126)
		{
			write(1, &memory[i], 1);
		}
		else
		{
			write(1,".", 1);		
		}
		i++;
	}	
}

void	*ft_print_memory(void *address, unsigned int size)
{
	unsigned char	*memory;
	unsigned int	i;
	unsigned int	bytes;

	memory = (unsigned char *)address;
	i = 0;
	while (i < size)
	{
		if (size - i >= 16)
			bytes = 16;
		else
			bytes = size - i;

		ft_putaddress((unsigned long)(memory + i));
		write(1, ":", 1);
		write(1, " ", 1);

		ft_print_hex_line(memory + i, bytes);

		ft_print_char_line(memory + i, bytes);

		write(1, "\n", 1);

		i += 16;
	}
	return (address);
}

int	main(int argc, char *argv[])
{
	unsigned	int	size;

	if (argc != 2)
	{
		return (1);
	}
	size = 0;
	while (argv[1][size] != '\0')
	{
		size++;		
	}
	ft_print_memory(argv[1], size);
	return (0);
}


/*int	main(void)
{
	char str[] = "abc";

	ft_putaddr((unsigned long)str);
	ft_putchar('\n');
	return (0);
}*/
