/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 18:15:28 by mcordoba          #+#    #+#             */
/*   Updated: 2021/09/17 18:45:33 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	cnt;

	cnt = ft_strlen((char *)s);
	while (cnt > 0 && s[cnt] != (unsigned char)c)
		cnt--;
	if (s[cnt] == (unsigned char)c)
		return ((char *)&s[cnt]);
	return (NULL);
}
