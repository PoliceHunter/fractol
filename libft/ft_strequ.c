/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:12:09 by pferdina          #+#    #+#             */
/*   Updated: 2019/09/18 18:48:15 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int	len1;
	int	len2;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		if (len1 == 0 && len2 == 0)
			return (1);
		else if (len1 == 0 || len2 == 0)
			return (0);
		else
		{
			while (len1 >= 0)
			{
				if (s1[len1] != s2[len1])
					return (0);
				len1--;
			}
			return (1);
		}
	}
	return (0);
}
