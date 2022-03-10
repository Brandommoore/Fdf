/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresen_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:07:46 by mcordoba          #+#    #+#             */
/*   Updated: 2022/03/10 18:02:59 by mcordoba         ###   ########.fr       */
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

void	bresen_alg(t_data *fdf)
{
	float	step_x;
	float	step_y;
	int		max;
	int		z;
	int		z1;

	z = fdf->points[(int)fdf->bresshem.x][(int)fdf->bresshem.y].value;
	z1 = fdf->points[(int)fdf->bresshem.x1][(int)fdf->bresshem.y1].value;

	printf("z_value --> %d\nz1_value --> %d\n", z, z1);

	zoom(fdf);
	isometric(&(fdf->bresshem.x), &(fdf->bresshem.y), z);
	isometric(&(fdf->bresshem.x1), &(fdf->bresshem.y1), z1);
	shift_map(fdf);
	step_x = fdf->bresshem.x1 - fdf->bresshem.x;
	step_y = fdf->bresshem.y1 - fdf->bresshem.y;
	max = f_max(f_mod(step_x), f_mod(step_y));
	step_x /= max;
	step_y /= max;
	while ((int)(fdf->bresshem.x - fdf->bresshem.x1)
			|| (int)(fdf->bresshem.y - fdf->bresshem.y1))
	{
		my_mlx_pixel_put(fdf, fdf->bresshem.x,
			fdf->bresshem.y, fdf->bresshem.color);
		fdf->bresshem.x += step_x;
		fdf->bresshem.y += step_y;
	}
}

//Terniary
//MAX1 (a, b) (a > b ? a :b)
// si a > b devuelve a, sino devuelve b

//MOD (a) ((a < 0) ? -a : a)
// si a < 0 devuelve -a (num pos) sino devuelve a (siempre devolver positivo)
