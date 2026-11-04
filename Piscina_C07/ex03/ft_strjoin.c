/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kardoso <kardoso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 12:43:34 by kardoso           #+#    #+#             */
/*   Updated: 2026/10/30 18:21:08 by kardoso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	<stdlib.h>

int	ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);	
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	j = 0;
	while (dest[j] != '\0')
	{
		j++;
	}
	i = 0;
	while (src[i])
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);	
}


char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	int		sep_len;
	int		i;
	char	*result;

	len = 0;
	sep_len = ft_strlen(sep);
	i = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	if (size > 1)
	{
		len += sep_len * (size - 1);
	}
	result = malloc(sizeof(char) * (len + 1));
	if (result == 0)
	{
		return (0);
	}
	result[0] = '\0';
	i = 0;
	while (i < size)// coloca ou não o separador
	{
		ft_strcat(result, strs[i]);
		if (i < size - 1)
			ft_strcat(result, sep);
		i++;
	}
	return (result);
}

int	main(int argc, char *argv[])
{
	char	*result;

	if (argc < 2)
	{
		write(1, "Uso: ./a.out separador [str1 str2 ...]\n", 39);
		return (1);
	}
	result = ft_strjoin(argc - 2, argv + 2, argv[1]);
	if (result == 0)
	{
		return (1);
	}
			
	write(1, result, ft_strlen(result));
	write(1, "\n", 1);
	free(result);
	return (0);
}