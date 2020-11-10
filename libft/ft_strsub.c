/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <pferdina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:05:59 by pferdina          #+#    #+#             */
/*   Updated: 2019/12/26 15:32:46 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;

	res = NULL;
	if (s)
	{
		res = (char*)malloc(sizeof(char) * (len + 1));
		if (!res)
			return (NULL);
		s += start;
		res[len] = '\0';
		while (len--)
			res[len] = s[len];
	}
	return (res);
}
