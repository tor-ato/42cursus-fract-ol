/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:17:13 by tkitahar          #+#    #+#             */
/*   Updated: 2024/09/26 13:10:25 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	init_data(t_fractol *fractol)
{
	fractol->escape_value = 4;
}

void	init_fractol(t_fractol *fractol)
{
	my_mlx_init(fractol);
	my_mlx_new_window(fractol);
	my_mlx_new_image(fractol);
	my_mlx_get_data_addr(fractol);
	init_data(fractol);
}
