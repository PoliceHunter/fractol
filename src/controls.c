/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmyrcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:49:17 by tmyrcell          #+#    #+#             */
/*   Updated: 2020/11/10 18:49:19 by tmyrcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_pressed(int key, t_data *data)
{
	if (key == ESC)
		terminate(data);
	if (key == PLUS)
		data->zoom *= 1.05;
	if (key == MINUS)
		data->zoom /= 1.05;
	if (key == COLOR)
	{
		data->color_frt = rand() % 16777215;
		data->color_bkg = rand() % 16777215;
	}
	if (key == CHANGE)
	{
		data->zoom = 1.0;
		data->move_x = 0.0;
		data->move_y = 0.0;
		data->type += 1;
		if (data->type > 3)
			data->type = 1;
	}
	key_pressed2(key, data);
	ft_pthread(data);
	return (key);
}

void	key_pressed2(int key, t_data *data)
{
	if (key == UP)
		data->move_y -= (0.1 / data->zoom);
	if (key == DOWN)
		data->move_y += (0.1 / data->zoom);
	if (key == LEFT)
		data->move_x += (0.1 / data->zoom);
	if (key == RIGHT)
		data->move_x -= (0.1 / data->zoom);
	if (key == MOUSE_ONOFF)
	{
		if (data->mouse_is_pressed == 0)
			data->mouse_is_pressed = 1;
		else
			data->mouse_is_pressed = 0;
	}
	if (key == D)
	{
		data->zoom = 1.0;
		data->move_x = 0.0;
		data->move_y = 0.0;
		data->color_frt = 0xFFFFFF;
		data->color_bkg = 0x000000;
	}
}

int		mouse_pressed(int button, int x, int y, t_data *data)
{
	if (button == 5 || button == 4)
	{
		data->but = button;
		zoom_in(x, y, data);
	}
	return (0);
}

void	zoom_in(int x, int y, t_data *data)
{
	if (y >= 0 && x >= 0 && x < WIDTH && y < HEIGHT)
	{
		if (data->but == 4)
		{
			data->move_x += ((data->min.xk + x * data->scale.xk)
				/ data->zoom * 1.05 + data->move_x) - ((data->min.xk + x *
				data->scale.xk) / data->zoom + data->move_x);
			data->move_y += ((data->max.yk - y * data->scale.yk)
				/ data->zoom * 1.05 + data->move_y) - ((data->max.yk - y *
				data->scale.yk) / data->zoom + data->move_y);
			data->zoom *= 1.05;
		}
		if (data->but == 5)
		{
			data->move_x += ((data->min.xk + x * data->scale.xk)
			/ data->zoom / 1.05 + data->move_x) - ((data->min.xk + x *
			data->scale.xk) / data->zoom + data->move_x);
			data->move_y += ((data->max.yk - y * data->scale.yk)
			/ data->zoom / 1.05 + data->move_y) - ((data->max.yk - y *
			data->scale.yk) / data->zoom + data->move_y);
			data->zoom /= 1.05;
		}
		ft_pthread(data);
	}
}

int		mouse_move(int x, int y, t_data *data)
{
	data->m_prev_x = data->mouse_x;
	data->m_prev_y = data->mouse_y;
	data->mouse_x = x;
	data->mouse_y = y;
	if (data->mouse_is_pressed == 1)
	{
		data->julia1 += (x - data->m_prev_x) * 0.001;
		data->julia2 -= (y - data->m_prev_y) * 0.001;
		ft_pthread(data);
	}
	return (0);
}
