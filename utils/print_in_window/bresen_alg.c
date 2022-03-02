/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresen_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:07:46 by mcordoba          #+#    #+#             */
/*   Updated: 2022/03/02 21:28:49 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void bresen_alg(float x, float y, float x1, float y1, t_data *fdf)
{
	float step_x;
	float step_y;

	step_x = x1 - x;
	step_y = y1 - y;

	step_x =/ MAX(step_x, step_y);
	step_y =/ MAX(step_x, step_y);

	(void)fdf;
}
