/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresen_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:07:46 by mcordoba          #+#    #+#             */
/*   Updated: 2022/03/15 12:34:24 by mcordoba         ###   ########.fr       */
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

static float	f_mod(float a)
{
	if (a < 0)
		return (a * -1);
	else
		return (a);
}

static void	zoom(t_data *fdf)
{
	fdf->bresshem.x *= fdf->m_control.zoom;
	fdf->bresshem.y *= fdf->m_control.zoom;
	fdf->bresshem.x1 *= fdf->m_control.zoom;
	fdf->bresshem.y1 *= fdf->m_control.zoom;
}

static void	color(int z, t_data *fdf)
{
	if (z)
		fdf->bresshem.color = 0x115500 * 2
			* fdf->m_control.color_hue * fdf->m_control.color_hue;
	else
	{
		fdf->bresshem.color = 0x005511 * 2
			* fdf->m_control.color_hue * fdf->m_control.color_hue;
	}
}

void	bresen_alg(t_data *fdf)
{
	float	step_x;
	float	step_y;
	int		max;
	int		z;
	int		z1;

	z = z_value(fdf);
	z1 = z1_value(fdf);
	zoom(fdf);
	color(z, fdf);
	isometric(fdf, &(fdf->bresshem.x), &(fdf->bresshem.y), z);
	isometric(fdf, &(fdf->bresshem.x1), &(fdf->bresshem.y1), z1);
	shift_map(fdf);
	step_x = fdf->bresshem.x1 - fdf->bresshem.x;
	step_y = fdf->bresshem.y1 - fdf->bresshem.y;
	max = f_max(f_mod(step_x), f_mod(step_y));
	step_x /= max;
	step_y /= max;
	while ((int)(fdf->bresshem.x - fdf->bresshem.x1)
			|| (int)(fdf->bresshem.y - fdf->bresshem.y1))
	{
		bress_pixel_print(fdf, step_x, step_y);
	}
}

//Terniary
//MAX1 (a, b) (a > b ? a :b)
// si a > b devuelve a, sino devuelve b

//MOD (a) ((a < 0) ? -a : a)
// si a < 0 devuelve -a (num pos) sino devuelve a (siempre devolver positivo)
