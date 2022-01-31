/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 21:54:29 by marvin            #+#    #+#             */
/*   Updated: 2022/01/31 20:04:20 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	fd = open("test_maps/elem2.fdf", O_RDONLY);
	if (fd == -1)
	{
		printf("Error al abrir el mapa");
		return (0);
	}
	
	line = get_next_line(fd);
	printf("first line map --> \n%s\n", line);

	(void)argc;
	(void)argv;
	return (0);
}