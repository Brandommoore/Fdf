/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:02:47 by mcordoba          #+#    #+#             */
/*   Updated: 2022/02/14 20:57:24 by mcordoba         ###   ########.fr       */
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

int	map_height(t_data fdf)
{
	int h;
	int c;
	char map[1000];

	h = 0;
	c = 0;
	read(fdf.fd_map, map, 1000);
	printf("%s/n", map);
	while (map[h] != '\0')
	{
		if (map[h] == '\n')
			c++;
		h++;
	}
	// while (line != NULL)
	// {
	// 	h++;
	// 	line = get_next_line(fd_map);
	// 	printf("%s\n", line);
	// }
	printf("height_map --> %d/n", c);
	return (c);
}
