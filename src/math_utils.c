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

t_complex_num	square_complexnum(t_complex_num z)
{
	t_complex_num	squared;

	squared.r = (z.r * z.r) - (z.i * z.i);
	squared.i = 2 * z.r * z.i;
	return (squared);
}

double	scale(
					double unscaled_num,
					double new_min,
					double new_max,
					double old_max)
{
	return ((new_max - new_min) * unscaled_num / old_max + new_min);
}

double	atodbl(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}
