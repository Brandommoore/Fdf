/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:14:35 by mcordoba          #+#    #+#             */
/*   Updated: 2021/09/22 12:32:38 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	c;
	size_t	s_len;
	char	*dst;

	if (!s)
		return (NULL);
	c = 0;
	s_len = ft_strlen((char *)s);
	dst = malloc(sizeof (char) * (s_len + 1));
	if (!dst)
		return (NULL);
	while (s[c])
	{
		dst[c] = f(c, s[c]);
		c++;
	}
	dst[c] = '\0';
	return (dst);
}
