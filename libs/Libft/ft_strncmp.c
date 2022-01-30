/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 22:29:59 by mcordoba          #+#    #+#             */
/*   Updated: 2021/09/17 22:46:18 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			c;
	unsigned char	*str1;
	unsigned char	*str2;

	c = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str1[c] && str2[c] && (str1[c] == str2[c]) && (c < n))
		c++;
	if (c == n)
		return (0);
	return (str1[c] - str2[c]);
}
