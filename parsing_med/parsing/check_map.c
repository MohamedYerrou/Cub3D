/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <myerrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 08:57:17 by myerrou           #+#    #+#             */
/*   Updated: 2025/02/21 01:38:57 by myerrou          ###   ########.fr       */
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

int	check_01eswn(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] != 'N' && data->map[j][i] != 'S'
				&& data->map[j][i] != 'W' && data->map[j][i] != 'E'
				&& data->map[j][i] != '0' && data->map[j][i] != '1'
				&& data->map[j][i] != '\t' && data->map[j][i] != ' ')
			{
				printf("Map not valid\n");
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	check_one_player(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'N' || data->map[j][i] == 'S'
				|| data->map[j][i] == 'W' || data->map[j][i] == 'E')
				return (0);
			i++;
		}
		j++;
	}
	printf("Player not found\n");
	return (1);
}

int	map_is_valid(t_data *data, char **map_tab)
{
	if (!data->map)
		return (message(data->mapdet.path, "map is not found", FAILURE));
	if (check_map_sides(map_tab) == FAILURE)
		return (message(data->mapdet.path, "dilimet map by ones", FAILURE));
	if (data->h_map < 3)
		return (message(data->mapdet.path, "map less than 3 lines", FAILURE));
	if (check_dup(data, 0, 0) || check_one_player(data))
		return (message(data->mapdet.path, "Player not valid", FAILURE));
	if (check_01eswn(data))
		return (message(data->mapdet.path, "Map not valid", FAILURE));
	if (is_end_of_map(&data->mapdet) == FAILURE)
		return (message(data->mapdet.path, "Map isn't last element", FAILURE));
	return (SUCCESS);
}
