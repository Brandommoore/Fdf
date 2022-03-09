/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:41:28 by mcordoba          #+#    #+#             */
/*   Updated: 2022/03/09 18:58:11 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void shift_map(t_data *fdf)
{
	fdf->bresshem.x += fdf->m_control.x_shift;
	fdf->bresshem.y += fdf->m_control.y_shift;
	fdf->bresshem.y1 += fdf->m_control.x_shift;
	fdf->bresshem.y1 += fdf->m_control.y_shift;
}
