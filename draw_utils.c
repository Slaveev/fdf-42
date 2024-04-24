/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslaveev <dslaveev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:10:58 by dslaveev          #+#    #+#             */
/*   Updated: 2024/04/22 11:03:47 by dslaveev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_horizontal(t_coords *coords, t_fdf *env)
{
	int	y;
	int	x;

	y = 0;
	while (y < env->map.height)
	{
		x = 0;
		while (x < env->map.width)
		{
			coords->x = x;
			coords->x1 = x;
			coords->y = y;
			coords->y1 = (y + 1);
			if (coords->y1 < env->map.height)
				line_draw(coords, env);
			x++;
		}
		y++;
	}
}

void	draw_vertical(t_coords *coords, t_fdf *env)
{
	int	x;
	int	y;

	x = 0;
	while (x < env->map.width)
	{
		y = 0;
		while (y < env->map.height)
		{
			coords->y = y;
			coords->y1 = y;
			coords->x = x;
			coords->x1 = (x + 1);
			if (coords->x1 < env->map.width)
				line_draw(coords, env);
			y++;
		}
		x++;
	}
}

// transformation for a point (x, y) around the origin
// by an angle theta is (x*cos(theta) - y*sin(theta),
// x*sin(theta) + y*cos(theta)).
void	adjust_z_coords(t_coords *coords, t_fdf *env)
{
	coords->z = 0;
	coords->z1 = 0;
	if ((int)coords->y < env->map.height && (int)coords->x < env->map.width)
		coords->z = env->map.z_matrix[(int)coords->y][(int)coords->x];
	if ((int)coords->y1 < env->map.height && (int)coords->x1 < env->map.width)
		coords->z1 = env->map.z_matrix[(int)coords->y1][(int)coords->x1];
	coords->x -= coords->z;
	coords->y -= coords->z;
	coords->x1 -= coords->z1;
	coords->y1 -= coords->z1;
}

void	adjust_coords(t_coords *coords, t_fdf *env)
{
	int	shift_x;
	int	shift_y;

	shift_x = ft_abs(env->shift_x);
	shift_y = ft_abs(env->shift_y);
	coords->x += shift_x;
	coords->y += shift_y;
	coords->x1 += shift_x;
	coords->y1 += shift_y;
}
