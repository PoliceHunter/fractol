/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmyrcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:29:24 by tmyrcell          #+#    #+#             */
/*   Updated: 2020/11/10 18:29:26 by tmyrcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	stop(char *s)
{
	ft_putendl(s);
	exit(1);
}

void	data_delete(t_data *data)
{
	free(data);
}

void	stop_usage(char *s)
{
	ft_putendl(s);
	ft_putendl(UE2);
	ft_putendl(UE3);
	ft_putendl(UE4);
	ft_putendl(UE5);
	exit(1);
}

void	menushka(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 20, 15, MC, "Controls");
	mlx_string_put(data->mlx, data->win, 20, 63, MC, "Escape: ECS");
	mlx_string_put(data->mlx, data->win, 20, 83, MC, "Color: C");
	mlx_string_put(data->mlx, data->win, 20, 103, MC,
	"Zoom: +/- or MSCROLL");
	mlx_string_put(data->mlx, data->win, 20, 123, MC, "Fractal: F");
	mlx_string_put(data->mlx, data->win, 20, 143, MC, "Default: D");
	mlx_string_put(data->mlx, data->win, 20, 163, MC, "Move: Arrows");
	if (data->type == 1)
		mlx_string_put(data->mlx, data->win, 850, 970, MC, "Mandelbrot");
	if (data->type == 2)
	{
		mlx_string_put(data->mlx, data->win, 850, 970, MC, "Julia");
		if (data->mouse_is_pressed == 0)
			mlx_string_put(data->mlx, data->win, 800, 15, MC,
			"MOUSE OFF press M");
		if (data->mouse_is_pressed == 1)
			mlx_string_put(data->mlx, data->win, 800, 15, MC,
			"MOUSE ON press M");
	}
	if (data->type == 3)
		mlx_string_put(data->mlx, data->win, 850, 970, MC, "Burning shift");
}

int		main(int ac, char **av)
{
	t_data	*data;

	data = NULL;
	if (ac == 2)
	{
		data = data_init(data, av[1]);
		window_init(data);
		mlx_loop(data->mlx);
	}
	stop_usage(UE1);
}
