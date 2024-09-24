/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:24:31 by tkitahar          #+#    #+#             */
/*   Updated: 2024/09/24 19:55:09 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"
/*# include "../mlx/mlx_int.h"*/

# define STRCMP_OK	0
# define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"
# define WIDTH 800
# define HIGHT 800
# define ESCAPE_VALUE 2
# define MAX_ITRATION 42

typedef struct	s_comolex_num
{
	double	r;
	double	i;
}			t_complex_num;

typedef struct	s_data
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;

}			t_data;

typedef struct s_fractol
{
	char	*title;

	void	*mlx_conection;
	void	*mlx_window;

	t_data	data;
	/*double	escape_value;*/
	
	
}			t_fractol;

void	init_fractol(t_fractol *fractol);
void	render_fractol(t_fractol *fractol);

t_complex_num	sum_complexnum(t_complex_num z1, t_complex_num z2);
t_complex_num squares_complexnum(t_complex_num z);
double	scale_position(double unscaled_positon,
					double new_min,
					double new_max,
					double old_min,
					double old_max);
#endif
