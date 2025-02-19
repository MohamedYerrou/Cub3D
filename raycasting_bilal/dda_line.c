/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <myerrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 08:58:28 by myerrou           #+#    #+#             */
/*   Updated: 2025/02/19 08:58:29 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    dda_line(t_data *data, float x2, float y2, int color)
{
    float   dx;
    float   dy;
    float   x1;
    float   y1;
    float   L;
    float   Xinc;
    float   Yinc;

    x1 = data->p->player_x;
    y1 = data->p->player_y;
    dx = fabs(x2 - x1);
    dy = fabs(y2 - y1);
    if (dx > dy)
        L = dx;
    else
        L = dy;
    Xinc = (x2 - x1) / L;
    Yinc = (y2 - y1) / L;
    // printf("ray distance using dda_line algo is: %.2f\n",L);
    // printf("ray distance is: %.2f\n", data->ray->distance);
    for (float i = 0; i <= L; i++)
    {
        my_mlx_put_pixel(data, roundf(x1), roundf(y1), color);
        x1 += Xinc;
        y1 += Yinc;
    }
}