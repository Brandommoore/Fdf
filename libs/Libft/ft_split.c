/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:07:16 by mcordoba          #+#    #+#             */
/*   Updated: 2021/09/29 13:27:56 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	nb_of_strs(char const *s, char c)
{
	int	cnt;
	int	str;

	cnt = 0;
	str = 0;
	if (!s[cnt])
		return (str);
	while (s[++cnt])
	{
		if (s[cnt] == c && s[cnt - 1] != c)
			str++;
	}
	if (!s[cnt] && s[cnt - 1] != c)
		str++;
	return (str);
}

static char	*fill_str(char const *s, char c, size_t *x)
{
	size_t	c1;
	size_t	c2;
	char	*str;

	c1 = 0;
	while (s[(*x) + c1] && s[(*x) + c1] != c)
		c1++;
	str = malloc((c1 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	c2 = 0;
	while (c2 < c1)
	{
		str[c2++] = s[(*x)++];
	}
	str[c2] = '\0';
	return (str);
}

static char	**mtx_free(char **matrix, size_t sub_m)
{
	size_t	cnt;

	cnt = 0;
	while (cnt < sub_m)
	{
		free(matrix[cnt]);
		cnt++;
	}
	free(matrix);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	size_t	nb_str;
	size_t	c1;
	size_t	c2;

	if (!s)
		return (NULL);
	nb_str = nb_of_strs(s, c);
	matrix = malloc((nb_str + 1) * sizeof(char *));
	if (!matrix)
		return (NULL);
	c1 = -1;
	c2 = 0;
	while (c2 < nb_str && s[++c1])
	{
		if (s[c1] != c)
		{
			matrix[c2++] = fill_str(s, c, &c1);
			if (!matrix[c2 - 1])
				return (mtx_free(matrix, c2 - 1));
		}
	}
	matrix[nb_str] = NULL;
	return (matrix);
}
