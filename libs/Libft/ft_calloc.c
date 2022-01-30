/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:07:56 by mcordoba          #+#    #+#             */
/*   Updated: 2021/09/20 16:10:57 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	c;
	char	*str;

	c = 0;
	str = malloc(count * size);
	if (!str)
		return (NULL);
	while (c < (size * count))
	{
		str[c] = '\0';
		c++;
	}
	return (str);
}
