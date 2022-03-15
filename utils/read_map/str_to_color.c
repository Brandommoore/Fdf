/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:16:07 by mcordoba          #+#    #+#             */
/*   Updated: 2022/03/15 15:23:59 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

char	*color_format(char *color)
{
	int		color_str_len;
	int		j;
	int		i;
	char	*color_hex;

	j = 2;
	i = 0;
	color_str_len = ft_strlen(color);
	color_hex = malloc(sizeof (char) * 7);
	while (j < color_str_len)
	{
		color_hex[i] = color[j];
		i++;
		j++;
	}
	color_hex[6] = '\0';
	return (color_hex);
}

int	str_to_color(char *color)
{
	int		color_len;
	int		exp;
	int		color_val;
	int		letter_val;
	int		nb_exp;

	color = color_format(color);
	color_val = 0;
	color_len = ft_strlen(color);
	exp = 0;
	while (color_len > 0)
	{
		color_len--;
		letter_val = letter_value(color[color_len]);
		nb_exp = pow(16, exp);
		color_val += (letter_val * nb_exp);
		exp++;
	}
	return (color_val);
}

int	letter_value(char letter)
{
	char	*base;
	int		val;

	val = 0;
	base = "0123456789ABCDEF";
	while (base[val] != '\0')
	{
		if (base[val] == letter)
			return (val);
		val++;
	}
	free(base);
	return (0);
}
