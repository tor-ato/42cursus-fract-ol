/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:56:21 by tkitahar          #+#    #+#             */
/*   Updated: 2024/09/27 15:40:09 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include <stdio.h>

int	close_handler(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_conection, fractol->data.data_ptr);
	mlx_destroy_window(fractol->mlx_conection, fractol->mlx_window);
	mlx_destroy_display(fractol->mlx_conection);
	free(fractol->mlx_conection);
	exit(EXIT_SUCCESS);
}

int	mouse_handler(int button, int x, int y, t_fractol *fractol)
{
	if (button == Button4)
	{
		fractol->zoom *= 0.95;
		fractol->shift_y += (0.1 * fractol->zoom);
		fractol->shift_x -= (0.1 * fractol->zoom);
	}
	else if (button == Button5)
	{
		fractol->zoom *= 1.05;
		fractol->shift_y += (0.1 * fractol->zoom);
		fractol->shift_x -= (0.1 * fractol->zoom);
	}
	render_fractol(fractol);
	return (0);
}

int	key_press_handler(int keysym, t_fractol *fractol)
{
	if (keysym == XK_Escape)
		close_handler(fractol);
	else if (keysym == MY_XK_PLUS)
		fractol->max_iteration += 10;
	else if (keysym == XK_minus)
		fractol->max_iteration -= 10;
	else if (keysym == XK_Up)
		fractol->shift_y += (0.1 * fractol->zoom);
	else if (keysym == XK_Down)
		fractol->shift_y -= (0.1 * fractol->zoom);
	else if (keysym == XK_Left)
		fractol->shift_x -= (0.1 * fractol->zoom);
	else if (keysym == XK_Right)
		fractol->shift_x += (0.1 * fractol->zoom);
	render_fractol(fractol);
	return (0);
}
