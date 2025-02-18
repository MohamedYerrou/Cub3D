#include "../../cub3d.h"

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

static int	fill_map_tab(t_data *data, char **map_tab, int index)
{
	int		i;
	int		j;

	data->w_map = max_len(data->mapdetail, index);
	i = 0;
	while (i < data->h_map)
	{
		j = 0;
		map_tab[i] = malloc(sizeof(char) * (data->w_map + 1));
		if (!map_tab[i])
			return (message(NULL, "Error in malloc", FAILURE));
		while (data->mapdetail.file[index][j] && data->mapdetail.file[index][j] != '\n')
		{
			map_tab[i][j] = data->mapdetail.file[index][j];
			// printf("%c",  map_tab[i][j]);
			j++;
		}
		while (j < data->w_map)
			map_tab[i][j++] = '\0';
		// printf("\n");
		i++;
		index++;
	}
	map_tab[i] = NULL;
	return (SUCCESS);
}

static int	get_map_info(t_data *data, char **file, int i)
{
	data->h_map = count_map_lines(data, file, i);
	data->map = malloc(sizeof(char *) * (data->h_map + 1));
	if (!data->map)
		return (message(NULL, "Error in malloc", FAILURE));
	if (fill_map_tab(data, data->map, i) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static void	spaces_are_walls(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] == ' ' || data->map[i][j] == '\t'
		|| data->map[i][j] == '\r'
		|| data->map[i][j] == '\v' || data->map[i][j] == '\f')
			j++;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == ' '
				&& j != data->map[i][ft_strlen(data->map[i]) - 1])
				data->map[i][j] = '1';
		}
		i++;
	}
}

int	create_map(t_data *data, char **file, int i)
{
	if (get_map_info(data, file, i) == FAILURE)
		return (FAILURE);
	spaces_are_walls(data);
	return (SUCCESS);
}
