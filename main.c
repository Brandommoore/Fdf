/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 21:54:29 by marvin            #+#    #+#             */
/*   Updated: 2022/02/09 21:40:08 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	event_key(int keycode, t_data *data)
{
	//printf("keycode is --> %d\n", keycode);
	if (keycode == 53)
		ft_close(data);
	else if (keycode == K_AR_U)
	{
		printf("↑\n");
		data->cord.py -= 5;
		clear_window(data);
		line_x(*data, 50, 0x00FF0FF0);
		line_y(*data, 50, 0x00FF0FF0);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
	else if (keycode == K_AR_D)
	{
		printf("↓\n");
		data->cord.py += 5;
		clear_window(data);
		line_x(*data, 50, 0x00FF0FF0);
		line_y(*data, 50, 0x00FF0FF0);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
	else if (keycode == K_AR_L)
	{
		printf("←\n");
		data->cord.px -= 5;
		clear_window(data);
		line_x(*data, 50, 0x00FF0FF0);
		line_y(*data, 50, 0x00FF0FF0);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
	else if (keycode == K_AR_R)
	{
		printf("➞\n");
		data->cord.px += 5;
		clear_window(data);
		line_x(*data, 50, 0x00FF0FF0);
		line_y(*data, 50, 0x00FF0FF0);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	fdf;
	int		fd_map;
	char	*line;

	fd_map = open("test_maps/elem2.fdf", O_RDONLY);
	if (fd_map == -1)
	{
		printf("Error al abrir el mapa");
		return (0);
	}
	
	line = get_next_line(fd_map);
	printf("first line map --> \n%s\n", line);

	map_width(fd_map);







	fdf.cord.win_h = 720;
	fdf.cord.win_w = 1080;
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, fdf.cord.win_w, fdf.cord.win_h, "Fdf");
	fdf.img.img = mlx_new_image(fdf.mlx, fdf.cord.win_w, fdf.cord.win_h);
	fdf.img.addr = mlx_get_data_addr(fdf.img.img, &fdf.img.bits_per_pixel, &fdf.img.line_length,
								&fdf.img.endian);
	///offset = (fdf.cord.win_h * fdf.img.line_length + fdf.cord.win_w * (fdf.img.bits_per_pixel / 8));

	fdf.cord.px = 50;
	fdf.cord.py = 50;
	line_x(fdf, 50, 0x00FF0FF0);
	line_y(fdf, 50, 0x00FF0FF0);
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
	mlx_loop(fdf.mlx);

	(void)argc;
	(void)argv;
	return (0);
}