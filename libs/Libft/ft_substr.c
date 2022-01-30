/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:18:06 by mcordoba          #+#    #+#             */
/*   Updated: 2021/09/20 19:36:21 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	c;
	char	*dst;

	c = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen((char *)s))
		return (ft_strdup(""));
	if (len > ft_strlen((char *)&s[start]))
		len = ft_strlen((char *)&s[start]);
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	while (c < len && s[start])
	{
		dst[c] = s[start + c];
		c++;
	}
	dst[c] = '\0';
	return (dst);
}
