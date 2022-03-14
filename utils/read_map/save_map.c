/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:10:59 by mcordoba          #+#    #+#             */
/*   Updated: 2022/03/14 17:39:00 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static void	fill_point(t_data *fdf, char **l_split, int i, int j)
{
	char	**p_split;

	p_split = ft_split(l_split[j], ',');
	fdf->poin[i][j] = ft_atoi(p_split[0]);
	freedom(p_split);
}

void	save_map(t_data *fdf)
{
	int		i;
	int		j;
	int		lw;
	char	*line;
	char	**l_split;

	line = "0";
	lw = line_width(fdf);
	fdf->poin = malloc(fdf->map.height * sizeof(int *));
	if (!fdf->poin)
		return ;
	i = 0;
	while (line != NULL && i < fdf->map.height)
	{
		j = 0;
		line = get_next_line(fdf->fd_map.fd_map);
		l_split = ft_split(line, ' ');
		fdf->poin[i] = malloc(lw * sizeof(int));
		if (!fdf->poin[i])
			return ;
		while (l_split != NULL && l_split[j] != '\0')
			fill_point(fdf, l_split, i, j++);
		i++;
	}
	double_freedom(l_split, line);
}
