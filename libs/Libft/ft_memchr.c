/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 18:52:35 by mcordoba          #+#    #+#             */
/*   Updated: 2021/09/17 22:21:00 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				cnt;
	const unsigned char	*str;

	cnt = 0;
	str = s;
	while ((cnt < n) && (str[cnt] != (unsigned char)c))
		cnt++;
	if (cnt == n)
		return (NULL);
	return ((void *)&str[cnt]);
}
