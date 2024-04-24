/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslaveev <dslaveev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:59:47 by dslaveev          #+#    #+#             */
/*   Updated: 2024/04/22 11:20:43 by dslaveev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *file)
{
	int		fd;
	char	*line;
	int		height;

	fd = open(file, O_RDONLY, 0);
	if (fd == -1)
		return (-1);
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		height += 1;
		free(line);
	}
	close(fd);
	return (height);
}

int	get_width(char *file)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY, 0);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	width = ft_word_counter(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	fill_matrix(t_map *data, char *line, int i)
{
	char	**split;
	int		j;

	split = ft_split(line, ' ');
	if (split == NULL)
		return ;
	j = 0;
	while (split[j] != NULL)
	{
		data->z_matrix[i][j] = ft_atoi(split[j]);
		free(split[j]);
		j++;
	}
	free(split);
}

void	read_file(char *file, t_map *data)
{
	int		fd;
	char	*line;
	int		i;

	data->height = get_height(file);
	data->width = get_width(file);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height));
	i = 0;
	while (i < data->height)
	{
		data->z_matrix[i] = (int *)malloc(sizeof(int) * (data->width));
		i++;
	}
	fd = open(file, O_RDONLY, 0);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		fill_matrix(data, line, i);
		free(line);
		i++;
	}
	close(fd);
}
