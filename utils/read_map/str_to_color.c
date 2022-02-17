/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:16:07 by mcordoba          #+#    #+#             */
/*   Updated: 2022/02/17 20:01:03 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	str_to_color(char *color)
{
	//int i;
	int j;
	char *color_hex;

	//i = 2;
	j = 0;
	color_hex = "0";
	while (color[j] != '\0')
	{
		//printf("i --> %d\nj --> %d\n", i, j);
		if (j < 2)
			color[j] = '\0';
		//color_hex[j] = color[j];
		//i++;
		j++;
	}
	printf("Color format is --> %s\n", color_hex);
	return (0);
}
