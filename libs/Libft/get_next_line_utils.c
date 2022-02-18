/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:58:02 by mcordoba          #+#    #+#             */
/*   Updated: 2022/02/18 19:05:55 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	c1;
	size_t	c2;
	char	*dst;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	dst = malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
		return (NULL);
	c1 = 0;
	while (s1[c1] != '\0')
	{
		dst[c1] = s1[c1];
		c1++;
	}
	c2 = -1;
	while (s2[++c2] != '\0')
		dst[c1 + c2] = s2[c2];
	dst[c1 + c2] = '\0';
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	c;
	char	*dst;

	c = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen((char *)s))
		return (ft_strdup(""));
	if (len > ft_strlen((char *)&s[start]))
		len = ft_strlen((char *)&s[start]);
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	while (c < len && s[start])
	{
		dst[c] = s[start + c];
		c++;
	}
	dst[c] = '\0';
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	size_t	s1_s;
	size_t	c;
	char	*str;

	c = 0;
	s1_s = ft_strlen((char *)s1);
	str = malloc(s1_s + 1);
	if (!str)
		return (NULL);
	while (c < s1_s)
	{
		str[c] = s1[c];
		c++;
	}
	str[c] = '\0';
	return (str);
}

int	size_ln(const char *str)
{
	int	c;

	c = 0;
	while (str && (str[c] != '\n' && str[c] != '\0'))
	{
		c++;
	}
	return (c);
}
