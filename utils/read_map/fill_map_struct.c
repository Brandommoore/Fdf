/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:03:06 by mcordoba          #+#    #+#             */
/*   Updated: 2022/02/14 20:22:37 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static int	nb_of_points(char const *s, char c)
{
	int	cnt;
	int	str;

	cnt = 0;
	str = 0;
	if (!s[cnt])
		return (str);
	while (s[++cnt])
	{
		if (s[cnt] == c && s[cnt - 1] != c)
			str++;
	}
	if (!s[cnt] && s[cnt - 1] != c)
		str++;
	return (str);
}

void	fill_map_struct(t_data fdf)
{
	int i;
	int j;
	char *line;
	char **l_split;

	//printf("fd_map --> %d\n", fdf.fd_map);
	line = "0";
	i = 0;
	while (line != NULL)
	{
		j = 0;
		line = get_next_line(fdf.fd_map);
		printf("nb_of_points --> %d/n", nb_of_points(line, ' '));
		l_split = ft_split(line, ' ');
		fdf.points[i] = malloc(nb_of_points(line, ' ') * sizeof(t_point));
		while (l_split[i] != '\0')
		{
			fdf.points[i][j].value = ft_atoi(l_split[i]);
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
