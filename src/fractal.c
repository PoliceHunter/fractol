/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmyrcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:49:24 by tmyrcell          #+#    #+#             */
/*   Updated: 2020/11/10 18:49:26 by tmyrcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	init_complex(double xk, double yk)
{
	t_complex	complex;

	complex.xk = xk;
	complex.yk = yk;
	return (complex);
}

void		ne_vlezlo(t_data *data)
{
	data->coord.xk = (data->min.xk + data->x * data->scale.xk)
		/ data->zoom + data->move_x;
	data->z = init_complex(data->coord.xk, data->coord.yk);
	data->iter = 0;
	while (data->z.xk * data->z.xk + data->z.yk * data->z.yk <= 4
		&& data->iter < data->max_iter)
	{
		if (data->type == 1)
			mandelbrot_draw(data);
		else if (data->type == 2)
			julia_draw(data);
		else if (data->type == 3)
			ship_draw(data);
	}
	drawdraw(data);
	data->x++;
}

void		*fractal_draw(void *tab)
{
	t_data		*data;

	data = (t_data *)tab;
	while (data->y < data->ymax)
	{
		data->coord.yk = (data->max.yk - data->y * data->scale.yk)
		/ data->zoom + data->move_y;
		data->x = 0;
		while (data->x < WIDTH)
		{
			ne_vlezlo(data);
		}
		data->y++;
	}
	pthread_exit(NULL);
}

void		mandelbrot_init(t_data *data)
{
	data->min.xk = -2.0;
	data->min.yk = -2.0;
	data->max.xk = 2.0;
	data->max.yk = data->min.yk + (data->max.xk - data->min.xk)
		* HEIGHT / WIDTH;
	data->color_frt = 0xFFFFFF;
	data->color_bkg = 0x000000;
	data->scale = init_complex(
		(data->max.xk - data->min.xk) / (WIDTH - 1),
		(data->max.yk - data->min.yk) / (HEIGHT - 1));
	data->max_iter = 50;
	data->zoom = 1.0;
	data->julia1 = -0.70176;
	data->julia2 = -0.3842;
	data->mouse_is_pressed = 0;
	data->move_x = 0.0;
	data->move_y = 0.0;
}

void		ft_pthread(t_data *data)
{
	t_data		tab[THREADS];
	pthread_t	t[THREADS];
	int			i;

	i = 0;
	while (i < THREADS)
	{
		ft_memcpy((void *)&tab[i], (void *)data, sizeof(t_data));
		tab[i].y = THR_H * i;
		tab[i].ymax = THR_H * (i + 1);
		i += 1;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_create(&t[i], NULL, fractal_draw, &tab[i]);
		i += 1;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	menushka(data);
}
