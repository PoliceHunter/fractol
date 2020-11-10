/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 22:04:03 by pferdina          #+#    #+#             */
/*   Updated: 2019/09/18 00:11:38 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	match(char *str, char *substr)
{
	while (*substr)
	{
		if (*str == *substr)
		{
			str++;
			substr++;
		}
		else
			return (0);
	}
	return (1);
}

char		*ft_strstr(const char *s1, const char *s2)
{
	char	*str;
	char	*substr;

	str = (char *)s1;
	substr = (char *)s2;
	if (*substr == 0)
		return (str);
	while (*str)
	{
		if (*str == *substr)
			if (match(str, substr))
				return (str);
		str++;
	}
	return (NULL);
}
