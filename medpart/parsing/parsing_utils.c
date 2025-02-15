#include "../../cub3d.h"

int	spaces(char c)
{
	if (c != ' ' && c != '\t' && c != '\r'
		&& c != '\n' && c != '\v' && c != '\f')
		return (FAILURE);
	else
		return (SUCCESS);
}

size_t	max_len(t_mapdetail map, int i)
{
	size_t	biggest_len;

	if (!map.file[i])
		return 0;
	biggest_len = ft_strlen(map.file[i]);
	while (map.file[i])
	{
		if (ft_strlen(map.file[i]) > biggest_len)
			biggest_len = ft_strlen(map.file[i]);
		i++;
	}
	return (biggest_len);
}
