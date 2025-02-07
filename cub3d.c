#include "cub3d.h"

int close_window()
{
    printf("closed window\n");
    exit(0);
}

void    my_mlx_put_pixel(t_data *data, int x, int y, int color)
{
    char    *offset;

    offset = data->addr + (y * data->line_length + x * (data->bpp / 8));
    *(unsigned int *)offset = color;
}

int ft_abs(int n)
{
    if (n < 0)
        n *= -1;
    return (n);
}

void    dda_line(t_data *data, float x1, float y1, float x2, float y2)
{
    float   dx;
    float   dy;
    float   L;
    float   Xinc;
    float   Yinc;

    dx = ft_abs(x2 - x1);
    dy = ft_abs(y2 - y1);
    if (dx > dy)
        L = dx;
    else
        L = dy;
    Xinc = (x2 - x1) / L;
    Yinc = (y2 - y1) / L;
    for (int i = 0; i <= L; i++)
    {
        my_mlx_put_pixel(data, roundf(x1), roundf(y1), 0xFF0000);
        x1 += Xinc;
        y1 += Yinc;
    }
}

void    render_map(t_data *data)
{
    for (int y = 0; y < data->h_map; y++)
    {
        for (int x = 0; x < data->w_map; x++)
        {
            if (data->map[y][x] == '1')
            {
                for (int j = 0; j < TILE_SIZE; j++)
                {
                    for (int i = 0; i < TILE_SIZE; i++)
                    {
                        my_mlx_put_pixel(data, x * TILE_SIZE + i, y * TILE_SIZE + j, 0x000000);
                    }
                }
            }
            else if (data->map[y][x] == '0')
            {
                for (int j = 0; j < TILE_SIZE; j++)
                {
                    for (int i = 0; i < TILE_SIZE; i++)
                    {
                        my_mlx_put_pixel(data, x * TILE_SIZE + i, y * TILE_SIZE + j, 0xFFFFFF);
                    }
                }
            }
        }
    }
}

void    render_player(t_data *data)
{
    float   x, y;
    float   end_x, end_y;

    x = data->p->player_x;
    y = data->p->player_y;
    end_x = x + cos(data->p->angle) * 30;
    end_y = y + sin(data->p->angle) * 30;
    if (data->p->player_x < 0 || data->p->player_x >= data->w_map * TILE_SIZE || data->p->player_y < 0 || data->p->player_y >= data->h_map * TILE_SIZE)
    {
        printf("Playr out of bounds! Player position: (%d, %d)\n", data->p->player_x, data->p->player_y);
        return;
    }
    my_mlx_put_pixel(data, data->p->player_x, data->p->player_y, 0xFF0000);
    dda_line(data, x, y, end_x, end_y);
}

void    render(t_data *data)
{
    render_map(data);
    render_player(data);
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

void    rotate_player(t_data *data, int direction)
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

void    move_player(t_data *data, float move_x, float move_y)
{
    int newx = roundf(data->p->player_x + move_x);
    int newy = roundf(data->p->player_y + move_y);
    int x = newx / TILE_SIZE;
    int y = newy / TILE_SIZE;
    if (data->map[y][x] != '1')
    {
        data->p->player_x = newx;
        data->p->player_y = newy;
    }
}

int key_hook(int keycode, t_data *data)
{
    float  move_x = 0;
    float  move_y = 0;
    // printf("keycode is : %d\n", keycode);
    if (keycode == 65307)
    {
        printf("ESC exiting\n");
        exit(0);
    }
    if (keycode == 97) // a
    {
        move_x = cos(data->p->angle) * PLAYER_SPEED; // -1
        move_y = sin(data->p->angle) * PLAYER_SPEED; // 0
    }
    else if (keycode == 100) // d
    {
        move_x = -cos(data->p->angle) * PLAYER_SPEED; // 1
        move_y = -sin(data->p->angle) * PLAYER_SPEED; // 0
    }
    else if (keycode == 119) // w
    {
        move_x = -sin(data->p->angle) * PLAYER_SPEED; // 0
        move_y = cos(data->p->angle) * PLAYER_SPEED; // 1
    }
    else if (keycode == 115) // s
    {
        move_x = sin(data->p->angle) * PLAYER_SPEED; // 0
        move_y = -cos(data->p->angle) * PLAYER_SPEED; // 1
    }
    else if (keycode == 65361)
        rotate_player(data, 0);
    else if (keycode == 65363)
        rotate_player(data, 1);
    mlx_clear_window(data->mlx, data->mlx_win);
    move_player(data, move_x, move_y);
    render(data);
    return (0);
}

int main()
{
    t_data  data;

    char *map[] = {
        "1111111111111111111111111",
        "1000010000000000011000001",
        "1100100000000000000010101",
        "1000000000000000000001111",
        "1000000000000000000000001",
        "1000000000000011111000001",
        "1000000000000000000000001",
        "1000000000000000000000001",
        "1111111111111111111111111",
        NULL
    };
    data.map = map;
    data.p = calloc(1, sizeof(t_paleyr));
    data.ray = calloc(1, sizeof(t_ray));
    data.p_x = 5;
    data.p_y = 5;
    data.w_map = 25;
    data.h_map = 9;
    data.p->player_x = data.p_x * TILE_SIZE + TILE_SIZE / 2;
    data.p->player_y = data.p_y * TILE_SIZE + TILE_SIZE / 2;
    data.p->angle = PI;
    data.ray->num_rays = data.w_map * TILE_SIZE;
    data.mlx = mlx_init();
    data.mlx_win = mlx_new_window(data.mlx, data.w_map * TILE_SIZE, data.h_map * TILE_SIZE, "CUB3D_WINDOW");
    
    data.img = mlx_new_image(data.mlx, data.w_map * TILE_SIZE, data.h_map * TILE_SIZE);
    
    data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_length, &data.endian);
    render(&data);
    mlx_key_hook(data.mlx_win, key_hook, &data);
    mlx_hook(data.mlx_win, 17, 0, close_window, &data);
    mlx_loop(data.mlx);
}