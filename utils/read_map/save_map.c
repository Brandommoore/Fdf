/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:10:59 by mcordoba          #+#    #+#             */
/*   Updated: 2022/03/10 21:42:24 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	save_map(t_data *fdf)
{
	int		i;
	int		j;
	int		lw;
	char	*line;
	char	**l_split;
	char	**p_split;

	line = "0";
	lw = line_width(fdf);
	fdf->poin = malloc(fdf->map.height * sizeof(int *) + 1);
	if (!fdf->poin)
		return ;
	i = 0;
	while (line != NULL)
	{
		j = 0;
		line = get_next_line(fdf->fd_map.fd_map);
		if (line[0] == '\n')
			return ;
		l_split = ft_split(line, ' ');
		fdf->poin[i] = malloc(fdf->map.width * sizeof(int) + 1);
		if (!fdf->poin[i])
			return ;
		while (l_split != NULL && l_split[j] != '\0')
		{
			p_split = ft_split(l_split[j], ',');
			fdf->poin[i][j] = ft_atoi(p_split[0]);
			j++;
		}
		i++;
	}
	double_freedom(l_split, line);
	freedom(p_split);
}
