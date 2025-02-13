#include "cub3d.h"

void    my_mlx_put_pixel(t_data *data, int x, int y, int color)
{
    char    *offset;
    if (x < 0 || y < 0 || x >= data->W_W || y >= data->H_W)
        return ;
    offset = data->addr + (y * data->line_length + x * (data->bpp / 8));
    *(unsigned int *)offset = color;
}

void    render_map(t_data *data)
{
    int color;

    color = 0;
    // mlx_clear_
    for (int y = 0; y < data->h_map; y++)
    {
        for (int x = 0; x < data->w_map; x++)
        {
            if (data->map[y][x] == '1')
                color = 0x000000;
            else if (data->map[y][x] == '0')
                color = 0xffffff;
            for (int h = 0; h < TILE_SIZE; h++)
            {
                for (int w = 0; w < TILE_SIZE; w++)
                {
                    my_mlx_put_pixel(data, (x * TILE_SIZE) + w, (y * TILE_SIZE) + h, color);
                }
            }
        }
    }
}

void    render_player(t_data *data)
{
    int   x, y;
    float   end_x, end_y;

    x = data->p->player_x;
    y = data->p->player_y;
    end_x = x + cos(data->p->angle) * 30;
    end_y = y + sin(data->p->angle) * 30;
    if (x < 0 || x >= data->W_W || y < 0 || y >= data->H_W)
    {
        printf("Playr out of bounds! Player position: (%d, %d)\n", x, y);
        return;
    }
    my_mlx_put_pixel(data, data->p->player_x, data->p->player_y, 0x0000FF);
    dda_line(data, end_x, end_y, 0x0000FF);
}

int    render(void *param)
{
    t_data *data;
    data = (t_data *)param;
    mlx_clear_window(data->mlx, data->mlx_win);
    render_map(data);
    cast_all_rays(data);
    render_player(data);
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
    return (0);
}
