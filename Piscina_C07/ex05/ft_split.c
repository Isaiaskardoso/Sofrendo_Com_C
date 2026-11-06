/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kardoso <kardoso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:59:58 by kardoso           #+#    #+#             */
/*   Updated: 2026/11/05 23:41:44 by kardoso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	<stdlib.h>

static	int	is_sep(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
		{
			return (1);
		}
		charset++;		
	}
	return (0);	
}

static	int	count_words(char *str, char *charset)
{
	int count;
	int in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (!is_sep(*str, charset) && !in_word)
		{			
			in_word = 1;
			count++;			
		}
		else if (is_sep(*str, charset))
		{
			in_word = 0;
		}
		str++;		
	}
	return (count);	
}

static	char	*copy_word(char *start, int len)
{
	char	*word;
	int	i;

	word = (char *)malloc(len + 1);
	if (!word)
	{
		return (0);
	}
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);	
}

static	void	free_all(char **arr, int n)
{
	while (n > 0)
	{
		free(arr[--n]);		
	}
	free(arr);
	
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int	len;
	int i;

	res = (char **)malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (!res)
	{
		return (0);
	}
	i = 0;
	while (*str)
	{
		while (*str && is_sep(*str, charset))
		{
			str++;
		}
		if (!*str)
		{
			break;
		}
		len = 0;
		while (str[len] && !is_sep(str[len], charset))
		{
			len++;
		}
		res[i] = copy_word(str, len);
		if (!res[i])
		{
			free_all(res, i);
			return (0);
		}
		i++;
		str += len;		
	}
	res[i] = 0;
	return (res);
}
