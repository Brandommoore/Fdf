/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:38:16 by mcordoba          #+#    #+#             */
/*   Updated: 2022/02/24 20:57:44 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	print_map(t_data fdf)
{
	int x;
	int y;
	int px;
	int py;

	px = 0;
	py = 0;
	//fdf.cord.px = 15;
	//fdf.cord.py = 15;
	y = 0;
	while (y <= 9)
	{
		x = 0;
		while (x <= 9)
		{
			py = line_y(fdf, py, fdf.points[x][y].color);
			px = line_x(fdf, px, fdf.points[x][y].color);
			x++;
		}
		y++;
	}
}

void	print_values_console(t_data *fdf)
{
	int x;
	int y;

	printf("map_height --> %d\nmap_width --> %d\n", fdf->map.height, fdf->map.height);

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