/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 21:54:34 by marvin            #+#    #+#             */
/*   Updated: 2022/03/14 17:20:19 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include "libs/Libft/libft.h"
# include "libs/minilibx_macos/mlx.h"
# include "libs/key_macos.h"

typedef struct s_fdmap{
	int				fd_map_size;
	int				fd_line_w;
	int				fd_map;
}				t_fdmap;

typedef struct s_point {
	int				value;
	int				pos_x;
	int				pos_y;
	int				color;
}				t_point;

typedef struct s_map {
	int				width;
	int				height;
	int				raw_len_w;
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

typedef struct s_bresshem
{
	float			x;
	float			y;
	float			x1;
	float			y1;
	int				color;
}				t_bresshem;

typedef	struct s_mapcontrol
{
	float			zoom;
	int				x_shift;
	int				y_shift;
	float				height;
	float			color_hue;
}				t_mapcontrol;

typedef struct s_data {
	void			*mlx;
	void			*win;
	t_fdmap			fd_map;
	t_img			img;
	t_cord			cord;
	t_map			map;
	t_bresshem		bresshem;
	t_mapcontrol	m_control;
	t_point			**points;
	int				**poin;
	int				init;
}				t_data;

/*MAIN*/
int		event_key(int keycode, t_data *data);

/*UTILS*/
void	freedom(char **matrix);
void	double_freedom(char **matrix, char *line);
void	ft_putstr(const char *str);

/*ERRMANAG*/
void	errmanag(int argc);

/*--Print_in_window*/
void	bresen_alg(t_data *fdf);
int		z_value(t_data *fdf);
int		z1_value(t_data *fdf);
void	isometric(float *x, float *y, int z);
void	shift_map(t_data *fdf);
void	bress_pixel_print(t_data *fdf, float step_x, float step_y);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		line_y(t_data fdf, int width, int color);
int		line_x(t_data fdf, int width, int color);
void	print_map(t_data *fdf);
void	print_values_console(t_data *fdf);

/*Events*/
void	ft_close(t_data *data);
int		ft_close_wrap(void *data);
void	clear_window(t_data *data);

/*Read_map*/
void	map_size(t_data *fdf);
int		map_width(t_data *fdf);
int		map_height(t_data *fdf);
int		line_width(t_data *fdf);
void	fill_map_struct(t_data *fdf);
void	save_map(t_data *fdf);
void	open_map(char *route, t_data *fdf);
int		f_extension(char *route, char *ext);
void	close_map(t_data *fdf);
void	insert_data(t_data fdf, char **l_split, int i, int j);
int		str_to_color(char *color);
char	*color_format(char *color);
int		letter_value(char letter);

#endif