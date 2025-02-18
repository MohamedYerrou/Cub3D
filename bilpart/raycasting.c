#include "../cub3d.h"

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
    if (!data->map[h][w] || data->map[h][w] == '1')
        return (0);
    return (1);
}

float   get_horz(t_data *data, float angle, float *horz_x, float *horz_y)
{
    float   xstep   = 0;
    float   ystep   = 0;
    float   dist    = 0;

    *horz_y = floor(data->p->player_y / TILE_SIZE) * TILE_SIZE;
    if (sin(angle) > 0)
        *horz_y += TILE_SIZE;
    *horz_x = data->p->player_x + (*horz_y - data->p->player_y) / tan(angle);
    ystep = TILE_SIZE;
    if (sin(angle) < 0)
        ystep *= -1;
    xstep = ystep / tan(angle);
    if (cos(angle) > 0 && xstep < 0)
        xstep *= -1;
    if (cos(angle) < 0 && xstep > 0)
        xstep *= -1;
    while (wall_hit(data, *horz_x, *horz_y, 'y'))
    {
        *horz_x += xstep;
        *horz_y += ystep;
    }
    dist = sqrt(pow(*horz_x - data->p->player_x, 2) + pow(*horz_y - data->p->player_y, 2));
    return (dist);
}

float   get_vert(t_data *data, float angle, float *vert_x, float *vert_y)
{
    float   xstep   = 0;
    float   ystep   = 0;
    float   dist    = 0;

    *vert_x = floor(data->p->player_x / TILE_SIZE) * TILE_SIZE;
    if (cos(angle) > 0)
        *vert_x += TILE_SIZE;
    *vert_y = data->p->player_y + (*vert_x - data->p->player_x) * tan(angle);
    xstep = TILE_SIZE;
    if (cos(angle) < 0)
        xstep *= -1;
    ystep = xstep * tan(angle);
    if (sin(angle) > 0 && ystep < 0)
        ystep *= -1;
    if (sin(angle) < 0 && ystep > 0)
        ystep *= -1;
    while (wall_hit(data, *vert_x, *vert_y, 'x'))
    {
        *vert_x += xstep;
        *vert_y += ystep;
    }
    dist = sqrt(pow(*vert_x - data->p->player_x, 2) + pow(*vert_y - data->p->player_y, 2));
    return (dist);
}

void    cast_ray(t_data *data, float angle)
{
    float   vert_x = 0;
    float   vert_y = 0;
    float   horz_x = 0;
    float   horz_y = 0;
    float   dist_vert = 0;
    float   dist_horz = 0;
    dist_vert = get_vert(data, angle, &vert_x, &vert_y);
    dist_horz = get_horz(data, angle, &horz_x, &horz_y);
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

t_img   *get_texture(t_data *data)
{
    if (data->ray->flag)
    {
        if (sin(data->ray->ray_angle) > 0)
            return (data->SO);
        else
            return (data->NO);
    }
    else
    {
        if (cos(data->ray->ray_angle) > 0)
            return (data->EA);
        else
            return (data->WE);
    }
    return (NULL);
}

int get_color(t_img *image, int offset_x, int offset_y)
{
    char    *offset;
    int     color;

    if (offset_x < 0 || offset_x >= image->w_texture || offset_y < 0 || offset_y >= image->h_texture)
        return (1);
    offset = image->addr + (offset_y * image->line_length + offset_x * (image->bpp / 8));
    color = *(unsigned int*)offset;
    return (color);
}

void    draw_wall(t_data *data, int *top, int *buttom, int ray)
{
    int offset_x    = 0;
    int offste_y    = 0;
    int wall_height = *buttom - *top;
    t_img   *texture = get_texture(data);
    int t_height    = texture->h_texture;

    if (data->ray->flag)
        offset_x = (data->ray->x % TILE_SIZE);
    else
        offset_x = (data->ray->y % TILE_SIZE);
    for (int y = *top; y < *buttom; y++)
    {
		int	dis = y + (wall_height / 2) - (data->H_W / 2);
        int   tex_pos = dis * t_height / wall_height;
        offste_y = tex_pos;
        int color = get_color(texture, offset_x, offste_y);
        my_mlx_put_pixel(data, ray, y, color);
    }
}

void    draw_f_c(t_data *data, int *top, int *buttom, int ray)
{
    int i;

    i = 0;
    while (i < *top)
    {
        my_mlx_put_pixel(data, ray, i, data->texdetail.hex_roof);
        i++;
    }
    i = *buttom;
    while (i < data->H_W)
    {
        my_mlx_put_pixel(data, ray, i, data->texdetail.hex_floor);
        i++;
    }
}

void    render3dwall(t_data *data, int ray)
{
    float   projct_distance = 0;
    float   project_wall_height = 0;
    int     top_pixel = 0;
    int     buttom_pixel = 0;
    int     wall_height = 0;
    float   distance    = 0;
    // float   angle = data->ray->ray_angle;

    distance = data->ray->distance * cos(data->ray->ray_angle - data->p->angle);
    projct_distance = (data->W_W / 2) / tan(FOV_ANGLE / 2);
    project_wall_height = (TILE_SIZE * projct_distance) / distance;
    wall_height = (int)project_wall_height;
    top_pixel = (data->H_W / 2) - (wall_height / 2);
    // if (top_pixel < 0)
    //     top_pixel = 0;
    buttom_pixel = (data->H_W / 2) + (wall_height / 2);
    // if (buttom_pixel > data->H_W)
    //     buttom_pixel = data->H_W;
    draw_f_c(data, &top_pixel, &buttom_pixel, ray);
    draw_wall(data, &top_pixel, &buttom_pixel, ray);
}

void    cast_all_rays(t_data *data)
{
    data->ray->ray_angle = data->p->angle - (FOV_ANGLE / 2);
    for (int ray = 0; ray < data->W_W; ray++)
    {
        data->ray->flag = 0;
        data->ray->ray_angle = normalize_angle(data->ray->ray_angle);
        cast_ray(data, data->ray->ray_angle);
        render3dwall(data, ray);
        // dda_line(data, data->ray->x, data->ray->y, 0xFF0000);
        data->ray->ray_angle += FOV_ANGLE / data->W_W;
    }
}
