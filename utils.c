/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslaveev <dslaveev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:15:35 by dslaveev          #+#    #+#             */
/*   Updated: 2024/04/22 11:00:42 by dslaveev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_word_counter(char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

void	free_array(int **array, int height)
{
	int	y;

	y = 0;
	while (y < height)
	{
		free(array[y]);
		y++;
	}
	free(array);
}

void	free_data(t_map *data)
{
	int	i;

	if (data != NULL)
	{
		if (data->z_matrix != NULL)
		{
			i = 0;
			while (i < data->height)
			{
				free(data->z_matrix[i]);
				i++;
			}
			free(data->z_matrix);
		}
		free(data);
	}
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}
