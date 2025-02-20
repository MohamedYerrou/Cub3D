/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 08:58:28 by myerrou           #+#    #+#             */
/*   Updated: 2025/02/20 01:21:39 by bjniane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	close_window(t_data *data)
{
	printf(BGREEN "closed window\n");
	exit_no_leaks(data, 0);
	return (0);
}

float	normalize_angle(float angle)
{
	while (angle < 2 * PI && angle > 2 * PI)
	{
		if (angle > 2 * PI)
			angle -= 2 * PI;
		if (angle < 2 * PI)
			angle += 2 * PI;
	}
	return (angle);
}

void	handle_movement(t_data *data, float *move_x, float *move_y)
{
	*move_x = 0;
	*move_y = 0;
	if (data->p->l_r == 1)
	{
		*move_x = -cos(data->p->angle + PI / 2) * PLAYER_SPEED;
		*move_y = -sin(data->p->angle + PI / 2) * PLAYER_SPEED;
	}
	else if (data->p->l_r == -1)
	{
		*move_x = cos(data->p->angle + PI / 2) * PLAYER_SPEED;
		*move_y = sin(data->p->angle + PI / 2) * PLAYER_SPEED;
	}
	else if (data->p->u_d == 1)
	{
		*move_x = cos(data->p->angle) * PLAYER_SPEED;
		*move_y = sin(data->p->angle) * PLAYER_SPEED;
	}
	else if (data->p->u_d == -1)
	{
		*move_x = -cos(data->p->angle) * PLAYER_SPEED;
		*move_y = -sin(data->p->angle) * PLAYER_SPEED;
	}
}

void	handle_rotation(t_data *data)
{
	if (data->p->rotate == 1)
		rotate_player(data, 1);
	else if (data->p->rotate == -1)
		rotate_player(data, -1);
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
	image->img = mlx_xpm_file_to_image(data->mlx, path, &image->w_texture,
			&image->h_texture);
	if (!image->img)
	{
		free(image);
		printf(BRED "Error in creation new image\n");
		exit_no_leaks(data, 1);
		return (NULL);
	}
	image->addr = mlx_get_data_addr(image->img, &image->bpp,
			&image->line_length, &image->endian);
	return (image);
}
