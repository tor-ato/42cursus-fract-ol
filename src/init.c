/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:17:13 by tkitahar          #+#    #+#             */
/*   Updated: 2024/09/24 19:08:02 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	malloc_error(void)
{
	perror("Problem whith malloc");
	exit(EXIT_FAILURE);
}

void	data_init(t_fractol *fractol)
{
	fractol->escape_value = 4;
}

void	init_fractol(t_fractol *fractol)
{
	fractol->mlx_conection = mlx_init();
	if (!fractol->mlx_conection)
		malloc_error();
	fractol->mlx_window = mlx_new_window(fractol->mlx_conection,
										WIDTH,
										HIGHT,
										fractol->title);
	if (!fractol->mlx_window)
	{
		mlx_destroy_display(fractol->mlx_conection);
		free(fractol->mlx_conection);
		malloc_error();
	}
	fractol->data.data_ptr = mlx_new_image(fractol->mlx_conection,
										WIDTH,
										HIGHT);
	if (!fractol->data.data_ptr)
	{
		mlx_destroy_window(fractol->mlx_conection, fractol->mlx_window);
		mlx_destroy_display(fractol->mlx_conection);
		free(fractol->mlx_conection);
		malloc_error();
	}
	fractol->data.image_ptr = mlx_get_data_addr(fractol->data.data_ptr,
												&fractol->data.bits_per_pixel,
												&fractol->data.bits_per_line,
												&fractol->data.endian);
	data_init(fractol);
}
