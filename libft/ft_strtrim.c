/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <pferdina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:17:15 by pferdina          #+#    #+#             */
/*   Updated: 2019/12/26 15:32:44 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		i;
	char	*res;
	int		len;

	res = NULL;
	if (s)
	{
		start = 0;
		end = ft_strlen(s) - 1;
		while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
			start++;
		while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
			end--;
		len = (end > start ? end - start : -1);
		res = (char*)malloc(sizeof(char) * (len + 2));
		if (!res)
			return (NULL);
		i = 0;
		while (start <= end)
			res[i++] = s[start++];
		res[i] = '\0';
	}
	return (res);
}
