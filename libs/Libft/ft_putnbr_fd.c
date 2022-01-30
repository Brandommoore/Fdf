/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:25:17 by mcordoba          #+#    #+#             */
/*   Updated: 2021/09/21 18:32:32 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 0 && n < 10)
	{
		ft_putchar(n + '0', fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar(n % 10 + '0', fd);
	}
	else
	{
		ft_putchar('-', fd);
		if (n == -2147483648)
		{
			ft_putchar('2', fd);
			ft_putnbr_fd(147483648, fd);
			return ;
		}
		ft_putnbr_fd(n * -1, fd);
	}
}
