/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IsaiasKardoso <isaiaskardososilva@gmail    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 12:45:50 by IsaiasKardo       #+#    #+#             */
/*   Updated: 2026/07/17 23:40:00 by IsaiasKardo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}	
}

int	ft_atoi(char *str)
{
	int i;
	int sign;
	int result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign *= -1;
		}
		i++;		
	}
	while (str[i] >='0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

unsigned	int	ft_putlen(char *str)
{
	unsigned	int i;
	
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned	int	dest_len;
	unsigned	int	src_len;
	unsigned	int i;

	src_len = ft_putlen(src);
	dest_len = 0;
	while (dest_len < size && dest[dest_len])
	{
		dest_len++;
	}
	if (dest_len == size)
	{
		return (size + src_len);
	}
	i = 0;
	while (src[i] && (dest_len + i + 1) < size)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);	
}

int main(int argc, char *argv[])
{
    char buffer[100];
    unsigned int size;
    int j;
    
    if (argc != 4)
    {
        ft_putstr("Uso: ./a.out <dest> <src> <size>\n");
        ft_putstr("Ex de uso: ./a.out\"Hello\"\"World\" 20\n");
        return (0);
    }
    j = 0;
    while (argv[1][j] && j < 99)
    {
        buffer[j] = argv[1][j];
        j++;
    }
    buffer[j] = '\0';
    size = ft_atoi(argv[3]);
    ft_strlcat(buffer, argv[2], size);
    ft_putstr("Buffer final: ");
    ft_putstr(buffer);
    write(1, "\n", 1);     
    return (0);    
}