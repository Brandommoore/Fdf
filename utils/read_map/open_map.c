/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:44:51 by mcordoba          #+#    #+#             */
/*   Updated: 2022/03/01 18:48:00 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static void	err_message()
{
	ft_putstr("Error al abrir el mapa\n");
	exit (0);
}

int	f_extension(char *route, char *ext)
{
	int route_len;
	int ext_len;

	route_len = (int)ft_strlen(route) - 1;
	ext_len = (int)ft_strlen(ext) - 1;
	while (ext_len > 0)
	{
		if (route[route_len - 1] != ext[ext_len - 1])
		{
			ft_putstr("Map error, bust be: .fdf\n");
			return (0);
		}
		ext_len--;
		route_len--;
	}
	return(1);
}

void	open_map(char *route, t_data *fdf)
{
	int	fd_map_w;
	int	fd_map_h;
	int	fd_line_w;
	int	fd_map;
	int	f_ext;

	f_ext = f_extension(route, ".fdf");
	if (f_ext == 0)
		exit(0);
	fd_map_w = open(route, O_RDONLY);
	if (fd_map_w == -1)
		err_message();
	fd_map_h = open(route, O_RDONLY);
	if (fd_map_h == -1)
		err_message();
	fd_line_w = open(route, O_RDONLY);
	if (fd_line_w == -1)
		err_message();
	fd_map = open(route, O_RDONLY);
	if (fd_map == -1)
		err_message();
	printf("fd_map_w --> %d\n", fd_map_w);
	fdf->fd_map.fd_map_w = fd_map_w;
	fdf->fd_map.fd_map_h = fd_map_h;
	fdf->fd_map.fd_line_w = fd_line_w;
	fdf->fd_map.fd_map = fd_map;
}

void	close_map(t_data *fdf)
{
	close(fdf->fd_map.fd_map_w);
	close(fdf->fd_map.fd_map_h);
	close(fdf->fd_map.fd_line_w);
	close(fdf->fd_map.fd_map);
}