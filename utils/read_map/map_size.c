/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:02:47 by mcordoba          #+#    #+#             */
/*   Updated: 2022/02/24 20:51:30 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

// int	map_width(t_data fdf)
// {
// 	char	**points;
// 	char	*line;
// 	int		w;

// 	line = get_next_line(fd_map);
// 	points = ft_split(line, ' ');
// 	w = 0;
// 	while (points && points[w] != '\0')
// 		w++;
// 	freedom(points);
// 	free(line);
// 	return (w);
// }

int	line_width(t_data *fdf)
{
	char	**points;
	char	*line;
	int		lw;

	line = "0";
	line = get_next_line_wl(fdf->fd_map.fd_line_w);
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
	line = get_next_line_w(fdf->fd_map.fd_map_w);
	points = ft_split(line, ' ');
	w = 0;
	while (points && points[w] != '\0')
		w++;
	freedom(points);
	free(line);
	//printf("width_map --> %d\n", w);
	return (w);
}

int	map_height(t_data *fdf)
{
	int h;
	char *line;
	
	//line = get_next_line(fd_map);
	h = 0;
	line = "0";
	while (line != NULL)
	{
		h++;
		line = get_next_line_h(fdf->fd_map.fd_map_h);
		//printf("%s\n", line);
	}
	free(line);
	fdf->map.height = h;
	//printf("height_map --> %d\n", h);
	return (h);
}


// int	map_height(t_data fdf)
// {
// 	int h;
// 	int c;

// 	h = 0;
// 	c = 0;
// 	printf("%s/n", map);
// 	while (map[h] != '\0')
// 	{
// 		if (map[h] == '\n')
// 			c++;
// 		h++;
// 	}
// 	// while (line != NULL)
// 	// {
// 	// 	h++;
// 	// 	line = get_next_line(fd_map);
// 	// 	printf("%s\n", line);
// 	// }
// 	printf("height_map --> %d/n", c);
// 	return (c);
// }
