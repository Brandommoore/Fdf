/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 21:54:34 by marvin            #+#    #+#             */
/*   Updated: 2022/02/14 20:34:14 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libs/Libft/libft.h"
# include "libs/minilibx_macos/mlx.h"
# include "libs/key_macos.h"

typedef struct s_point {
	int				value;
	int				pos_x;
	int				pos_y;
	int				color;
}				t_point;

typedef struct s_map {
	int				width;
	int				height;
}				t_map;

typedef struct s_cord {
	int				win_w;
	int				win_h;
	int				px;
	int				py;
}				t_cord;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}				t_img;

typedef struct s_data {
	void			*mlx;
	void			*win;
	int				fd_map;
	t_img			img;
	t_cord			cord;
	t_map			map;
	t_point			**points;
}				t_data;

/*MAIN*/
int		event_key(int keycode, t_data *data);

/*UTILS*/
void	freedom(char **matrix);

/*--Print_in_window*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		line_y(t_data fdf, int width, int color);
int		line_x(t_data fdf, int width, int color);

/*Events*/
void	ft_close(t_data *data);
void	clear_window(t_data *data);

/*Read_map*/
int		map_width(t_data fdf);
int		map_height(t_data fdf);
void	fill_map_struct(t_data fdf);

#endif