#include "cub3d.h"

// void	init_texture_pixels(t_data *data)
// {
// 	int	i;

// 	if (data->texture_pixels)
// 		free_tab((void **)data->texture_pixels);
// 	data->texture_pixels = ft_calloc(data->h_map + 1,
// 			sizeof * data->texture_pixels);
// 	if (!data->texture_pixels)
// 	{
// 		message(NULL, "Error in malloc", 1);
// 		exit (1);
// 	}
// 	i = 0;
// 	while (i < data->h_map)
// 	{
// 		data->texture_pixels[i] = ft_calloc(data->w_map + 1,
// 				sizeof * data->texture_pixels);
// 		if (!data->texture_pixels[i])
// 		{
// 			message(NULL, "Error in malloc", 1);
// 			exit (1);
// 		}
// 		i++;
// 	}
// }

// int	render(t_data *data)
// {
// 	init_texture_pixels(data);
// 	render_frame(data);
// 	return (0);
// }

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
	// init_player(data);
	return (SUCCESS);
}

int main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (message("Path" ,"please add a .cub file", FAILURE));
	data = (t_data){0};
	if (parsing(&data, argv) != SUCCESS)
		return (FAILURE);
	data.p = calloc(1, sizeof(t_paleyr));
    data.ray = calloc(1, sizeof(t_ray));
    data.p_x = 5;
    data.p_y = 5;
    // data.w_map = 25;
    // data.h_map = 9;
    data.W_W = data.w_map * TILE_SIZE;
    data.H_W = data.h_map * TILE_SIZE;
    data.p->player_x = data.p_x * TILE_SIZE + TILE_SIZE / 2;
    data.p->player_y = data.p_y * TILE_SIZE + TILE_SIZE / 2;
    data.p->angle = 0;
	// init_mlx(&data);
	// init_textures(&data);
	// input_handler(&data);
	// mlx_loop_hook(data.mlx, render, &data);
	// mlx_loop(data.mlx);

    data.mlx = mlx_init();
    data.mlx_win = mlx_new_window(data.mlx, data.W_W, data.H_W, "CUB3D_WINDOW");

    data.img = mlx_new_image(data.mlx, data.W_W, data.H_W);

    data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_length, &data.endian);
    render(&data);
    mlx_loop_hook(data.mlx, render, &data);
    mlx_hook(data.mlx_win, 02, 1L<<0,  key_hook, &data);
    mlx_hook(data.mlx_win, 03, 1L<<1,  key_release, &data);
    mlx_hook(data.mlx_win, 17, 0, close_window, &data);
    mlx_loop(data.mlx);
	return (SUCCESS);
}
