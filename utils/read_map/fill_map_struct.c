/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:03:06 by mcordoba          #+#    #+#             */
/*   Updated: 2022/03/07 17:35:07 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	fill_map_struct(t_data *fdf)
{
	int		i;
	int		j;
	int		lw;
	char	*line;
	char	**l_split;

	line = "0";
	lw = line_width(fdf);
	fdf->points = malloc((map_height(fdf)) * sizeof(t_point *) + 1);
	if (!fdf->points)
		return ;
	i = 0;
	while (line != NULL)
	{
		j = 0;
		line = get_next_line(fdf->fd_map.fd_map);
		l_split = ft_split(line, ' ');
		fdf->points[i] = malloc((lw) * sizeof(t_point) + 1);
		if (!fdf->points[i])
			return ;
		while (l_split != NULL && l_split[j] != '\0')
			insert_data(*fdf, l_split, i, j++);
		i++;
	}
	double_freedom(l_split, line);
}

void	insert_data(t_data fdf, char **l_split, int i, int j)
{
	char	**p_split;

	p_split = ft_split(l_split[j], ',');
	fdf.points[i][j].value = ft_atoi(p_split[0]);
	fdf.points[i][j].pos_x = i;
	fdf.points[i][j].pos_y = j;
	if (p_split[1] == NULL)
		fdf.points[i][j].color = 0xFFFFFF;
	else
	{
		fdf.points[i][j].color = str_to_color(p_split[1]);
	}
}
