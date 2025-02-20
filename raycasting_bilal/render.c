/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 08:58:19 by myerrou           #+#    #+#             */
/*   Updated: 2025/02/20 01:37:13 by bjniane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_put_pixel(t_data *data, int x, int y, int color)
{
	char	*offset;

	if (x < 0 || y < 0 || x >= data->w_w || y >= data->h_w)
		return ;
	offset = data->img->addr + (y * data->img->line_length + x * (data->img->bpp
				/ 8));
	*(unsigned int *)offset = color;
}

int	render(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_clear_window(data->mlx, data->mlx_win);
	cast_all_rays(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->img, 0, 0);
	return (0);
}
