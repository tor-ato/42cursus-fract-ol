/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:01:10 by tkitahar          #+#    #+#             */
/*   Updated: 2024/09/26 13:05:57 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	malloc_error(void)
{
	perror("Problem whith malloc");
	exit(EXIT_FAILURE);
}

void	my_mlx_init(t_fractol *fractol)
{
	fractol->mlx_conection = mlx_init();
	if (!fractol->mlx_conection)
		malloc_error();
}

void	my_mlx_new_window(t_fractol *fractol)
{
	fractol->mlx_window = mlx_new_window(fractol->mlx_conection,
			WIDTH,
			HEIGHT,
			fractol->title);
	if (!fractol->mlx_window)
	{
		mlx_destroy_display(fractol->mlx_conection);
		free(fractol->mlx_conection);
		malloc_error();
	}
}

void	my_mlx_new_image(t_fractol *fractol)
{
	fractol->data.data_ptr = mlx_new_image(fractol->mlx_conection,
			WIDTH,
			HEIGHT);
	if (!fractol->data.data_ptr)
	{
		mlx_destroy_window(fractol->mlx_conection, fractol->mlx_window);
		mlx_destroy_display(fractol->mlx_conection);
		free(fractol->mlx_conection);
		malloc_error();
	}
}

void	my_mlx_get_data_addr(t_fractol *fractol)
{
	fractol->data.image_ptr = mlx_get_data_addr(fractol->data.data_ptr,
			&fractol->data.bits_per_pixel,
			&fractol->data.bits_per_line,
			&fractol->data.endian);
}
