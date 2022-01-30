/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:27:04 by mcordoba          #+#    #+#             */
/*   Updated: 2021/09/17 17:39:29 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	cnt;

	cnt = 0;
	while (s[cnt] != '\0' && s[cnt] != (unsigned char)c)
		cnt++;
	if (s[cnt] == (unsigned char)c)
		return ((char *)&s[cnt]);
	return (NULL);
}
