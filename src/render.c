/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:08:45 by tkitahar          #+#    #+#             */
/*   Updated: 2024/09/27 15:24:20 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	my_pixel_put(t_data *data, int x, int y, int color)
{
	int	offset;

	offset = (data->bits_per_line * y) + (x * (data->bits_per_pixel / 8));
	*(unsigned int *)(offset + data->image_ptr) = color;
}

static void	init_c_mandel_or_julia(t_complex_num *z,
		t_complex_num *c,
		t_fractol *fractol)
{
	if (ft_strcmp(fractol->title, "julia") == STRCMP_OK)
	{
		c->r = fractol->julia_x;
		c->i = fractol->julia_y;
	}
	else
	{
		c->r = z->r;
		c->i = z->i;
	}
}

static void	calculate_pixel(int x, int y, t_fractol *fractol)
{
	t_complex_num	z;
	t_complex_num	c;
	int				i;
	int				color;

	i = 0;
	z.r = (scale(x, -2, +2, WIDTH) * fractol->zoom) + fractol->shift_x;
	z.i = (scale(y, +2, -2, HEIGHT) * fractol->zoom) + fractol->shift_y;
	color = 0;
	init_c_mandel_or_julia(&z, &c, fractol);
	while (i < fractol->max_iteration)
	{
		z = sum_complexnum(square_complexnum(z), c);
		if ((z.r * z.r) + (z.i * z.i) > fractol->escape_value)
		{
			color = scale(i, WHITE, BLACK, fractol->max_iteration);
			my_pixel_put(&fractol->data, x, y, color);
			return ;
		}
		++i;
	}
	my_pixel_put(&fractol->data, x, y, color);
}

void	render_fractol(t_fractol *fractol)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			calculate_pixel(x, y, fractol);
	}
	mlx_put_image_to_window(fractol->mlx_conection,
		fractol->mlx_window,
		fractol->data.data_ptr,
		0, 0);
}
