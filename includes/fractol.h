/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmyrcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:49:59 by tmyrcell          #+#    #+#             */
/*   Updated: 2020/11/10 18:51:00 by tmyrcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <pthread.h>

# define BLU		"\e[96m"
# define FIO		"\e[94m"
# define CLR		"\e[0m"

# define UE1 "\e[96m\n\tHow to use: \e[94m./fractol \e[96m[option]\n\n"
# define UE2 "\e[96m\tAvailable options:\n\e[94m"
# define UE3 "\t\t1 - Mandelbrot\n"
# define UE4 "\t\t2 - Julia set\n"
# define UE5 "\t\t3 - Burning ship\n"

# define INIT_ERROR "Init error"
# define DATA_ERROR "Data init error"

# define WIDTH 1000
# define HEIGHT 1000
# define THREADS 20
# define THR_H 50

# define MANDELBROT 0
# define JULIA 1
# define BURNINGSHIP 2

# define ESC 53
# define PLUS 69
# define MINUS 78
# define COLOR 8
# define CHANGE 3
# define MOUSE_ONOFF 46
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define D 2

# define MC 0xFFFFFF

typedef struct	s_complex
{
	double		yk;
	double		xk;
}				t_complex;

typedef struct	s_data
{
	int			type;
	int			iter;
	int			max_iter;
	int			x;
	int			y;
	int			color_bkg;
	int			color_frt;

	char		mouse_is_pressed;
	int			but;
	int			mouse_x;
	int			mouse_y;
	int			m_prev_x;
	int			m_prev_y;

	t_complex	min;
	t_complex	max;
	t_complex	scale;
	t_complex	coord;
	t_complex	z;

	void		*mlx;
	void		*win;
	void		*img;
	int			*img_ptr;
	int			bpp;
	int			size_line;
	int			endian;
	double		zoom;
	double		move_x;
	double		move_y;
	double		julia1;
	double		julia2;
	double		ymax;
}				t_data;

void			stop(char *s);
t_data			*data_init(t_data *data, char *fractal);
void			fractal_init(t_data *data);
void			window_init(t_data *data);
void			data_delete(t_data *data);
void			mandelbrot_init(t_data *data);
int				key_pressed(int key, t_data *data);
int				mouse_pressed(int button, int x, int y, t_data *data);
int				mouse_move(int x, int y, t_data *data);
int				terminate(t_data *data);
t_complex		init_complex(double re, double im);
void			mandelbrot_draw(t_data *data);
void			julia_draw(t_data *data);
void			ship_draw(t_data *data);
void			newton_draw(t_data *data);
void			*fractal_draw(void *tab);
void			key_pressed2(int key, t_data *data);
void			zoom_in(int x, int y, t_data *data);
t_data			*drawdraw(t_data *data);
void			ft_pthread(t_data *data);
void			menushka(t_data *data);
void			stop_usage(char *s);

#endif
