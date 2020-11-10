/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:35:11 by pferdina          #+#    #+#             */
/*   Updated: 2019/09/19 12:28:14 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*temp;
	unsigned char		*const_temp;

	if (dst || src)
	{
		temp = (unsigned char*)dst;
		const_temp = (unsigned char*)src;
		while (n-- > 0)
			*temp++ = *const_temp++;
		return (dst);
	}
	return (NULL);
}
