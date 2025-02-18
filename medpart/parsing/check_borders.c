#include "../../cub3d.h"

int is_out_of_bounds(char **map, int i, int j)
{
	if (i == 0 || j == 0 || map[i + 1] == NULL 
		|| map[i][j + 1] == '\0' || j >= (int)ft_strlen(map[i - 1])
		|| j >= (int)ft_strlen(map[i + 1]))
		return (FAILURE);
	return (SUCCESS);
}

int check_map_sides(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == 'W' 
				|| map[i][j] == 'E' || map[i][j] == 'S' 
				|| map[i][j] == 'N')
			{
				if (is_out_of_bounds(map, i, j) == FAILURE ||
					map[i - 1][j] == ' ' || map[i + 1][j] == ' ' 
					|| map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
					return (FAILURE);
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
