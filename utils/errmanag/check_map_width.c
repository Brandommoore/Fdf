/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:29:43 by mcordoba          #+#    #+#             */
/*   Updated: 2022/03/15 14:54:01 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static int	line_map_width(int fd)
{
	char	**points;
	char	*line;
	int		lw;
	int		line_width;

	line = "0";
	line = get_next_line_w_map(fd);
	if (line == NULL)
		return (0);
	line_width = (int)ft_strlen(line);
	points = ft_split(line, ' ');
	lw = 0;
	while (points && points[lw] != '\0')
		lw++;
	freedom(points);
	free(line);
	return (lw);
}

void	check_map_width(char *route)
{
	int	fd;
	int	current_lw;
	int	lw;

	fd = open(route, O_RDONLY);
	lw = line_map_width(fd);
	current_lw = line_map_width(fd);
	while (current_lw != 0)
	{
		if (lw != current_lw)
		{
			ft_putstr("Map error\n");
			exit (0);
		}
		current_lw = line_map_width(fd);
	}
}
