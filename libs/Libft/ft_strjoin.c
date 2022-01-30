/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 19:41:05 by mcordoba          #+#    #+#             */
/*   Updated: 2021/09/22 16:22:40 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	c1;
	size_t	c2;
	char	*dst;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	dst = malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
		return (NULL);
	c1 = 0;
	while (s1[c1] != '\0')
	{
		dst[c1] = s1[c1];
		c1++;
	}
	c2 = -1;
	while (s2[++c2] != '\0')
		dst[c1 + c2] = s2[c2];
	dst[c1 + c2] = '\0';
	return (dst);
}
