/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:16:07 by mcordoba          #+#    #+#             */
/*   Updated: 2022/02/24 19:27:13 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

<<<<<<< Updated upstream
char	*color_format(char *color)
=======
/*int	str_to_color(char *color)
>>>>>>> Stashed changes
{
	int color_str_len;
	int j;
	int i;
	char *color_hex;

	//i = 2;
	j = 2;
	i = 0;
	color_str_len = ft_strlen(color);
	color_hex = malloc(sizeof (char) * 7);
	while (j < color_str_len)
	{
		//printf("color_strlen --> %d\nj --> %d\n", color_str_len, j);
		color_hex[i] = color[j];
		i++;
		j++;
	}
	color_hex[6] = '\0';
	//printf("Color format is --> %s\n", color_hex);
	return (color_hex);
}

int	str_to_color(char *color)
{
	int color_len;
	int exp;
	int color_val;
	int letter_val;
	int nb_exp;

	color = color_format(color);
	color_val = 0;
	color_len = ft_strlen(color);
	exp = 0;
	//printf("letter -> %c\n", color[color_len - 1]);
	while (color_len > 0)
	{
		letter_val = letter_value(color[color_len]);
		nb_exp = pow(16, exp);
		color_val += (letter_val * nb_exp);
		//printf("color_val --> %d\nletter_val --> %d\nnb_exp --> %d\n", color_val, letter_val, nb_exp);
		exp++;
		color_len--;
	}
	return (color_val);
}

int	letter_value(char letter)
{
	char *base;
	int val;

	val = 0;
	base = "0123456789ABCDEF";
	while (base[val] != '\0')
	{
		if (base[val] == letter)
			return (val);
		val++;
	}
	return (0);
}*/
