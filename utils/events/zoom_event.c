/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:54:38 by mcordoba          #+#    #+#             */
/*   Updated: 2022/03/14 17:58:54 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	zoom_up(t_data *fdf)
{
	clear_window(fdf);
	fdf->m_control.zoom += 3.2;
	print_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 0, 0);
}

void	zoom_down(t_data *fdf)
{
	clear_window(fdf);
	fdf->m_control.zoom -= 3.2;
	print_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 0, 0);
}
