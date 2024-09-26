/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:15:06 by tkitahar          #+#    #+#             */
/*   Updated: 2024/09/24 16:40:41 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (!((argc == MANDELBROT_ARGC
				&& ft_strcmp(argv[1], "mandelbrot") == STRCMP_OK)
			|| (argc == JULIA_ARGC
				&& ft_strcmp(argv[1], "julia") == STRCMP_OK)))
	{
		ft_dprintf(STDERR_FILENO, ERROR_MESSAGE);
		exit(EXIT_FAILURE);
	}
	fractol.title = argv[1];
	init_fractol(&fractol);
	render_fractol(&fractol);
	mlx_loop(fractol.mlx_conection);
}
