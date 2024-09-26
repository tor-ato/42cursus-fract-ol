/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:08:45 by tkitahar          #+#    #+#             */
/*   Updated: 2024/09/24 19:59:05 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	my_pixel_put(t_data *data, int x, int y, int color)
{
	int	offset;

	offset = (data->bits_per_line * y) + (x * (data->bits_per_pixel / 8));
	*((unsigned int *)(offset + data->image_ptr)) = color;
}

static void	calculate_pixel(int x, int y, t_fractol *fractol)
{
	t_complex_num	z;
	t_complex_num	c;
	int				i;
	int				color;

	i = 0;
	z.r = 0.0;
	z.i = 0.0;
	c.r = scale(x, -2, +2, 0, WIDTH);
	c.i = scale(y, +2, -2, 0, HIGHT);
	while (i < fractol->max_iteration)
	{
		z = sum_complexnum(squares_complexnum(z), c);
		if ((z.r * z.r) + (z.i * z.i) > fractol->escape_value)
		{
			color = scale(i, WHITE, RED, 0, fractol->max_iteration);
			my_pixel_put(&fractol->data, x, y, color);
			return ;
		}
		i++;
	}
}

void	render_fractol(t_fractol *fractol)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			calculate_pixel(x, y, fractol);
		}
	}
	mlx_put_image_to_window(fractol->mlx_conection,
		fractol->mlx_window,
		fractol->data.data_ptr,
		0, 0);
}
