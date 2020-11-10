/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 22:40:07 by pferdina          #+#    #+#             */
/*   Updated: 2019/09/18 00:12:09 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	matchn(char *str, char *substr, size_t len)
{
	while (len && *substr)
	{
		if (*str == *substr)
		{
			str++;
			substr++;
			len--;
		}
		else
			return (0);
	}
	if (*substr)
		return (0);
	return (1);
}

char		*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	char	*str;
	char	*substr;

	str = (char *)s1;
	substr = (char *)s2;
	if (*substr == 0)
		return (str);
	if (len == 0)
		return (NULL);
	while (*str && len)
	{
		if (*str == *substr)
			if (matchn(str, substr, len))
				return (str);
		str++;
		len--;
	}
	return (NULL);
}
