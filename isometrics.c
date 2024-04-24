/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometrics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslaveev <dslaveev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:11:26 by dslaveev          #+#    #+#             */
/*   Updated: 2024/04/20 09:49:49 by dslaveev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	apply_isometric(t_coords *coords, int z_start, int z_end)
{
	ft_isometric(&coords->x, &coords->y, z_start);
	ft_isometric(&coords->x1, &coords->y1, z_end);
}
