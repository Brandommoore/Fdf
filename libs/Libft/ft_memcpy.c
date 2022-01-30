/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:53:33 by mcordoba          #+#    #+#             */
/*   Updated: 2021/09/16 18:54:54 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	cnt;

	cnt = 0;
	if (dst || src)
	{
		while (cnt < n)
		{
			((unsigned char *)dst)[cnt] = ((unsigned char *)src)[cnt];
			cnt++;
		}
	}
	return (dst);
}
