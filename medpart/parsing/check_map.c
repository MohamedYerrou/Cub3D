#include "../medpart.h"

static int	handle_components(t_data *data, char **map_tab)
{
	int	i;
	int	j;

	i = 0;
	data->player.dir = '0';
	while (map_tab[i] != NULL)
	{
		j = 0;
		while (map_tab[i][j])
		{
			while (data->map[i][j] == ' ' || data->map[i][j] == '\t'
			|| data->map[i][j] == '\r'
			|| data->map[i][j] == '\v' || data->map[i][j] == '\f')
				j++;
			if (!(ft_strchr("10NSEW", map_tab[i][j])))
				return (message(data->mapinfo.path, "Invalid character in map", FAILURE));
			if (ft_strchr("NSEW", map_tab[i][j]) && data->player.dir != '0')
				return (message(data->mapinfo.path, "Map has more than one player", FAILURE));
			if (ft_strchr("NSEW", map_tab[i][j]) && data->player.dir == '0')
				data->player.dir = map_tab[i][j];
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

static int	is_valid_position(t_data *data, char **map_tab)
{
	int	i;
	int	j;

	i = (int)data->player.pos_y;
	j = (int)data->player.pos_x;
	if (ft_strlen(map_tab[i - 1]) < (size_t)j
		|| ft_strlen(map_tab[i + 1]) < (size_t)j
		|| spaces(map_tab[i][j - 1]) == 0
		|| spaces(map_tab[i][j + 1]) == 0
		|| spaces(map_tab[i - 1][j]) == 0
		|| spaces(map_tab[i + 1][j]) == 0)
		return (1);
	return (0);
}

static int	player_position(t_data *data, char **map_tab)
{
	int	i;
	int	j;

	if (data->player.dir == '0')
		return (message(data->mapinfo.path, "(expected N, S, E or W)", FAILURE));
	i = 0;
	while (map_tab[i])
	{
		j = 0;
		while (map_tab[i][j])
		{
			if (ft_strchr("NSEW", map_tab[i][j]))
			{
				data->player.pos_x = (double)j + 0.5;
				data->player.pos_y = (double)i + 0.5;
				map_tab[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	if (is_valid_position(data, map_tab) == FAILURE)
		return (message(data->mapinfo.path, "Invalid player position", FAILURE));
	return (SUCCESS);
}

static int	is_end_of_map(t_mapinfo *map)
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
	if (!data->mapinfo.file)
		return (message(data->mapinfo.path, "Missing map", FAILURE));
	if (handle_sides_of_map(&data->mapinfo, map_tab) == FAILURE)
		return (message(data->mapinfo.path, "Map is not surrounded by walls", FAILURE));
	if (data->mapinfo.height < 3)
		return (message(data->mapinfo.path, "Map is not at least 3 lines high", FAILURE));
	if (handle_components(data, map_tab) == FAILURE)
		return (FAILURE);
	if (player_position(data, map_tab) == FAILURE)
		return (FAILURE);
	if (is_end_of_map(&data->mapinfo) == FAILURE)
		return (message(data->mapinfo.path, "Map is not the last element in file", FAILURE));
	return (SUCCESS);
}
