/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresen_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:07:46 by mcordoba          #+#    #+#             */
/*   Updated: 2022/03/03 21:39:25 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static float	max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

static float	mod(a)
{
	if (a < 0)
		return (a * -1);
	else
		return (a);
}

void	bresen_alg(float x, float y, float x1, float y1, t_data *fdf)
{
	float	step_x;
	float	step_y;
	int		max;

	//step_x = x1 - x;
	//step_y = y1 - y;

	//step_x /= max;
	//step_x /= max;

	(void)fdf;
}


//Terniary
//MAX1 (a, b) (a > b ? a :b)
// si a > b devuelve a, sino devuelve b

//MOD (a) ((a < 0) ? -a : a)
// si a < 0 devuelve -a (num pos) sino devuelve a (siempre devolver positivo)
