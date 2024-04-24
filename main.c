/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslaveev <dslaveev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:00:16 by dslaveev          #+#    #+#             */
/*   Updated: 2024/04/22 11:34:46 by dslaveev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(void *param)
{
	t_fdf	*env;
	int		y;

	env = (t_fdf *)param;
	y = 0;
	while (y < env->map.height)
	{
		free(env->map.z_matrix[y]);
		y++;
	}
	free(env->map.z_matrix);
	free(env);
	exit(0);
}

void	leaks(void)
{
	system("leaks fdf");
}

t_fdf	*init_env(void)
{
	t_fdf	*env;

	env = (t_fdf *)malloc(sizeof(t_fdf));
	if (env == NULL)
		return (NULL);
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, WIDTH, HEIGHT, "fdf");
	env->shift_x = WIDTH / 2.5;
	env->shift_y = HEIGHT / 2.5;
	env->angle = 0;
	env->zoom = 20;
	return (env);
}

//	ft_printf("key: %d\n", key);
int	deal_key(int key, t_fdf *env)
{
	if (key == 126)
		env->shift_y = max(env->shift_y - 10, 0);
	else if (key == 125)
		env->shift_y += 10;
	else if (key == 124)
		env->shift_x += 10;
	else if (key == 123)
		env->shift_x = max(env->shift_x - 10, 0);
	else if (key == 53)
		close_window(env);
	else if (key == 69)
		zoom_in(env);
	else if (key == 78)
		zoom_out(env);
	else if (key == 18)
		rotate_left(env);
	else if (key == 19)
		rotate_right(env);
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	draw(env);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*env;

	if (argc != 2)
	{
		ft_printf("Usage: ./fdf <filename>\n");
		return (1);
	}
	atexit(leaks);
	env = init_env();
	if (env == NULL)
		return (1);
	read_file(argv[1], &(env->map));
	mlx_key_hook(env->win_ptr, deal_key, env);
	mlx_hook(env->win_ptr, 17, 0, close_window, env);
	draw(env);
	mlx_loop(env->mlx_ptr);
	return (0);
}
