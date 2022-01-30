/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:36:54 by mcordoba          #+#    #+#             */
/*   Updated: 2021/09/22 17:33:02 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	f_sign(long long int n)
{
	if (n >= 0)
		return (0);
	else
		return (1);
}

static size_t	number_len(long long int n)
{
	size_t	len;

	len = 1;
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long long int	l_num;
	size_t			n_len;
	char			*str_num;
	size_t			sign;

	l_num = n;
	sign = (size_t)f_sign(l_num);
	if (l_num < 0)
		l_num = l_num * -1;
	n_len = number_len(l_num);
	str_num = malloc(sizeof (char) * ((n_len + 1) + sign));
	if (!str_num)
		return (NULL);
	if (sign == 1)
		n_len = n_len + 1;
	str_num[n_len--] = '\0';
	while (l_num >= 10)
	{
		str_num[n_len--] = l_num % 10 + '0';
		l_num /= 10;
	}
	str_num[n_len] = l_num + '0';
	if (sign == 1)
		str_num[0] = '-';
	return (str_num);
}
