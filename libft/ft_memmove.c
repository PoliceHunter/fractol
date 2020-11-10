/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:37:19 by pferdina          #+#    #+#             */
/*   Updated: 2019/09/19 12:25:15 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp_dst;
	unsigned char	*temp_src;

	if (dst || src)
	{
		temp_dst = (unsigned char *)dst;
		temp_src = (unsigned char *)src;
		if (dst < src)
			return (ft_memcpy(dst, src, len));
		temp_dst += len;
		temp_src += len;
		while (len--)
			*--temp_dst = *--temp_src;
		return (dst);
	}
	return (NULL);
}
