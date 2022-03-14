/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 21:54:29 by marvin            #+#    #+#             */
/*   Updated: 2022/03/14 19:47:11 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_program(t_data *fdf, int argc, char **argv)
{
	errmanag(argc);
	open_map(argv[1], fdf);
	map_size(fdf);
	save_map(fdf);
	close_map(fdf);
}

static void	init_window(t_data *fdf, int width, int height)
{
	fdf->cord.win_w = width;
	fdf->cord.win_h = height;
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, fdf->cord.win_w,
			fdf->cord.win_h, "Fdf");
	fdf->img.img = mlx_new_image(fdf->mlx, fdf->cord.win_w,
			fdf->cord.win_h);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel,
			&fdf->img.line_length, &fdf->img.endian);
}

static void	set_params(t_data *fdf)
{
	fdf->m_control.zoom = 40;
	fdf->m_control.color_hue = 1.03;
	fdf->m_control.height = 1.2;
}

int	main(int argc, char **argv)
{
	t_data	fdf;

	fdf.init = 1;
	init_program(&fdf, argc, argv);
	init_window(&fdf, 1080, 720);
	set_params(&fdf);
	print_map(&fdf);
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img.img, 0, 0);
	mlx_hook(fdf.win, 2, 0, event_key, &fdf);
	mlx_hook(fdf.win, 17, 0, ft_close_wrap, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
