/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 22:50:22 by mcordoba          #+#    #+#             */
/*   Updated: 2021/09/20 18:20:29 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	c1;
	size_t	c2;

	c1 = 0;
	if (!*needle)
		return ((char *)haystack);
	while (c1 < len && haystack[c1] != '\0')
	{
		c2 = 0;
		while ((c1 + c2) < len && haystack[c1 + c2] == needle[c2])
		{
			if (needle[c2 + 1] == '\0')
				return ((char *)&haystack[c1]);
			c2++;
		}
		c1++;
	}
	return (NULL);
}
