#include "../../cub3d.h"

static int	is_end_of_map(t_mapdetail *map)
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
		return (message(data->mapdetail.path, "map is no where to be found", FAILURE));
	if (check_map_sides(map_tab) == FAILURE)
		return (message(data->mapdetail.path, "Map is not dilimeted by ones", FAILURE));
	if (data->h_map < 3)
		return (message(data->mapdetail.path, "map is less than 3 lines", FAILURE));
	if (is_end_of_map(&data->mapdetail) == FAILURE)
		return (message(data->mapdetail.path, "Map should be last element", FAILURE));
	return (SUCCESS);
}
