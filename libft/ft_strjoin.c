/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <pferdina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 12:37:09 by pferdina          #+#    #+#             */
/*   Updated: 2019/12/26 15:32:52 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*res;

	res = NULL;
	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		res = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
		if (!res)
			return (NULL);
		res = ft_strcpy(res, s1);
		res = ft_strcat(res, (char *)s2);
	}
	return (res);
}
