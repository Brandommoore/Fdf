/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:44:51 by mcordoba          #+#    #+#             */
/*   Updated: 2022/02/16 17:38:41 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static void	err_message()
{
	printf("Error al abrir el mapa\n");
	exit (0);
}

void	open_map(char *route, t_data *fdf)
{
	int fd_map_w;
	int fd_map_h;
	int fd_map;

	fd_map_w = open(route, O_RDONLY);
	if (fd_map_w == -1)
		err_message();
	fd_map_h = open(route, O_RDONLY);
	if (fd_map_h == -1)
		err_message();
	fd_map = open(route, O_RDONLY);
	if (fd_map == -1)
		err_message();
	fdf->fd_map.fd_map_w = fd_map_w;
	fdf->fd_map.fd_map_h = fd_map_h;
	fdf->fd_map.fd_map = fd_map;
}

void	close_map(t_data *fdf)
{
	close(fdf->fd_map.fd_map_w);
	close(fdf->fd_map.fd_map_h);
	close(fdf->fd_map.fd_map);
}