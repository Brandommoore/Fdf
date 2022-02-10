/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:02:47 by mcordoba          #+#    #+#             */
/*   Updated: 2022/02/10 17:47:31 by mcordoba         ###   ########.fr       */
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

int	map_height(int fd_map)
{
	int h;
	char *line;

	h = 0;
	//line = get_next_line(fd_map);
	line = "0";
	while (line != NULL)
	{
		h++;
		line = get_next_line(fd_map);
		printf("%s\n", line);
	}
	printf("height_map --> %d/n", h);
	return (h);
}
