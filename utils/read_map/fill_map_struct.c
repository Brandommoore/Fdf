/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:03:06 by mcordoba          #+#    #+#             */
/*   Updated: 2022/02/11 21:38:43 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	fill_map_struct(t_data fdf)
{
	int i;
	int j;
	char *line;
	char **l_split;

	line = "0";
	i = 0;
	while (line != NULL)
	{
		j = 0;
		line = get_next_line(fdf.fd_map);
		l_split = ft_split(line, ' ');
		while (l_split[i] != '\0')
		{
			//fdf.points[i][j].value = ft_atoi(l_split[i]);
			fdf.points[i][j].pos_x = i;
			fdf.points[i][j].pos_y = j;
			fdf.points[i][j].color = 0x00FF0000;
			j++;
		}
		i++;
	}
	freedom(l_split);
	free(line);
}
