/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:42:44 by mcordoba          #+#    #+#             */
/*   Updated: 2022/03/14 19:30:41 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	event_key(int keycode, t_data *fdf)
{
	if (keycode == 53)
		ft_close(fdf);
	else if (keycode == K_AR_U)
		shift_up(fdf);
	else if (keycode == K_AR_D)
		shift_down(fdf);
	else if (keycode == K_AR_L)
		shift_left(fdf);
	else if (keycode == K_AR_R)
		shift_right(fdf);
	else if (keycode == K_Z)
		zoom_up(fdf);
	else if (keycode == K_X)
		zoom_down(fdf);
	else if (keycode == K_S)
		height_up(fdf);
	else if (keycode == K_D)
		height_down(fdf);
	else if (keycode == K_C)
		color_event(fdf);
	return (0);
}
