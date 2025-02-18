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

	line = get_next_line(data->mapdetail.fd);
	while (line != NULL)
	{
		data->mapdetail.file[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!data->mapdetail.file[row])
		{
			message(NULL, "Error in malloc", 0);
			return (free_tab((void **)data->mapdetail.file));
		}
		while (line[i] != '\0')
			data->mapdetail.file[row][column++] = line[i++];
		data->mapdetail.file[row++][column] = '\0';
		column = 0;
		i = 0;
		free(line);
		line = get_next_line(data->mapdetail.fd);
	}
	data->mapdetail.file[row] = NULL;
}

void	parse_file_data(char *path, t_data *data)
{
	int		row;
	int		i;
	size_t	column;

	i = 0;
	row = 0;
	column = 0;
	data->mapdetail.line_count = n_of_lines(path);
	data->mapdetail.path = path;
	data->mapdetail.file = ft_calloc(data->mapdetail.line_count
			+ 1, sizeof(char *));
	if (!(data->mapdetail.file))
	{
		message(NULL, "Error in malloc", 0);
		return ;
	}
	data->mapdetail.fd = open(path, O_RDONLY);
	if (data->mapdetail.fd < 0)
		message(path, strerror(errno), FAILURE);
	else
	{
		fill_tab(row, column, i, data);
		close(data->mapdetail.fd);
	}
}
