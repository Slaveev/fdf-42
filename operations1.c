/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslaveev <dslaveev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:37:39 by dslaveev          #+#    #+#             */
/*   Updated: 2024/04/21 10:33:45 by dslaveev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_zoom(t_coords *coords, int zoom)
{
	int	normalize_num;

	normalize_num = 2;
	coords->x = (coords->x / normalize_num) * zoom;
	coords->y = (coords->y / normalize_num) * zoom;
	coords->x1 = (coords->x1 / normalize_num) * zoom;
	coords->y1 = (coords->y1 / normalize_num) * zoom;
}
