/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslaveev <dslaveev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:09:25 by dslaveev          #+#    #+#             */
/*   Updated: 2024/04/21 10:29:33 by dslaveev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	rotate_left(t_fdf *env)
{
	env->angle = fmod(env->angle - 0.00872665 + 2 * 3.14, 2 * 3.14);
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	draw(env);
}

void	rotate_right(t_fdf *env)
{
	env->angle = fmod(env->angle + 0.00872665 + 2 * 3.14, 2 * 3.14);
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	draw(env);
}

void	apply_rotation(t_coords *coords, t_fdf *env)
{
	float	previous_x;
	float	previous_y;
	float	previous_x1;
	float	previous_y1;

	previous_x = coords->x;
	previous_y = coords->y;
	coords->x = previous_x * cos(env->angle) - previous_y * sin(env->angle);
	coords->y = previous_x * sin(env->angle) + previous_y * cos(env->angle);
	previous_x1 = coords->x1;
	previous_y1 = coords->y1;
	coords->x1 = previous_x1 * cos(env->angle) - previous_y1 * sin(env->angle);
	coords->y1 = previous_x1 * sin(env->angle) + previous_y1 * cos(env->angle);
}

void	zoom_in(t_fdf *env)
{
	env->zoom += 2;
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	draw(env);
}

void	zoom_out(t_fdf *env)
{
	env->zoom -= 2;
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	draw(env);
}
