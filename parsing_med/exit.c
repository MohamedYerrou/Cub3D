/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 08:57:40 by myerrou           #+#    #+#             */
/*   Updated: 2025/02/20 01:40:18 by bjniane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_texdetail(t_texdetail *textures)
{
	if (textures->north)
		free(textures->north);
	if (textures->south)
		free(textures->south);
	if (textures->west)
		free(textures->west);
	if (textures->east)
		free(textures->east);
	if (textures->floor)
		free(textures->floor);
	if (textures->roof)
		free(textures->roof);
}

int	free_data(t_data *data)
{
	free_texdetail(&data->texdetail);
	free(data->ray);
	free(data->p);
	if (data->mapdet.fd > 0)
		close(data->mapdet.fd);
	if (data->mapdet.file)
		free_tab((void **)data->mapdet.file);
	if (data->map)
		free_tab((void **)data->map);
	return (FAILURE);
}

void	free_directions(t_data *data)
{
	if (data->ea)
	{
		if (data->ea->img)
			mlx_destroy_image(data->mlx, data->ea->img);
		free(data->ea);
	}
	if (data->we)
	{
		if (data->we->img)
			mlx_destroy_image(data->mlx, data->we->img);
		free(data->we);
	}
	if (data->no)
	{
		if (data->no->img)
			mlx_destroy_image(data->mlx, data->no->img);
		free(data->no);
	}
	if (data->so)
	{
		if (data->so->img)
			mlx_destroy_image(data->mlx, data->so->img);
		free(data->so);
	}
}

void	exit_no_leaks(t_data *data, int status)
{
	if (!data)
		exit(status);
	if (data->mlx && data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->img)
	{
		if (data->img->img)
			mlx_destroy_image(data->mlx, data->img->img);
		free(data->img);
	}
	free_directions(data);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		mlx_loop_end(data->mlx);
		free(data->mlx);
	}
	if (data)
		free_data(data);
	exit(status);
}
