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
	data->mapdetail.index_end_of_map = i;
	return (i - index_value);
}

static int	fill_map_tab(t_mapdetail *mapdetail, char **map_tab, int index)
{
	int		i;
	int		j;

	mapdetail->width = find_biggest_len(mapdetail, index);
	i = 0;
	while (i < mapdetail->height)
	{
		j = 0;
		map_tab[i] = malloc(sizeof(char) * (mapdetail->width + 1));
		if (!map_tab[i])
			return (message(NULL, "Could not allocate memory", FAILURE));
		while (mapdetail->file[index][j] && mapdetail->file[index][j] != '\n')
		{
			map_tab[i][j] = mapdetail->file[index][j];
			j++;
		}
		while (j < mapdetail->width)
			map_tab[i][j++] = '\0';
		i++;
		index++;
	}
	map_tab[i] = NULL;
	return (SUCCESS);
}

static int	get_map_info(t_data *data, char **file, int i)
{
	data->mapdetail.height = count_map_lines(data, file, i);
	data->mapdetail.file = malloc(sizeof(char *) * (data->mapdetail.height + 1));
	if (!data->mapdetail.file)
		return (message(NULL, "Could not allocate memory", FAILURE));
	if (fill_map_tab(&data->mapdetail, data->mapdetail.file, i) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static void	change_space_into_wall(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->mapdetail.file[i])
	{
		j = 0;
		while (data->mapdetail.file[i][j] == ' ' || data->mapdetail.file[i][j] == '\t'
		|| data->mapdetail.file[i][j] == '\r'
		|| data->mapdetail.file[i][j] == '\v' || data->mapdetail.file[i][j] == '\f')
			j++;
		while (data->mapdetail.file[i][++j])
		{
			if (data->mapdetail.file[i][j] == ' '
				&& j != data->mapdetail.file[i][ft_strlen(data->mapdetail.file[i]) - 1])
				data->mapdetail.file[i][j] = '1';
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
