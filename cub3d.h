#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <mlx.h>

#define PI 3.14
#define TILE_SIZE 32
#define W_W 800
#define W_H 600
#define FOV_ANGLE (60 * (PI / 180))
#define PLAYER_SPEED 10
#define ROTATION_SPEED (10 * (PI / 180))

typedef struct s_player
{
    int player_x;
    int player_y;
    int rotate;
    int l_r;
    int u_d;
    double  angle;
}   t_paleyr;

typedef struct s_ray
{
    float   ray_angle;
    float   distance;
    int     x;
    int     y;
    int     num_rays;
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
    int     w_map;
    int     h_map;
    t_paleyr    *p;
    t_ray   *ray;
}   t_data;

#endif