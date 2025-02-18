#include "cub3d.h"

static int	parsing(t_data *data, char **argv)
{
	if (handle_file_error(data, argv[1], true) == FAILURE)
		return (FAILURE);
	parse_file_data(argv[1], data);
	if (bring_data(data, data->mapdetail.file) == FAILURE)
		return (FAILURE);
	if (map_is_valid(data, data->map) == FAILURE)
		return (FAILURE);
	if (texture_is_valid(data, &data->texdetail) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

t_img	*create_new_image(t_data *data, char *path)
{
	t_img	*image;

	image = malloc(sizeof(t_img));
	if (!image)
	{
		printf(BRED "Image allocation failed\n");
		exit_no_leaks(data, 1);
		return (NULL);
	}
	image->img = mlx_xpm_file_to_image(data->mlx, path, &image->w_texture, &image->h_texture);
	if (!image->img)
	{
		free(image);
		printf(BRED "Error in creation new image\n");
		exit_no_leaks(data, 1);
		return (NULL);
	}
	image->addr = mlx_get_data_addr(image->img, &image->bpp, &image->line_length, &image->endian);
	if (!image->addr)
	{
		free(image);
		mlx_destroy_image(data->mlx, image->img);
		printf(BRED "Error getting image data address\n");
		exit_no_leaks(data, 1);
		return (NULL);
	}
	return (image);
}

void	init_texture(t_data *data)
{
	data->NO = create_new_image(data, data->texdetail.north);
	data->EA = create_new_image(data, data->texdetail.east);
	data->SO = create_new_image(data, data->texdetail.south);
	data->WE = create_new_image(data, data->texdetail.west);
}

float	player_facing(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->h_map)
	{
		i = 0;
		while (i < data->w_map)
		{
			if (data->map[j][i] == 'N')
				return (1.5 * PI);
			else if (data->map[j][i] == 'S')
				return (0.5 * PI);
			else if (data->map[j][i] == 'E')
				return (0);
			else if (data->map[j][i] == 'W')
				return (PI);
			i++;
		}
		j++;
	}
	return (0);
}

void	ft_init(t_data *data)
{
	data->p = calloc(1, sizeof(t_player));
    data->ray = calloc(1, sizeof(t_ray));
	data->img = calloc(1, sizeof(t_img));
    data->p_x = 5;
    data->p_y = 5;
    data->W_W = data->w_map * TILE_SIZE;
    data->H_W = data->h_map * TILE_SIZE;
    data->p->player_x = data->p_x * TILE_SIZE + TILE_SIZE / 2;
    data->p->player_y = data->p_y * TILE_SIZE + TILE_SIZE / 2;
    data->p->angle = player_facing(data);
}

int main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (message("Path" ,"please add a .cub file", FAILURE));
	data = (t_data){0};
	if (parsing(&data, argv) != SUCCESS)
		return (exit_no_leaks(&data, 1), 1);
    ft_init(&data);
	data.mlx = mlx_init();
    data.mlx_win = mlx_new_window(data.mlx, data.W_W, data.H_W, "CUB3D_WINDOW");

    data.img->img = mlx_new_image(data.mlx, data.W_W, data.H_W);

    data.img->addr = mlx_get_data_addr(data.img->img, &data.img->bpp, &data.img->line_length, &data.img->endian);
	init_texture(&data);
    mlx_loop_hook(data.mlx, render, &data);
    mlx_hook(data.mlx_win, KeyPress, KeyPressMask,  key_hook, &data);
    mlx_hook(data.mlx_win, KeyRelease, KeyReleaseMask,  key_release, &data);
    mlx_hook(data.mlx_win, 17l, 0, close_window, &data);
    mlx_loop(data.mlx);
	return (SUCCESS);
}
