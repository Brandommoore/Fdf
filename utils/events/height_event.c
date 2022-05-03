/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:08:14 by mcordoba          #+#    #+#             */
/*   Updated: 2022/03/14 19:11:25 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	height_up(t_data *fdf)
{
	clear_window(fdf);
	fdf->m_control.height += 1.5;
	print_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 0, 0);
}

void	height_down(t_data *fdf)
{
	clear_window(fdf);
	fdf->m_control.height -= 1.5;
	print_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 0, 0);
}
