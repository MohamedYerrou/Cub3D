#include "../medpart.h"

static int	count_map_lines(t_data *data, char **file, int i)
{
	int	index_value;
	int	j;

	index_value = i;
	while (file[i])
	{
		j = 0;
		while (file[i][j] == ' ' || file[i][j] == '\t' || file[i][j] == '\r'
		|| file[i][j] == '\v' || file[i][j] == '\f')
			j++;
		if (file[i][j] != '1')
			break ;
		i++;
	}
	data->mapinfo.index_end_of_map = i;
	return (i - index_value);
}

static int	fill_map_tab(t_mapinfo *mapinfo, char **map_tab, int index)
{
	int		i;
	int		j;

	mapinfo->width = find_biggest_len(mapinfo, index);
	i = 0;
	while (i < mapinfo->height)
	{
		j = 0;
		map_tab[i] = malloc(sizeof(char) * (mapinfo->width + 1));
		if (!map_tab[i])
			return (message(NULL, "Could not allocate memory", FAILURE));
		while (mapinfo->file[index][j] && mapinfo->file[index][j] != '\n')
		{
			map_tab[i][j] = mapinfo->file[index][j];
			j++;
		}
		while (j < mapinfo->width)
			map_tab[i][j++] = '\0';
		i++;
		index++;
	}
	map_tab[i] = NULL;
	return (SUCCESS);
}

static int	get_map_info(t_data *data, char **file, int i)
{
	data->mapinfo.height = count_map_lines(data, file, i);
	data->mapinfo.file = malloc(sizeof(char *) * (data->mapinfo.height + 1));
	if (!data->mapinfo.file)
		return (message(NULL, "Could not allocate memory", FAILURE));
	if (fill_map_tab(&data->mapinfo, data->mapinfo.file, i) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static void	change_space_into_wall(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->mapinfo.file[i])
	{
		j = 0;
		while (data->mapinfo.file[i][j] == ' ' || data->mapinfo.file[i][j] == '\t'
		|| data->mapinfo.file[i][j] == '\r'
		|| data->mapinfo.file[i][j] == '\v' || data->mapinfo.file[i][j] == '\f')
			j++;
		while (data->mapinfo.file[i][++j])
		{
			if (data->mapinfo.file[i][j] == ' '
				&& j != data->mapinfo.file[i][ft_strlen(data->mapinfo.file[i]) - 1])
				data->mapinfo.file[i][j] = '1';
		}
		i++;
	}
}

int	create_map(t_data *data, char **file, int i)
{
	if (get_map_info(data, file, i) == FAILURE)
		return (FAILURE);
	change_space_into_wall(data);
	return (SUCCESS);
}
