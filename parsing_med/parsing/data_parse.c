/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <myerrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 08:57:24 by myerrou           #+#    #+#             */
/*   Updated: 2025/02/19 09:18:05 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	free_tab(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

static int	n_of_lines(char *path)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		message(path, strerror(errno), errno);
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			line_count++;
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (line_count);
}

static void	fill_tab(int row, int column, int i, t_data *data)
{
	char	*line;

	line = get_next_line(data->mapdet.fd);
	while (line != NULL)
	{
		data->mapdet.file[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!data->mapdet.file[row])
		{
			message(NULL, "Error in malloc", 0);
			return (free_tab((void **)data->mapdet.file));
		}
		while (line[i] != '\0')
			data->mapdet.file[row][column++] = line[i++];
		data->mapdet.file[row++][column] = '\0';
		column = 0;
		i = 0;
		free(line);
		line = get_next_line(data->mapdet.fd);
	}
	data->mapdet.file[row] = NULL;
}

void	parse_file_data(char *path, t_data *data)
{
	int		row;
	int		i;
	size_t	column;

	i = 0;
	row = 0;
	column = 0;
	data->mapdet.line_count = n_of_lines(path);
	data->mapdet.path = path;
	data->mapdet.file = ft_calloc(data->mapdet.line_count
			+ 1, sizeof(char *));
	if (!(data->mapdet.file))
	{
		message(NULL, "Error in malloc", 0);
		return ;
	}
	data->mapdet.fd = open(path, O_RDONLY);
	if (data->mapdet.fd < 0)
		message(path, strerror(errno), FAILURE);
	else
	{
		fill_tab(row, column, i, data);
		close(data->mapdet.fd);
	}
}
