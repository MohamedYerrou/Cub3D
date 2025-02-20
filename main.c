/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 08:58:09 by myerrou           #+#    #+#             */
/*   Updated: 2025/02/20 01:39:38 by bjniane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parsing(t_data *data, char **argv)
{
	if (handle_file_error(argv[1], true) == FAILURE)
		return (FAILURE);
	parse_file_data(argv[1], data);
	if (bring_data(data, data->mapdet.file) == FAILURE)
		return (FAILURE);
	if (map_is_valid(data, data->map) == FAILURE)
		return (FAILURE);
	if (texture_is_valid(data, &data->texdetail) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

void	init_texture(t_data *data)
{
	data->no = create_new_image(data, data->texdetail.north);
	data->ea = create_new_image(data, data->texdetail.east);
	data->so = create_new_image(data, data->texdetail.south);
	data->we = create_new_image(data, data->texdetail.west);
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
	data->w_w = data->w_map * TILE_SIZE;
	data->h_w = data->h_map * TILE_SIZE;
	data->p->player_x = data->p_x * TILE_SIZE + TILE_SIZE / 2;
	data->p->player_y = data->p_y * TILE_SIZE + TILE_SIZE / 2;
	data->p->fov = FOV_ANGLE * (PI / 180);
	data->p->angle = player_facing(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (message("Path", "please add a .cub file", FAILURE));
	data = (t_data){0};
	if (parsing(&data, argv) != SUCCESS)
		return (exit_no_leaks(&data, 1), 1);
	ft_init(&data);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, data.w_w, data.h_w, "CUB3D_WINDOW");
	data.img->img = mlx_new_image(data.mlx, data.w_w, data.h_w);
	data.img->addr = mlx_get_data_addr(data.img->img, &data.img->bpp,
			&data.img->line_length, &data.img->endian);
	init_texture(&data);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, key_hook, &data);
	mlx_hook(data.mlx_win, KeyRelease, KeyReleaseMask, key_release, &data);
	mlx_hook(data.mlx_win, 17l, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (SUCCESS);
}
