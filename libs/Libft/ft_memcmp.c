/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 19:26:24 by mcordoba          #+#    #+#             */
/*   Updated: 2021/09/17 22:21:30 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				c;
	unsigned const char	*str1;
	unsigned const char	*str2;

	c = 0;
	str1 = s1;
	str2 = s2;
	while (c < n && str1[c] == str2[c])
		c++;
	if (c == n)
		return (0);
	return (str1[c] - str2[c]);
}
