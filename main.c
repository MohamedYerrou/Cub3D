#include "medpart/medpart.h"

void	init_texture_pixels(t_data *data)
{
	int	i;

	if (data->texture_pixels)
		free_tab((void **)data->texture_pixels);
	data->texture_pixels = ft_calloc(data->win_height + 1,
			sizeof * data->texture_pixels);
	if (!data->texture_pixels)
	{
		message(NULL, "Error in malloc", 1);
		exit (1);
	}
	i = 0;
	while (i < data->win_height)
	{
		data->texture_pixels[i] = ft_calloc(data->win_width + 1,
				sizeof * data->texture_pixels);
		if (!data->texture_pixels[i])
		{
			message(NULL, "Error in malloc", 1);
			exit (1);
		}
		i++;
	}
}

int	render(t_data *data)
{
	init_texture_pixels(data);
	render_frame(data);
	return (0);
}

static int	parsing(t_data *data, char **argv)
{
	if (handle_file_error(argv[1], true) == FAILURE)
		return (FAILURE);
	parse_file_data(argv[1], data);
	if (bring_data(data, data->mapdetail.file) == FAILURE)
		return (FAILURE);
	if (map_is_valid(data, data->map) == FAILURE)
		return (FAILURE);
	if (texture_is_valid(data, &data->texdetail) == FAILURE)
		return (FAILURE);
	init_player(data);
	return (SUCCESS);
}

int main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (message("Path" ,"please add a .cub file", FAILURE));
	data = (t_data){0};
	data.win_height = WIN_HEIGHT;
	data.win_width = WIN_WIDTH;
	data.texdetail.size = 64;
	if (parsing(&data, argv) != SUCCESS)
		return (FAILURE);
	init_mlx(&data);
	init_textures(&data);
	input_handler(&data);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
	return (SUCCESS);
}
