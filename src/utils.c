/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:38:05 by tkitahar          #+#    #+#             */
/*   Updated: 2024/09/24 19:46:08 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

t_complex_num	sum_complexnum(t_complex_num z1, t_complex_num z2)
{
	t_complex_num	summed;

	summed.r = z1.r + z2.r;
	summed.i = z1.i + z2.i;
	return (summed);
}

t_complex_num	squares_complexnum(t_complex_num z)
{
	t_complex_num	squared;

	squared.r = (z.r * z.r) - (z.i * z.i);
	squared.i = 2 * z.r * z.i;
	return (squared);
}

double	scale(double unscaled_positon,
					double new_min,
					double new_max,
					double old_min,
					double old_max)
{
	return ((new_max - new_min) * (unscaled_positon - old_min)
		/ (old_max - old_min) + new_min);
}
