/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <pferdina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:26:55 by pferdina          #+#    #+#             */
/*   Updated: 2019/12/27 16:51:03 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char *str, char c)
{
	size_t	counter;
	int		flag;

	counter = 0;
	flag = 0;
	while (*str)
	{
		if (*str != c && flag == 0)
		{
			counter++;
			flag = 1;
		}
		else if (*str == c)
			flag = 0;
		str++;
	}
	return (counter);
}

static char		**free_mem(char **res, size_t words)
{
	size_t	j;

	j = 0;
	while (j < words)
		free(res[j++]);
	free(res);
	res = NULL;
	return (res);
}

static char		**generate_res(char **res, size_t words, char const *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	start = 0;
	end = 0;
	while (i < words)
	{
		while (s[end] != c && s[end])
			end++;
		res[i] = ft_strsub(s, (unsigned int)start, end - start);
		if (!res[i])
			return (free_mem(res, words));
		start = end;
		while (s[start] == c)
			start++;
		end = start;
		i++;
	}
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	char	*str;
	char	**res;
	size_t	words_counter;

	if (s && c)
	{
		str = ft_strctrim(s, c);
		if (!str)
			return (NULL);
		words_counter = count_words(str, c);
		res = (char**)malloc(sizeof(char*) * (words_counter + 1));
		if (!res)
			return (NULL);
		res[words_counter] = 0;
		res = generate_res(res, words_counter, str, c);
		free(str);
		return (res);
	}
	return (NULL);
}
