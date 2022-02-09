/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:41:21 by mcordoba          #+#    #+#             */
/*   Updated: 2022/02/09 20:44:39 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	ft_close(t_data *data)
{
	
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx ,data->img.img);
	exit (0);
}

void	clear_window(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->cord.win_w)
	{
		j = 0;
		while (j < data->cord.win_h)
		{
			my_mlx_pixel_put(data, i, j, 0x000000);
			j++;
		}
		i++;
	}
}
