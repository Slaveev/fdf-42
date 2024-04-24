/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslaveev <dslaveev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:40:54 by dslaveev          #+#    #+#             */
/*   Updated: 2024/04/22 11:36:55 by dslaveev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1400
# define HEIGHT 1000

// # define GL_SILENCE_DEPRECATION

// # include <OpenGL/gl3.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "libft/libft.h"
// # include "minilibx_macos/mlx.h"

typedef struct s_map
{
	int		width;
	int		height;
	int		**z_matrix;
}	t_map;

typedef struct s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;

	int			min_x;
	int			min_y;
	int			shift_x;
	int			shift_y;

	int			color;
	int			zoom;
	int			angle;
	int			projection;

	float		scale;

	int			max_delta;
	float		x_step;
	float		y_step;
	int			bits_per_pixel;
	int			size_line;
	int			endian;

	t_map		map;
}	t_fdf;

typedef struct s_coords
{
	float	x;
	float	y;
	float	x1;
	float	y1;
	float	z;
	float	z1;
}	t_coords;

// essentials for reading the file
int		get_height(char *file);
int		get_width(char *file);
int		ft_word_counter(char *str, char c);
void	read_file(char *file, t_map *data);
void	fill_matrix(t_map *data, char *line, int i);
int		**create_vector(int width, int height);

// drawing esseantials
void	line_draw(t_coords *coords, t_fdf *env);
void	draw(t_fdf *env);
int		color(int z, int z1);
void	draw_horizontal(t_coords *coords, t_fdf *env);
void	draw_vertical(t_coords *coords, t_fdf *env);

// operations with the map
void	adjust_coords(t_coords *coords, t_fdf *env);
void	adjust_z_coords(t_coords *coords, t_fdf *env);
void	apply_zoom(t_coords *coords, int zoom);
void	apply_isometric(t_coords *coords, int z, int z1);
void	zoom_in(t_fdf *env);
void	zoom_out(t_fdf *env);
void	rotate_left(t_fdf *env);
void	rotate_right(t_fdf *env);
void	apply_rotation(t_coords *coords, t_fdf *env);

// utils
void	free_array(int **array, int height);
int		max(int a, int b);
int		ft_abs(int a);
void	free_data(t_map *data);

// deal with the keys
int		deal_key(int key, t_fdf *env);

// start of map
t_fdf	*init_env(void);
// void	switch_projection(t_fdf *env);
// void	apply_paralel(t_coords *coords);
// void	minimalize_values(t_fdf *env);
// void	get_map_size(t_fdf *env);

#endif
