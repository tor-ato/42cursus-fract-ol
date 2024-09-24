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

void	calculate_pixel(int x,int y, t_fractol *fractol)
{
	t_complex_num	z;
	t_complex_num	c;
	int				i;

	i = 0;
	z.r = 0.0;
	z.i = 0.0;
	c.r = scale_position(x, -2, +2, 0, WIDTH);
	c.i = scale_position(y, +2, -2, 0, HIGHT);
	while (i < MAX_ITRATION) 
	{
		z = sum_complexnum(squares_complexnum(z), c);

		if ((z.r * z.r) + (z.i * z.i) > ESCAPE_VALUE)
		{
			my_pixel_put();
			return ;
		}
	}
	

	
}

void	render_fractol(t_fractol *fractol)
{
	int x;
	int y;

	y  = -1;
	while (++y < HIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			calculate_pixel(x, y, fractol);
		}
	}
	mlx_put_image_to_window(fractol->mlx_conection, fractol->mlx_window, fractol->data.img_ptr, 0, 0);
}
