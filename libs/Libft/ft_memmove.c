/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 20:00:56 by mcordoba          #+#    #+#             */
/*   Updated: 2021/09/16 16:05:49 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				c;
	const unsigned char	*init;
	unsigned char		*end;

	init = src;
	end = dst;
	c = 0;
	if (src == dst)
		return (dst);
	else if (src > dst)
	{
		while (c < len)
		{
			end[c] = init[c];
			c++;
		}
		return (end);
	}
	else
		while (len--)
			end[len] = init[len];
	return (end);
}
