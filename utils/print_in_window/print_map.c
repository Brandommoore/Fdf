/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:38:16 by mcordoba          #+#    #+#             */
/*   Updated: 2022/03/04 19:20:02 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static void	bress_line_hor(int x, int y, int color, t_data *fdf)
{
	int zoom;

	zoom = fdf->m_control.zoom;
	fdf->bresshem.x = x;
	fdf->bresshem.y = y;
	fdf->bresshem.x1 = x + 1;
	fdf->bresshem.y1 = y;
	fdf->bresshem.color = color;
}

static void	bress_line_ver(int x, int y, int color, t_data *fdf)
{
	int zoom;

	zoom = fdf->m_control.zoom;
	fdf->bresshem.x = x;
	fdf->bresshem.y = y;
	fdf->bresshem.x1 = x;
	fdf->bresshem.y1 = y + 1;
	fdf->bresshem.color = color;
}

void	print_map(t_data *fdf)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < fdf->map.height - 1)
	{
		x = 0;
		while (x < fdf->map.width)
		{
			color = fdf->points[y][x].color;
			bress_line_hor(x, y, color, fdf);
			bresen_alg(fdf);
			bress_line_ver(x, y, color, fdf);
			bresen_alg(fdf);
			x++;
		}
		y++;
	}
}

void	print_values_console(t_data *fdf)
{
	int x;
	int y;

	printf("map_height --> %d\nmap_width --> %d\n", fdf->map.height, fdf->map.width);

	x = 0;
	while (x < fdf->map.height - 1)
	{
		y = 0;
		while (y < fdf->map.width)
		{
			printf("value --> %d\n", fdf->points[x][y].value);
			printf("pos_x --> %d\n", fdf->points[x][y].pos_x);
			printf("pos_y --> %d\n", fdf->points[x][y].pos_y);
			printf("color --> %d\n", fdf->points[x][y].color);
			printf("--------------\n");
			y++;
		}
		x++;
	}
}