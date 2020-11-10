/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:32:40 by pferdina          #+#    #+#             */
/*   Updated: 2019/09/17 19:17:15 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp;

	if (n)
	{
		temp = (unsigned char*)s;
		while (n--)
			if (*temp++ == (unsigned char)c)
				return ((void*)(temp - 1));
	}
	return (NULL);
}
