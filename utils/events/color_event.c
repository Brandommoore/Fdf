/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:12:07 by mcordoba          #+#    #+#             */
/*   Updated: 2022/03/14 19:24:20 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	color_event(t_data *fdf)
{
	clear_window(fdf);
	fdf->m_control.color_hue += 0.2;
	printf("color --> %f\n", fdf->m_control.color_hue);
	print_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 0, 0);
}
