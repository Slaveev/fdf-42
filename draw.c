/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslaveev <dslaveev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 10:45:17 by dslaveev          #+#    #+#             */
/*   Updated: 2024/04/22 11:36:40 by dslaveev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line_draw(t_coords *coords, t_fdf *env)
{
	adjust_z_coords(coords, env);
	apply_zoom(coords, env->zoom);
	env->color = color(coords->z, coords->z1);
	apply_isometric(coords, coords->z, coords->z1);
	apply_rotation(coords, env);
	adjust_coords(coords, env);
	env->x_step = coords->x1 - coords->x;
	env->y_step = coords->y1 - coords->y;
	env->max_delta = max(ft_abs(env->x_step), ft_abs(env->y_step));
	env->x_step /= env->max_delta;
	env->y_step /= env->max_delta;
	env->img_ptr = mlx_new_image(env->mlx_ptr, WIDTH, HEIGHT);
	while ((int)(coords->x - coords->x1) || (int)(coords->y - coords->y1))
	{
		mlx_pixel_put(env->mlx_ptr, env->win_ptr, coords->x,
			coords->y, env->color);
		coords->x += env->x_step;
		coords->y += env->y_step;
	}
	mlx_destroy_image(env->mlx_ptr, env->img_ptr);
}

void	draw(t_fdf *env)
{
	t_coords	*coords;

	coords = (t_coords *)malloc(sizeof(t_coords));
	if (coords == NULL)
		return ;
	draw_horizontal(coords, env);
	draw_vertical(coords, env);
	free(coords);
}
