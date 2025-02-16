#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "utils/Libft/libft.h"
#include <limits.h>
#include <stdbool.h>
#include <mlx.h>
#include <errno.h>

#define PI 3.14
#define TILE_SIZE 64
#define FOV_ANGLE (60 * (PI / 180))
#define PLAYER_SPEED 5
#define ROTATION_SPEED (15 * (PI / 180))

// medpart

#define BRED    "\e[1;31m"
#define BGREEN  "\e[1;32m"
#define BBLUE   "\e[1;34m"

# ifndef O_DIRECTORY
#  define O_DIRECTORY	00200000
# endif

# define SUCCESS		0
# define FAILURE		1
# define ERR			2
# define BREAK			3
# define CONTINUE		4

# define NORTH			0
# define SOUTH			1
# define EAST			2
# define WEST			3

typedef struct s_texdetail
{
	unsigned long	hex_roof;
	unsigned long	hex_floor;
	int				*roof;
	int				*floor;
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				size;

}	t_texdetail;

typedef struct s_mapdetail
{
	int			fd;
	int			line_count;
	int			index_end_of_map;
	char		*path;
	int			height;
	int			width;
	char		**file;
} t_mapdetail;


//bilal part
typedef struct s_img
{
    void    *img;
    char    *addr;
    int     bpp;
    int     line_length;
    int     endian;
    int     w_texture;
    int     h_texture;
}   t_img;

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
    int     flag;
    int     x;
    int     y;
}   t_ray;

typedef struct s_data
{
    void    *mlx;
    void    *mlx_win;
    char    **map;
    int     p_x;
    int     p_y;
    int     w_map; // width in index
    int     h_map; // height in index
    int     W_W; // width in pixels
    int     H_W; // height in pixels
    t_img   *EA;
    t_img   *WE;
    t_img   *NO;
    t_img   *SO;
    t_img   *img;
    t_paleyr    *p;
    t_ray   *ray;
	t_texdetail	texdetail;
	t_mapdetail	mapdetail;
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
void    movement(t_data *data);
int key_release(int key, t_data *data);

// med part functions
int		fill_color_textures(t_data *data, t_texdetail *textures, char *line, int j);
// void	init_img(t_data *data, t_img *image, int width, int height);
int		texture_is_valid(t_data *data, t_texdetail *textures);
// void	init_texture_img(t_data *data, t_img *image, char *path);
int		check_map_sides(t_data *data, char **map_tab);
int		create_map(t_data *data, char **file, int i);
int		message_val(int detail, char *str, int code);
int		map_is_valid(t_data *data, char **map_tab);
int		message(char *detail, char *str, int code);
size_t	max_len(t_mapdetail map, int i);
void	parse_file_data(char *path, t_data *data);
int		handle_file_error(char *arg, bool cub);
int		bring_data(t_data *data, char **map);
// void	init_player(t_data *data);
// void	input_handler(t_data *data);
// void	init_textures(t_data *data);
// void	render_frame(t_data *data);
// void	init_mlx(t_data *data);
char	*get_next_line(int fd);
void	free_tab(void **tab);
int		spaces(char c);

#endif
