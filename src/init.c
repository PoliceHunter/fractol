/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmyrcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:49:30 by tmyrcell          #+#    #+#             */
/*   Updated: 2020/11/10 18:49:32 by tmyrcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		terminate(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	data_delete(data);
	exit(1);
}

t_data	*data_init(t_data *data, char *fractal)
{
	if (!(data = (t_data*)malloc(sizeof(t_data))))
		stop(DATA_ERROR);
	if (ft_strcmp(fractal, "1") == 0)
		data->type = 1;
	else if (ft_strcmp(fractal, "2") == 0)
		data->type = 2;
	else if (ft_strcmp(fractal, "3") == 0)
		data->type = 3;
	else
	{
		free(data);
		stop_usage(UE1);
	}
	return (data);
}

void	fractal_init(t_data *data)
{
	mandelbrot_init(data);
	ft_pthread(data);
}

void	controls_init(t_data *data)
{
	mlx_hook(data->win, 17, 0, terminate, data);
	mlx_hook(data->win, 2, 0, key_pressed, data);
	mlx_hook(data->win, 4, 0, mouse_pressed, data);
	mlx_hook(data->win, 6, 0, mouse_move, data);
}

void	window_init(t_data *data)
{
	if (!(data->mlx = mlx_init()))
	{
		data_delete(data);
		stop(INIT_ERROR);
	}
	if (!(data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fractol")))
	{
		data_delete(data);
		stop(INIT_ERROR);
	}
	if (!(data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT)))
	{
		data_delete(data);
		stop(INIT_ERROR);
	}
	if (!(data->img_ptr = (int*)mlx_get_data_addr(data->img, &data->bpp,
	&data->size_line, &data->endian)))
	{
		data_delete(data);
		stop(INIT_ERROR);
	}
	fractal_init(data);
	controls_init(data);
}
