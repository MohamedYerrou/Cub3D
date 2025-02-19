/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <myerrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 08:57:40 by myerrou           #+#    #+#             */
/*   Updated: 2025/02/19 09:18:05 by myerrou          ###   ########.fr       */
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
	if (data->EA)
	{
		if (data->EA->img)
			mlx_destroy_image(data->mlx, data->EA->img);
		free(data->EA);
	}
	if (data->WE)
	{
		if (data->WE->img)
			mlx_destroy_image(data->mlx, data->WE->img);
		free(data->WE);
	}
	if (data->NO)
	{
		if (data->NO->img)
			mlx_destroy_image(data->mlx, data->NO->img);
		free(data->NO);
	}
	if (data->SO)
	{
		if (data->SO->img)
			mlx_destroy_image(data->mlx, data->SO->img);
		free(data->SO);
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
