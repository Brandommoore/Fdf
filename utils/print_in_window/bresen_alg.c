/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresen_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:07:46 by mcordoba          #+#    #+#             */
/*   Updated: 2022/03/04 17:10:11 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static float	f_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

static float	f_mod(a)
{
	if (a < 0)
		return (a * -1);
	else
		return (a);
}

void	bresen_alg(float x, float y, float x1, float y1, t_data *fdf)
{
	float	step_x;
	float	step_y;
	int		max;

	step_x = x1 - x;
	step_y = y1 - y;

	max = f_max(f_mod(step_x), f_mod(step_y));
	step_x /= max;
	step_y /= max;

	while ((int)(x - x1) || (int)(y - y1))
	{
		my_mlx_pixel_put(fdf, x, y, 0xffffff);
		x += step_x;
		y += step_y;
	}
}


//Terniary
//MAX1 (a, b) (a > b ? a :b)
// si a > b devuelve a, sino devuelve b

//MOD (a) ((a < 0) ? -a : a)
// si a < 0 devuelve -a (num pos) sino devuelve a (siempre devolver positivo)
