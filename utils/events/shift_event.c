/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:45:07 by mcordoba          #+#    #+#             */
/*   Updated: 2022/03/14 19:27:29 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	shift_up(t_data *fdf)
{
	clear_window(fdf);
	fdf->m_control.y_shift -= 10;
	print_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 0, 0);
}

void	shift_down(t_data *fdf)
{
	clear_window(fdf);
	fdf->m_control.y_shift += 10;
	print_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 0, 0);
}

void	shift_left(t_data *fdf)
{
	clear_window(fdf);
	fdf->m_control.x_shift -= 10;
	print_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 0, 0);
}

void	shift_right(t_data *fdf)
{
	clear_window(fdf);
	fdf->m_control.x_shift += 10;
	print_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 0, 0);
}
