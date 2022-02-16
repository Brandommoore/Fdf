/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:37:37 by mcordoba          #+#    #+#             */
/*   Updated: 2022/02/16 19:44:21 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	line_y(t_data fdf, int width, int color)
{
	int	j;

	j = 0;
	while (j <= width)
	{
		my_mlx_pixel_put(&fdf, fdf.cord.px, fdf.cord.py + j, color);
		j++;
	}
	return (j + fdf.cord.py);
}

int	line_x(t_data fdf, int width, int color)
{
	int	j;

	j = 0;
	while (j <= width)
	{
		my_mlx_pixel_put(&fdf, fdf.cord.px + j, fdf.cord.py, color);
		j++;
	}
	return (j + fdf.cord.px);
}

