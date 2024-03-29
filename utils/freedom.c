/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:26:13 by mcordoba          #+#    #+#             */
/*   Updated: 2022/02/25 18:09:12 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	freedom(char **matrix)
{
	int	c;

	c = 0;
	while (matrix && matrix[c] != '\0')
	{
		free(matrix[c]);
		c++;
	}
	free(matrix);
}

void	double_freedom(char **matrix, char *line)
{
	freedom(matrix);
	free(line);
}
