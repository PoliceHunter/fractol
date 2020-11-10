/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:48:20 by pferdina          #+#    #+#             */
/*   Updated: 2019/09/18 21:25:37 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	len1;
	size_t	len2;
	size_t	i;

	i = 0;
	if (s1 && s2 && n)
	{
		len1 = (size_t)ft_strlen(s1);
		len2 = (size_t)ft_strlen(s2);
		if (len1 == 0 && len2 == 0)
			return (1);
		else if (len1 == 0 || len2 == 0)
			return (0);
		else
		{
			while ((s1[i] || s2[i]) && n--)
			{
				if (s1[i] != s2[i])
					return (0);
				i++;
			}
			return (1);
		}
	}
	return (1);
}
