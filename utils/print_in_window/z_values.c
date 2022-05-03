/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_values.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:10:54 by mcordoba          #+#    #+#             */
/*   Updated: 2022/03/14 11:27:26 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	z_value(t_data *fdf)
{
	int	z;

	z = fdf->poin[(int)fdf->bresshem.y][(int)fdf->bresshem.x]
		* fdf->m_control.height;
	return (z);
}

int	z1_value(t_data *fdf)
{
	int	z1;

	z1 = fdf->poin[(int)fdf->bresshem.y1][(int)fdf->bresshem.x1]
		* fdf->m_control.height;
	return (z1);
}
