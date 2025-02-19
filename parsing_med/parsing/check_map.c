/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <myerrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 08:57:17 by myerrou           #+#    #+#             */
/*   Updated: 2025/02/19 09:18:05 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	is_end_of_map(t_mapdet *map)
{
	int	i;
	int	j;

	i = map->index_end_of_map;
	while (map->file[i])
	{
		j = 0;
		while (map->file[i][j])
		{
			if (map->file[i][j] != ' ' && map->file[i][j] != '\t'
				&& map->file[i][j] != '\r' && map->file[i][j] != '\n'
				&& map->file[i][j] != '\v' && map->file[i][j] != '\f')
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	map_is_valid(t_data *data, char **map_tab)
{
	if (!data->map)
		return (message(data->mapdet.path, "map is not found", FAILURE));
	if (check_map_sides(map_tab) == FAILURE)
		return (message(data->mapdet.path, "dilimet map by ones", FAILURE));
	if (data->h_map < 3)
		return (message(data->mapdet.path, "map less than 3 lines", FAILURE));
	if (is_end_of_map(&data->mapdet) == FAILURE)
		return (message(data->mapdet.path, "Map isn't last element", FAILURE));
	return (SUCCESS);
}
