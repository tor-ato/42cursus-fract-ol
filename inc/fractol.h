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
# include "../mlx/mlx_int.h"

# define STRCMP_OK	0
# define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"
# define WIDTH 800
# define HIGHT 800
# define MANDELBROT_ARGC 2
# define JULIA_ARGC 4

#define BLACK    	0x000000
#define WHITE      	0xFFFFFF
#define RED         0xFF0000
#define GREEN       0x00FF00
#define BLUE        0x0000FF

#define MAGENTA_BURST	   	0xFF00FF
#define LIME_SHOCK     		0xCCFF00
#define NEON_ORANGE     	0xFF6600
#define PSYCHEDELIC_PURPLE 	0x660066
#define AQUA_DREAM      	0x33CCCC
#define HOT_PINK        	0xFF66B2
#define ELECTRIC_BLUE   	0x0066FF
#define LAVA_RED        	0xFF3300

typedef struct	s_comolex_num
{
	double	r;
	double	i;
}			t_complex_num;

typedef struct	s_data
{
	void	*data_ptr;
	char	*image_ptr;
	int		endian;
	int		bits_per_pixel;
	int		bits_per_line;

}			t_data;

typedef struct s_fractol
{
	char	*title;

	void	*mlx_conection;
	void	*mlx_window;

	t_data	data;
	double	escape_value;
	int		max_iteration;	
	
}			t_fractol;

void	init_fractol(t_fractol *fractol);
void	render_fractol(t_fractol *fractol);

t_complex_num	sum_complexnum(t_complex_num z1, t_complex_num z2);
t_complex_num 	squares_complexnum(t_complex_num z);
double			scale(double unscaled_positon,
					double new_min,
					double new_max,
					double old_min,
					double old_max);
#endif
