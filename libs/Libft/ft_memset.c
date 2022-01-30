/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:00:25 by mcordoba          #+#    #+#             */
/*   Updated: 2021/09/14 12:16:02 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			cnt;
	unsigned char	*str;

	str = b;
	cnt = 0;
	while (cnt < len)
	{
		str[cnt] = c;
		cnt++;
	}
	return (b);
}
