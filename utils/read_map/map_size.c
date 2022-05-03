/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:02:47 by mcordoba          #+#    #+#             */
/*   Updated: 2022/03/15 15:30:34 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	line_width(t_data *fdf)
{
	char	**points;
	char	*line;
	int		lw;

	line = "0";
	line = get_next_line_w(fdf->fd_map.fd_line_w);
	fdf->map.raw_len_w = (int)ft_strlen(line);
	points = ft_split(line, ' ');
	lw = 0;
	while (points && points[lw] != '\0')
		lw++;
	freedom(points);
	free(line);
	fdf->map.width = lw;
	return (lw);
}

int	map_width(t_data *fdf)
{
	char	**points;
	char	*line;
	int		w;

	line = "0";
	line = get_next_line_w(fdf->fd_map.fd_map_size);
	points = ft_split(line, ' ');
	w = 0;
	while (points && points[w] != '\0')
		w++;
	freedom(points);
	free(line);
	fdf->map.width = w;
	return (w);
}

int	map_height(t_data *fdf)
{
	int		h;
	char	*line;

	h = 0;
	line = "0";
	while (line != NULL)
	{
		h++;
		line = get_next_line_h(fdf->fd_map.fd_map_size);
		free(line);
	}
	fdf->map.height = h;
	return (h);
}

void	map_size(t_data *fdf)
{
	map_width(fdf);
	map_height(fdf);
	close(fdf->fd_map.fd_map_size);
}
