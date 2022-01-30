/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:05:12 by mcordoba          #+#    #+#             */
/*   Updated: 2021/09/20 15:59:10 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	s1_s;
	size_t	c;
	char	*str;

	c = 0;
	s1_s = ft_strlen((char *)s1);
	str = malloc(s1_s + 1);
	if (!str)
		return (NULL);
	while (c < s1_s)
	{
		str[c] = s1[c];
		c++;
	}
	str[c] = '\0';
	return (str);
}
