/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wdcounter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferdina <pferdina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 15:22:01 by pferdina          #+#    #+#             */
/*   Updated: 2019/12/26 20:04:21 by pferdina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wdcounter(char *str, char c)
{
	size_t	counter;
	int		flag;

	counter = 0;
	flag = 0;
	while (*str)
	{
		if (*str != c && flag == 0)
		{
			counter++;
			flag = 1;
		}
		else if (*str == c)
			flag = 0;
		str++;
	}
	return (counter);
}
