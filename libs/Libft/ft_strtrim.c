/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 11:52:07 by mcordoba          #+#    #+#             */
/*   Updated: 2021/09/21 17:42:12 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ischarin(const char *set, char letter)
{
	size_t	c;

	c = 0;
	while (set[c] != '\0')
	{
		if (set[c] == letter)
			return (1);
		c++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	c1;
	size_t	c2;
	size_t	c_dst;
	char	*dst;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	c1 = 0;
	while (s1[c1] && ft_ischarin((char *)set, s1[c1]))
		c1++;
	c2 = ft_strlen(s1);
	while ((c2 - 1) > 0 && ft_ischarin((char *)set, s1[c2 - 1]))
		c2--;
	if (c1 > c2)
		c2 = c1;
	dst = malloc(sizeof (char) * ((c2 - c1) + 1));
	if (!dst)
		return (NULL);
	c_dst = 0;
	while (c1 < c2)
		dst[c_dst++] = s1[c1++];
	dst[c_dst] = '\0';
	return (dst);
}
