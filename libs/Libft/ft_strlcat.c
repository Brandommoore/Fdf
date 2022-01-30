/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:31:40 by mcordoba          #+#    #+#             */
/*   Updated: 2021/09/20 19:19:31 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	c;
	size_t	c2;
	size_t	src_s;
	size_t	dst_s;

	c = 0;
	src_s = ft_strlen((char *)src);
	dst_s = ft_strlen(dst);
	if (!dstsize)
		return (src_s);
	else if (dstsize <= dst_s)
		return (src_s + dstsize);
	c2 = dst_s;
	while (src[c] && c2 < (dstsize - 1))
	{
		dst[c2] = src[c];
		c++;
		c2++;
	}
	dst[c2] = '\0';
	return (src_s + dst_s);
}
