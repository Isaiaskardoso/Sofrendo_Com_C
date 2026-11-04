/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kardoso <kardoso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 21:26:20 by kardoso           #+#    #+#             */
/*   Updated: 2026/10/22 18:14:15 by kardoso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
    int	i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

char	*ft_strdup(char *src)
{
    char    *dest;
    int        i;

    dest = (char *)malloc(ft_strlen(src) + 1);
	if (dest == 0)
	{
		return (0);
	}
	i = 0;
    while (src[i] != 0)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

int main(int argc, char *argv[])
{
	char	*dest;
	int pos;
	int i;

	i = 1;
	while (i < argc)
	{
		dest = ft_strdup(argv[i]);
		if (dest == 0)
		{
			return (1);
		}
		pos = 0;
		while (dest[pos] != '\0')
		{
			ft_putchar(dest[pos]);
			pos++;			
		}
		i++;		
		
		ft_putchar('\n');
		free(dest);
	}
	return (0);
}
