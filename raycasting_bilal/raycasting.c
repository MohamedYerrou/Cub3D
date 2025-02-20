/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 08:58:23 by myerrou           #+#    #+#             */
/*   Updated: 2025/02/20 01:37:13 by bjniane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	wall_hit(t_data *data, float x, float y, char c)
{
	int	w;
	int	h;

	if (x < 0 || y < 0 || x >= data->w_w || y >= data->h_w)
		return (0);
	w = floor(x / TILE_SIZE);
	h = floor(y / TILE_SIZE);
	if (c == 'x' && cos(data->ray->ray_angle) < 0)
		w--;
	if (c == 'y' && sin(data->ray->ray_angle) < 0)
		h--;
	if (!data->map[h][w] || data->map[h][w] == '1')
		return (0);
	return (1);
}

float	get_horz(t_data *data, float angle, float *horz_x, float *horz_y)
{
	float	xstep;
	float	ystep;

	xstep = 0;
	ystep = 0;
	*horz_y = floor(data->p->player_y / TILE_SIZE) * TILE_SIZE;
	if (sin(angle) > 0)
		*horz_y += TILE_SIZE;
	*horz_x = data->p->player_x + (*horz_y - data->p->player_y) / tan(angle);
	ystep = TILE_SIZE;
	if (sin(angle) < 0)
		ystep *= -1;
	xstep = ystep / tan(angle);
	if (cos(angle) > 0 && xstep < 0)
		xstep *= -1;
	if (cos(angle) < 0 && xstep > 0)
		xstep *= -1;
	while (wall_hit(data, *horz_x, *horz_y, 'y'))
	{
		*horz_x += xstep;
		*horz_y += ystep;
	}
	return (sqrt(pow(*horz_x - data->p->player_x, 2) + pow(*horz_y
				- data->p->player_y, 2)));
}

float	get_vert(t_data *data, float angle, float *vert_x, float *vert_y)
{
	float	xstep;
	float	ystep;

	xstep = 0;
	ystep = 0;
	*vert_x = floor(data->p->player_x / TILE_SIZE) * TILE_SIZE;
	if (cos(angle) > 0)
		*vert_x += TILE_SIZE;
	*vert_y = data->p->player_y + (*vert_x - data->p->player_x) * tan(angle);
	xstep = TILE_SIZE;
	if (cos(angle) < 0)
		xstep *= -1;
	ystep = xstep * tan(angle);
	if (sin(angle) > 0 && ystep < 0)
		ystep *= -1;
	if (sin(angle) < 0 && ystep > 0)
		ystep *= -1;
	while (wall_hit(data, *vert_x, *vert_y, 'x'))
	{
		*vert_x += xstep;
		*vert_y += ystep;
	}
	return (sqrt(pow(*vert_x - data->p->player_x, 2) + pow(*vert_y
				- data->p->player_y, 2)));
}

void	cast_ray(t_data *data, float angle)
{
	t_var	var;

	var.vert_x = 0;
	var.vert_y = 0;
	var.horz_x = 0;
	var.horz_y = 0;
	var.dist_vert = 0;
	var.dist_horz = 0;
	var.dist_vert = get_vert(data, angle, &var.vert_x, &var.vert_y);
	var.dist_horz = get_horz(data, angle, &var.horz_x, &var.horz_y);
	if (var.dist_horz < var.dist_vert)
	{
		data->ray->flag = 1;
		data->ray->x = var.horz_x;
		data->ray->y = var.horz_y;
		data->ray->distance = var.dist_horz;
	}
	else
	{
		data->ray->x = var.vert_x;
		data->ray->y = var.vert_y;
		data->ray->distance = var.dist_vert;
	}
}

void	cast_all_rays(t_data *data)
{
	int	ray;

	ray = 0;
	data->ray->ray_angle = data->p->angle - (data->p->fov / 2);
	while (ray < data->w_w)
	{
		data->ray->flag = 0;
		data->ray->ray_angle = normalize_angle(data->ray->ray_angle);
		cast_ray(data, data->ray->ray_angle);
		render3dwall(data, ray);
		data->ray->ray_angle += data->p->fov / data->w_w;
		ray++;
	}
}
