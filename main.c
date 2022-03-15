/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 21:54:29 by marvin            #+#    #+#             */
/*   Updated: 2022/03/15 18:28:03 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	print_instructions(void)
{
	ft_putstr("|+-+-+-+-+-       CONTROL MAP INSTRUCTIONS       -+-+-+-+-+|\n");
	ft_putstr("|                                                          |\n");
	ft_putstr("|    SHIFT CONTROLS                            *           |\n");
	ft_putstr("|     |                                       | |          |\n");
	ft_putstr("|     ↳ Map up    --> Arrow up (↑)           |...|         |\n");
	ft_putstr("|     ↳ Map down  --> Arrow down (↓)        |-*-*-|        |\n");
	ft_putstr("|     ↳ Map left  --> Arrow left (➞)       | =   = |       |\n");
	ft_putstr("|     ↳ Map right --> Arrow up (←)         |       |       |\n");
	ft_putstr("|                                          |   F   |       |\n");
	ft_putstr("|    ZOOM CONTROLS                         |   D   |       |\n");
	ft_putstr("|     |                                    |   F   |       |\n");
	ft_putstr("|     ↳ Map zoom up   --> Key Z            |       |       |\n");
	ft_putstr("|     ↳ Map zoom down --> Key X            |   T   |       |\n");
	ft_putstr("|                                          |   O   |       |\n");
	ft_putstr("|    DEPTH CONTROLS                        |       |       |\n");
	ft_putstr("|     |                                    |   S   |       |\n");
	ft_putstr("|     ↳ Map depth up   --> Key S           |   T   |       |\n");
	ft_putstr("|     ↳ Map depth down --> Key D           |   A   |       |\n");
	ft_putstr("|                                         ||   R   ||      |\n");
	ft_putstr("|    COLOR HUE                           |.|   S   |.|     |\n");
	ft_putstr("|     |                                 |..|       |..|    |\n");
	ft_putstr("|     ↳ Map HUE    --> Key C           |..| |.....| |..|   |\n");
	ft_putstr("|                                      $       $       $   |\n");
	ft_putstr("|                                             $$$          |\n");
	ft_putstr("|+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-|\n");
}

static void	init_program(t_data *fdf, int argc, char **argv)
{
	errmanag(argc);
	ft_putstr("\nFdf is opening ");
	ft_putstr(argv[1]);
	ft_putstr(" [.");
	check_map_width(argv[1]);
	open_map(argv[1], fdf);
	map_size(fdf);
	save_map(fdf);
	close_map(fdf);
	ft_putstr("]  Map loaded\n\n\n");
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
	fdf->m_control.zoom = (720 / fdf->map.width) * 1.5;
	fdf->m_control.color_hue = 1.03;
	fdf->m_control.height = 1.2;
	fdf->m_control.rot_fact = 1;
	fdf->m_control.x_shift = (1920 / fdf->map.width) * 3.5;
	fdf->m_control.y_shift = (720 / fdf->map.height);
}

int	main(int argc, char **argv)
{
	t_data	fdf;

	fdf.init = 1;
	init_program(&fdf, argc, argv);
	init_window(&fdf, 1080, 720);
	print_instructions();
	set_params(&fdf);
	print_map(&fdf);
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img.img, 0, 0);
	mlx_hook(fdf.win, 2, 0, event_key, &fdf);
	mlx_hook(fdf.win, 17, 0, ft_close_wrap, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
