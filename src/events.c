/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:56:21 by tkitahar          #+#    #+#             */
/*   Updated: 2024/09/26 16:14:41 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include <X11/Xutil.h>

int	close_handler(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_conection, fractol->data.data_ptr);
	mlx_destroy_window(fractol->mlx_conection, fractol->mlx_window);
	mlx_destroy_display(fractol->mlx_conection);
	free(fractol->mlx_conection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractol *fractol)
{
	if (keysym == XK_Escape)
		close_handler(fractol);
	else if (keysym == XK_plus)
	else if (keysym == XK_minus)
	return 0;
}
