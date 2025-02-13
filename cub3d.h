#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <mlx.h>

#define PI 3.14
#define TILE_SIZE 32
#define FOV_ANGLE (60 * (PI / 180))
#define PLAYER_SPEED 5
#define ROTATION_SPEED (15 * (PI / 180))

typedef struct s_player
{
    int player_x;
    int player_y;
    int rotate;
    int l_r;
    int u_d;
    float  angle;
}   t_paleyr;

typedef struct s_ray
{
    float   ray_angle;
    float   distance;
    float   h_x;
    float   h_y;
    float   v_x;
    float   v_y;
    int     flag;
    int     x;
    int     y;
    int     rayFacingUP;
    int     rayFacingDown;
    int     rayFacingRight;
    int     rayFacingLeft;
}   t_ray;

typedef struct s_data
{
    void    *mlx;
    void    *mlx_win;
    void    *img;
    char    *addr;
    int     bpp;
    int     line_length;
    int     endian;
    char    **map;
    int     p_x;
    int     p_y;
    int     w_map; // width in index
    int     h_map; // height in index
    int     W_W; // width in pixels
    int     H_W; // height in pixels
    t_paleyr    *p;
    t_ray   *ray;
}   t_data;


int main(int ac, char **av);
void    dda_line(t_data *data, float x2, float y2, int color);
void ray_facing(t_ray *ray, float angle);
float   normalize_angle(float angle);
void    cast_ray(t_data *data, float ray_angle);
void    cast_all_rays(t_data *data);
int close_window();
void    rotate_player(t_data *data, int direction);
void    move_player(t_data *data, float move_x, float move_y);
int key_hook(int keycode, t_data *data);
void    my_mlx_put_pixel(t_data *data, int x, int y, int color);
void    render_map(t_data *data);
void    render_player(t_data *data);
int    render(void *param);
void    render3dwall(t_data *data, int ray);

#endif