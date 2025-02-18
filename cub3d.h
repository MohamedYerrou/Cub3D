#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "medpart/utils/Libft/libft.h"
#include <limits.h>
#include <stdbool.h>
#include <mlx.h>
#include <X11/X.h>
#include <errno.h>

#define PI 3.14
#define TILE_SIZE 64
#define FOV_ANGLE (60 * (PI / 180))
#define PLAYER_SPEED 10
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
	unsigned long	hex_floor;
	unsigned long	hex_roof;
	int				*floor;
	char			*south;
	char			*north;
	int				*roof;
	char			*west;
	char			*east;
	int				size;

}	t_texdetail;

typedef struct s_mapdetail
{
    int			index_end_of_map;
	int			line_count;
	char		**file;
	int			height;
	int			width;
	char		*path;
	int			fd;
} t_mapdetail;


//bilal part
typedef struct s_img
{
    int     line_length;
    int     h_texture;
    int     w_texture;
    int     endian;
    char    *addr;
    void    *img;
    int     bpp;
}   t_img;

typedef struct s_player
{
    int player_x;
    int player_y;
    float  angle;
    int rotate;
    int l_r;
    int u_d;
}   t_player;

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
    t_ray   *ray;
    t_player    *p;
	t_texdetail	texdetail;
	t_mapdetail	mapdetail;
}   t_data;


void    my_mlx_put_pixel(t_data *data, int x, int y, int color);
void    dda_line(t_data *data, float x2, float y2, int color);
void    move_player(t_data *data, float move_x, float move_y);
void    rotate_player(t_data *data, int direction);
void    cast_ray(t_data *data, float ray_angle);
int     key_hook(int keycode, t_data *data);
void    render3dwall(t_data *data, int ray);
int     key_release(int key, t_data *data);
float   normalize_angle(float angle);
void    render_player(t_data *data);
void    cast_all_rays(t_data *data);
int     close_window(t_data *data);
void    render_map(t_data *data);
int     main(int ac, char **av);
void    movement(t_data *data);
int     render(void *param);

// med part functions
int		fill_color_textures(t_data *data, t_texdetail *textures, char *line, int j);
int		texture_is_valid(t_data *data, t_texdetail *textures);;
int     handle_file_error(t_data *data, char *arg, bool cub);
int		create_map(t_data *data, char **file, int i);
int		message_val(int detail, char *str, int code);
int		map_is_valid(t_data *data, char **map_tab);
int		message(char *detail, char *str, int code);
void	parse_file_data(char *path, t_data *data);
void	exit_no_leaks(t_data *data, int status);
int		bring_data(t_data *data, char **map);
size_t	max_len(t_mapdetail map, int i);
int		check_map_sides(char **map_tab);
char	*get_next_line(int fd);
void	free_tab(void **tab);
int		spaces(char c);

#endif
