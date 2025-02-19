/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <myerrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 08:57:19 by myerrou           #+#    #+#             */
/*   Updated: 2025/02/19 09:20:20 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	check_valid_rgb(int *rgb)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			return (message_val(rgb[i], "Invalid RGB value", FAILURE));
		i++;
	}
	return (SUCCESS);
}

static unsigned long	convert_rgb_to_hex(int *rgb_tab)
{
	unsigned long	result;
	int				r;
	int				g;
	int				b;

	r = rgb_tab[0];
	g = rgb_tab[1];
	b = rgb_tab[2];
	result = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	return (result);
}

int	texture_is_valid(t_data *data, t_texdetail *textures)
{
	if (!textures->north || !textures->south || !textures->west
		|| !textures->east)
		return (message(data->mapdet.path, "Texture is missing", FAILURE));
	if (!textures->floor || !textures->roof)
		return (message(data->mapdet.path, "colors are missing", FAILURE));
	if (handle_file_error(textures->north, false) == FAILURE
		|| handle_file_error(textures->south, false) == FAILURE
		|| handle_file_error(textures->west, false) == FAILURE
		|| handle_file_error(textures->east, false) == FAILURE
		|| check_valid_rgb(textures->floor) == FAILURE
		|| check_valid_rgb(textures->roof) == FAILURE)
		return (FAILURE);
	textures->hex_floor = convert_rgb_to_hex(textures->floor);
	textures->hex_roof = convert_rgb_to_hex(textures->roof);
	return (SUCCESS);
}
