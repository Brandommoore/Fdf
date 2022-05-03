/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bress_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:19:24 by mcordoba          #+#    #+#             */
/*   Updated: 2022/03/14 11:24:07 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	bress_pixel_print(t_data *fdf, float step_x, float step_y)
{
	my_mlx_pixel_put(fdf, fdf->bresshem.x,
		fdf->bresshem.y, fdf->bresshem.color);
	fdf->bresshem.x += step_x;
	fdf->bresshem.y += step_y;
}
