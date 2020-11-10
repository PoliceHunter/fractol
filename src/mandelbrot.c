/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmyrcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:49:44 by tmyrcell          #+#    #+#             */
/*   Updated: 2020/11/10 18:49:46 by tmyrcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_draw(t_data *data)
{
	data->z = init_complex(data->z.xk * data->z.xk - data->z.yk
	* data->z.yk + data->coord.xk, 2.0 * data->z.xk
	* data->z.yk + data->coord.yk);
	data->iter++;
}

void	julia_draw(t_data *data)
{
	data->z = init_complex(data->z.xk * data->z.xk - data->z.yk
	* data->z.yk + data->julia1, 2.0 * data->z.xk * data->z.yk
	+ data->julia2);
	data->iter++;
}

void	ship_draw(t_data *data)
{
	data->z = init_complex(fabs(data->z.xk * data->z.xk
	- data->z.yk * data->z.yk + data->coord.xk), -fabs(2.0
	* data->z.xk * data->z.yk + data->coord.yk));
	data->iter++;
}

t_data	*drawdraw(t_data *data)
{
	if (data->iter == data->max_iter)
		data->img_ptr[data->y * data->size_line
		/ 4 + data->x] = data->color_frt;
	else
	{
		if (data->iter == 0)
			data->img_ptr[data->y * data->size_line
			/ 4 + data->x] = data->color_bkg;
		else
		{
			if (data->color_bkg == 0x000000)
				data->img_ptr[data->y * data->size_line
				/ 4 + data->x] = data->color_bkg + (255
				/ data->max_iter * data->iter) * 65793;
			else
				data->img_ptr[data->y * data->size_line
				/ 4 + data->x] = abs(data->color_bkg - data->color_frt)
				/ data->max_iter * data->iter;
		}
	}
	return (data);
}
