/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 08:58:26 by myerrou           #+#    #+#             */
/*   Updated: 2025/02/20 01:21:30 by bjniane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotate_player(t_data *data, int direction)
{
	if (direction == 1)
	{
		data->p->angle += ROTATION_SPEED;
		if (data->p->angle > 2 * PI)
			data->p->angle -= 2 * PI;
	}
	else
	{
		data->p->angle -= ROTATION_SPEED;
		if (data->p->angle < 0)
			data->p->angle += 2 * PI;
	}
}

void	move_player(t_data *data, float move_x, float move_y)
{
	int	newx;
	int	newy;
	int	x;
	int	y;

	newx = roundf(data->p->player_x + move_x);
	newy = roundf(data->p->player_y + move_y);
	x = newx / TILE_SIZE;
	y = newy / TILE_SIZE;
	if (data->map[y][x] != '1')
	{
		data->p->player_x = newx;
		data->p->player_y = newy;
	}
}

void	movement(t_data *data)
{
	float	move_x;
	float	move_y;

	handle_movement(data, &move_x, &move_y);
	handle_rotation(data);
	move_player(data, move_x, move_y);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		printf(BGREEN "ESC exiting\n");
		exit_no_leaks(data, 0);
	}
	if (keycode == 97)
		data->p->l_r = 1;
	else if (keycode == 100)
		data->p->l_r = -1;
	else if (keycode == 119)
		data->p->u_d = 1;
	else if (keycode == 115)
		data->p->u_d = -1;
	else if (keycode == 65361)
		data->p->rotate = -1;
	else if (keycode == 65363)
		data->p->rotate = 1;
	movement(data);
	render(data);
	return (0);
}

int	key_release(int key, t_data *data)
{
	if (key == 97)
		data->p->l_r = 0;
	else if (key == 100)
		data->p->l_r = 0;
	else if (key == 119)
		data->p->u_d = 0;
	else if (key == 115)
		data->p->u_d = 0;
	else if (key == 65361)
		data->p->rotate = 0;
	else if (key == 65363)
		data->p->rotate = 0;
	return (0);
}
