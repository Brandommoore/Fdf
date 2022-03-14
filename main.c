/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 21:54:29 by marvin            #+#    #+#             */
/*   Updated: 2022/03/14 19:32:12 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data	fdf;
	fdf.init = 1;
	errmanag(argc);
	open_map(argv[1], &fdf);
	map_size(&fdf);
	save_map(&fdf);
	close_map(&fdf);
	//fdf.map.width = 50;
	//fdf.map.height = 50;

	//print_map_values(&fdf);
	//printf("JAJAJAJAJAAJA_NO\n");
	//printf("El punto 4-2 tiene por valor --> %d\n", fdf.points[2][2].value);
	//printf("El punto 2-2 tiene por color --> %d\n", fdf.points[2][2].color);
	//str_to_color("0xFF0000");
	//printf("str_to_color --> %d\n", str_to_color("0xFF0000"));

	//print_values_console(fdf);
	

	
	fdf.cord.win_h = 720;
	fdf.cord.win_w = 1080;
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, fdf.cord.win_w, fdf.cord.win_h, "Fdf");
	fdf.img.img = mlx_new_image(fdf.mlx, fdf.cord.win_w, fdf.cord.win_h);
	fdf.img.addr = mlx_get_data_addr(fdf.img.img, &fdf.img.bits_per_pixel, &fdf.img.line_length,
								&fdf.img.endian);
	///offset = (fdf.cord.win_h * fdf.img.line_length + fdf.cord.win_w * (fdf.img.bits_per_pixel / 8));

	//int line_w = line_width(&fdf);
	printf("map_height --> %d\nmap_width --> %d\n", fdf.map.height, fdf.map.width);
	//printf("line_widt ---------------> %d\n", line_w);

	fdf.m_control.zoom = 40;
	fdf.m_control.color_hue = 1.03;
	fdf.m_control.height = 1.2;
	print_map(&fdf);
	// fdf.bresshem.x = 10;
	// fdf.bresshem.y = 10;
	// fdf.bresshem.x1 = 600;
	// fdf.bresshem.y1 = 300;
	// bresen_alg(&fdf);

	// int x;
	// int y;

	// x = 0;
	// while (x < fdf.map.height)
	// {
	// 	y = 0;
	// 	while (y < fdf.map.width)
	// 	{
	// 		printf("value --> %d\n", fdf.points[x][y].value);
	// 		printf("pos_x --> %d\n", fdf.points[x][y].pos_x);
	// 		printf("pos_y --> %d\n", fdf.points[x][y].pos_y);
	// 		printf("color --> %d\n", fdf.points[x][y].color);
	// 		printf("--------------\n");
	// 		y++;
	// 	}
	// 	x++;
	// }
	
	//print_values_console(&fdf);




	//printf("value --> %d\n", fdf.points[9][9].value);
	//printf("pos_x --> %d\n", fdf.points[9][9].pos_x);
	//printf("pos_y --> %d\n", fdf.points[9][9].pos_y);
	//printf("color --> %d\n", fdf.points[9][9].color);

	//print_map(fdf);
	
		// fdf.cord.px = 50;
		// fdf.cord.py = 50;
		// line_x(fdf, 50, 16715760);
		// line_y(fdf, 50, 16715760);
		
	// int c = 0;
	// int px = 50;
	// while (c < 10)
	// {
	// 	px = line_x(img, px, 40 * c, 50);
	// 	c++;
	// }
	// px = 150;
	// c = 0;
	// while (c < 10)
	// {
	// 	px = line_x(img, px, 40 * c, 50);
	// 	c++;
	// }
	// while (c < 500)
	// {
	// 	int i = 0;
	// 	//my_mlx_pixel_put(&img, 50 + c, 50, 0x00FFFF00);
	// 	while (i < 500)
	// 	{
	// 		my_mlx_pixel_put(&img, 50 + c, 50 + i, 0x00FF00FF);
	// 		i++;
	// 	}
	// 	c++;
	// }
	// c = 0;
	// while (c < 500)
	// {
	// 	my_mlx_pixel_put(&img, 50 + c, 50 + c, 0x00FFFF00);
	// 	c++;
	// }
	// c = 0;
	// while (c < 500)
	// {
	// 	my_mlx_pixel_put(&img, 50 + c, 50 + 500, 0x00FFFF00);
	// 	c++;
	// }
	//img.vars = &vars;
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img.img, 0, 0);
	mlx_hook(fdf.win, 2, 0, event_key, &fdf);
	mlx_hook(fdf.win, 17, 0, ft_close_wrap, &fdf);
	mlx_loop(fdf.mlx);

	(void)argc;
	(void)argv;
	return (0);
}