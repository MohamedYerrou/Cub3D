#include "cub3d.h"

float   normalize_angle(float angle)
{
    while (angle < 2 * PI && angle > 2 * PI)
    {
        if (angle > 2 * PI)
            angle -= 2 * PI;
        if (angle < 2 * PI)
            angle += 2 * PI;
    }
    return (angle);
}

int wall_hit(t_data *data, float x, float y, char c)
{
    int w;
    int h;

    if (x < 0 || y < 0 || x >= data->W_W || y >= data->H_W)
        return (0);
    w = floor(x / TILE_SIZE);
    h = floor(y / TILE_SIZE);
    if (c == 'x' && cos(data->ray->ray_angle) < 0)
        w--;
    if (c == 'y' && sin(data->ray->ray_angle) < 0)
        h--;
    if (data->map[h][w] == '1')
        return (0);
    return (1);
}

float   get_horz(t_data *data, float angle)
{
    float   horz_x  = 0;
    float   horz_y  = 0;
    float   xstep   = 0;
    float   ystep   = 0;
    float   dist_horz = 0;

    horz_y = floor(data->p->player_x / TILE_SIZE) * TILE_SIZE;
    if (sin(angle) > 0)
        horz_y += TILE_SIZE;
    horz_x = data->p->player_x + (horz_y - data->p->player_y) / tan(angle);
    ystep = TILE_SIZE;
    if (sin(angle) < 0)
        ystep *= -1;
    xstep = ystep / tan(angle);
    if (cos(angle) > 0 && xstep < 0)
        xstep *= -1;
    if (cos(angle) < 0 && xstep > 0)
        xstep *= -1;
    while (wall_hit(data, horz_x, horz_y, 'y'))
    {
        horz_x += xstep;
        horz_y += ystep;
    }
    dist_horz = sqrt(pow(horz_x - data->p->player_x, 2) + pow(horz_y - data->p->player_y, 2));
    return (dist_horz);
}

float   get_vert(t_data *data, float angle)
{
    float   vert_x  = 0;
    float   vert_y  = 0;
    float   xstep   = 0;
    float   ystep   = 0;
    float   dist_vert = 0;

    vert_x = floor(data->p->player_x / TILE_SIZE) * TILE_SIZE;
    if (cos(angle) > 0)
        vert_x += TILE_SIZE;
    vert_y = data->p->player_y + (vert_x - data->p->player_x) * tan(angle);
    xstep = TILE_SIZE;
    if (cos(angle) < 0)
        xstep *= -1;
    ystep = xstep * tan(angle);
    if (sin(angle) > 0 && ystep < 0)
        ystep *= -1;
    if (sin(angle) < 0 && ystep > 0)
        ystep *= -1;
    while (wall_hit(data, vert_x, vert_y, 'x'))
    {
        vert_x += xstep;
        vert_y += ystep;
    }
    dist_vert = sqrt(pow(vert_x - data->p->player_x, 2) + pow(vert_y - data->p->player_y, 2));
    return (dist_vert);
}

void    cast_ray(t_data *data, float angle)
{
    float   vert_x = 0;
    float   vert_y = 0;
    float   horz_x = 0;
    float   horz_y = 0;
    float   xstep = 0;
    float   ystep = 0;
    float   dist_vert = 0;
    float   dist_horz = 0;

    // VERTICAL INTERSECTIONS
    vert_x = floor(data->p->player_x / TILE_SIZE) * TILE_SIZE;
    if (cos(angle) > 0)
        vert_x += TILE_SIZE;
    vert_y = data->p->player_y + (vert_x - data->p->player_x) * tan(angle);
    xstep = TILE_SIZE;
    if (cos(angle) < 0)
        xstep *= -1;
    ystep = xstep * tan(angle);
    if (sin(angle) > 0 && ystep < 0)
        ystep *= -1;
    if (sin(angle) < 0 && ystep > 0)
        ystep *= -1;
    while (wall_hit(data, vert_x, vert_y, 'x'))
    {
        vert_x += xstep;
        vert_y += ystep;
    }
    dist_vert = sqrt(pow(vert_x - data->p->player_x, 2) + pow(vert_y - data->p->player_y, 2));

    //HORIZONTAL INTERSECTIONS
    horz_y = floor(data->p->player_y / TILE_SIZE) * TILE_SIZE;
    if (sin(angle) > 0)
        horz_y += TILE_SIZE;
    horz_x = data->p->player_x + (horz_y - data->p->player_y) / tan(angle);
    ystep = TILE_SIZE;
    if (sin(angle) < 0)
        ystep *= -1;
    xstep = ystep / tan(angle);
    if (cos(angle) > 0 && xstep < 0)
        xstep *= -1;
    if (cos(angle) < 0 && xstep > 0)
        xstep *= -1;
    while (wall_hit(data, horz_x, horz_y, 'y'))
    {
        horz_x += xstep;
        horz_y += ystep;
    }
    dist_horz = sqrt(pow(horz_x - data->p->player_x, 2) + pow(horz_y - data->p->player_y, 2));

    //CALCULATION OF THE CLOSEST DISTANCE
    if (dist_horz < dist_vert)
    {
        data->ray->flag = 1;
        data->ray->x = horz_x;
        data->ray->y = horz_y;
        data->ray->distance = dist_horz;
    }
    else
    {
        data->ray->x = vert_x;
        data->ray->y = vert_y;
        data->ray->distance = dist_vert;
    }
}

void    render3dwall(t_data *data, int ray)
{
    float   projct_distance = 0;
    float   project_wall_height = 0;
    int     top_pixel = 0;
    int     buttom_pixel = 0;
    int     wall_height = 0;
    // float   angle = data->ray->ray_angle;

    projct_distance = (data->W_W / 2) / tan(FOV_ANGLE / 2);
    project_wall_height = (TILE_SIZE * projct_distance) / data->ray->distance;
    wall_height = (int)project_wall_height;
    top_pixel = (data->H_W / 2) - (wall_height / 2);
    if (top_pixel < 0)
        top_pixel = 0;
    buttom_pixel = (data->H_W / 2) + (wall_height / 2);
    if (buttom_pixel > data->H_W)
        buttom_pixel = data->H_W;
    for (int i = 0; i < top_pixel; i++)
        my_mlx_put_pixel(data, ray, i, 0x4682B4);
    for (int y = top_pixel; y < buttom_pixel; y++)
    {
        if (data->ray->flag)
        {
            my_mlx_put_pixel(data, ray, y, 0xC0C0C0);
            // if (cos(angle) > 0)
            //     my_mlx_put_pixel(data, ray, y, 0x00ffff);
            // else
            //     my_mlx_put_pixel(data, ray, y, 0x0000FF);
        }
        else
        {
            my_mlx_put_pixel(data, ray, y, 0x808080);
            // if (sin (angle) > 0)
            //     my_mlx_put_pixel(data, ray, y, 0xC0C0C0);
            // else
            //     my_mlx_put_pixel(data, ray, y, 0x808080);
        }
        for (int j = buttom_pixel; j < data->H_W; j++)
            my_mlx_put_pixel(data, ray, j, 0x8B4513);
    }
}

void    cast_all_rays(t_data *data)
{
    // float   dist_vert = 0;
    // float   dist_horz = 0;

    data->ray->ray_angle = data->p->angle - (FOV_ANGLE / 2);
    for (int ray = 0; ray < data->W_W; ray++)
    {
        data->ray->flag = 0;
        data->ray->ray_angle = normalize_angle(data->ray->ray_angle);
        cast_ray(data, data->ray->ray_angle);
        // dist_horz = get_horz(data, data->ray->ray_angle);
        // dist_vert = get_vert(data, data->ray->ray_angle);
        // if (dist_horz < dist_vert)
        // {
        //     data->ray->flag = 1;
        //     data->ray->distance = dist_horz;
        // }
        // else
        //     data->ray->distance = dist_vert;
        render3dwall(data, ray);
        // dda_line(data, data->ray->x, data->ray->y, 0xFF0000);
        data->ray->ray_angle += FOV_ANGLE / data->W_W;
    }
    // exit(1);
}