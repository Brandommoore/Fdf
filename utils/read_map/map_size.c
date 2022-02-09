/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:02:47 by mcordoba          #+#    #+#             */
/*   Updated: 2022/02/09 21:44:34 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	map_width(int fd_map)
{
	char	**points;
	char	*line;
	int		w;

	line = get_next_line(fd_map);
	points = ft_split(line, ' ');
	w = 0;
	while (points && points[w] != '\0')
		w++;
	freedom(points);
	free(line);
	return (w);
}

// int	map_height(int fd_map)
// {
// 	int h;

// 	h = 0;
// 	while (get_next_line(fd_map) != 0)
// 	{

// 	}
// 		h++;
// 	printf("height_map --> %d/n", h);
// 	return (h);
// }
