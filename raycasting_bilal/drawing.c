/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 01:04:39 by bjniane           #+#    #+#             */
/*   Updated: 2025/02/20 01:39:38 by bjniane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_img	*get_texture(t_data *data)
{
	if (data->ray->flag)
	{
		if (sin(data->ray->ray_angle) > 0)
			return (data->so);
		else
			return (data->no);
	}
	else
	{
		if (cos(data->ray->ray_angle) > 0)
			return (data->ea);
		else
			return (data->we);
	}
	return (NULL);
}

int	get_color(t_img *image, int offset_x, int offset_y)
{
	char	*offset;
	int		color;

	if (offset_x < 0 || offset_x >= image->w_texture || offset_y < 0
		|| offset_y >= image->h_texture)
		return (1);
	offset = image->addr + (offset_y * image->line_length + offset_x
			* (image->bpp / 8));
	color = *(unsigned int *)offset;
	return (color);
}

void	draw_wall(t_data *data, int *top, int *buttom, int ray)
{
	t_var	var;

	var.offset_x = 0;
	var.offset_y = 0;
	var.wall_height = *buttom - *top;
	var.texture = get_texture(data);
	var.t_height = var.texture->h_texture;
	var.y = *top;
	if (data->ray->flag)
		var.offset_x = (data->ray->x % TILE_SIZE);
	else
		var.offset_x = (data->ray->y % TILE_SIZE);
	while (var.y < *buttom)
	{
		var.offset_y = (var.y - *top) * var.t_height / var.wall_height;
		var.color = get_color(var.texture, var.offset_x, var.offset_y);
		my_mlx_put_pixel(data, ray, var.y, var.color);
		var.y++;
	}
}

void	draw_f_c(t_data *data, int *top, int *buttom, int ray)
{
	int	i;

	i = 0;
	while (i < *top)
	{
		my_mlx_put_pixel(data, ray, i, data->texdetail.hex_roof);
		i++;
	}
	i = *buttom;
	while (i < data->h_w)
	{
		my_mlx_put_pixel(data, ray, i, data->texdetail.hex_floor);
		i++;
	}
}

void	render3dwall(t_data *data, int ray)
{
	t_var	var;

	var.projct_distance = 0;
	var.project_wall_height = 0;
	var.top_pixel = 0;
	var.buttom_pixel = 0;
	var.wall_height = 0;
	var.distance = data->ray->distance * cos(data->ray->ray_angle
			- data->p->angle);
	var.projct_distance = (data->w_w / 2) / tan(data->p->fov / 2);
	var.project_wall_height = (TILE_SIZE * var.projct_distance) / var.distance;
	var.wall_height = (int)var.project_wall_height;
	var.top_pixel = (data->h_w / 2) - (var.wall_height / 2);
	var.buttom_pixel = (data->h_w / 2) + (var.wall_height / 2);
	draw_f_c(data, &var.top_pixel, &var.buttom_pixel, ray);
	draw_wall(data, &var.top_pixel, &var.buttom_pixel, ray);
}
