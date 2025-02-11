#include "cub3d.h"

int close_window()
{
    printf("closed window\n");
    exit(0);
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
        move_x = -cos(data->p->angle + PI / 2) * PLAYER_SPEED; // -1
        move_y = -sin(data->p->angle + PI / 2) * PLAYER_SPEED; // 0
    }
    else if (keycode == 100) // d
    {
        move_x = cos(data->p->angle + PI / 2) * PLAYER_SPEED; // 1
        move_y = sin(data->p->angle + PI / 2) * PLAYER_SPEED; // 0
    }
    else if (keycode == 119) // w
    {
        move_x = cos(data->p->angle) * PLAYER_SPEED; // 0
        move_y = sin(data->p->angle) * PLAYER_SPEED; // 1
    }
    else if (keycode == 115) // s
    {
        move_x = -cos(data->p->angle) * PLAYER_SPEED; // 0
        move_y = -sin(data->p->angle) * PLAYER_SPEED; // 1
    }
    else if (keycode == 65361)
        rotate_player(data, 0);
    else if (keycode == 65363)
        rotate_player(data, 1);
    move_player(data, move_x, move_y);
    render(data);
    return (0);
}