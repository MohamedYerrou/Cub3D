/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 08:58:05 by myerrou           #+#    #+#             */
/*   Updated: 2025/02/20 01:37:44 by bjniane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "parsing_med/utils/Libft/libft.h"
# include <X11/X.h>
# include <errno.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define PI 3.14
# define TILE_SIZE 64
# define FOV_ANGLE 60
# define PLAYER_SPEED 10
# define ROTATION_SPEED 0.05

# define BRED "\e[1;31m"
# define BGREEN "\e[1;32m"
# define BBLUE "\e[1;34m"

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

# define SUCCESS 0
# define FAILURE 1
# define ERR 2
# define BREAK 3
# define CONTINUE 4

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

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

}					t_texdetail;

typedef struct s_mapdet
{
	int				index_end_of_map;
	int				line_count;
	char			**file;
	int				height;
	int				width;
	char			*path;
	int				fd;
}					t_mapdet;

// bilal part
typedef struct s_img
{
	int				line_length;
	int				h_texture;
	int				w_texture;
	int				endian;
	char			*addr;
	void			*img;
	int				bpp;
}					t_img;

typedef struct s_player
{
	int				player_x;
	int				player_y;
	float			angle;
	float			fov;
	int				rotate;
	int				l_r;
	int				u_d;
}					t_player;

typedef struct s_ray
{
	float			ray_angle;
	float			distance;
	int				flag;
	int				x;
	int				y;
}					t_ray;

typedef struct s_var
{
	int				offset_x;
	int				offset_y;
	int				wall_height;
	t_img			*texture;
	int				t_height;
	int				y;
	int				tex_pos;
	int				color;

	float			projct_distance;
	float			project_wall_height;
	int				top_pixel;
	int				buttom_pixel;
	float			distance;

	float			vert_x;
	float			vert_y;
	float			horz_x;
	float			horz_y;
	float			dist_vert;
	float			dist_horz;
}					t_var;

typedef struct s_data
{
	void			*mlx;
	void			*mlx_win;
	char			**map;
	int				p_x;
	int				p_y;
	int				w_map;
	int				h_map;
	int				w_w;
	int				h_w;
	t_img			*ea;
	t_img			*we;
	t_img			*no;
	t_img			*so;
	t_img			*img;
	t_ray			*ray;
	t_player		*p;
	t_texdetail		texdetail;
	t_mapdet		mapdet;
}					t_data;

void				my_mlx_put_pixel(t_data *data, int x, int y, int color);
void				move_player(t_data *data, float move_x, float move_y);
void				rotate_player(t_data *data, int direction);
void				cast_ray(t_data *data, float ray_angle);
int					key_hook(int keycode, t_data *data);
int					key_release(int key, t_data *data);
float				normalize_angle(float angle);
void				cast_all_rays(t_data *data);
int					close_window(t_data *data);
int					main(int ac, char **av);
void				movement(t_data *data);
int					render(void *param);
t_img				*get_texture(t_data *data);
int					get_color(t_img *image, int offset_x, int offset_y);
void				draw_wall(t_data *data, int *top, int *buttom, int ray);
void				draw_f_c(t_data *data, int *top, int *buttom, int ray);
void				render3dwall(t_data *data, int ray);
t_img				*create_new_image(t_data *data, char *path);
void				handle_movement(t_data *data, float *move_x, float *move_y);
void				handle_rotation(t_data *data);

// med part functions
int					fill_color_textures(t_data *data, t_texdetail *textures,
						char *line, int j);
int					texture_is_valid(t_data *data, t_texdetail *textures);
;
int					handle_file_error(char *arg, bool cub);
int					create_map(t_data *data, char **file, int i);
int					message_val(int detail, char *str, int code);
int					map_is_valid(t_data *data, char **map_tab);
int					message(char *detail, char *str, int code);
void				parse_file_data(char *path, t_data *data);
void				exit_no_leaks(t_data *data, int status);
int					bring_data(t_data *data, char **map);
size_t				max_len(t_mapdet map, int i);
int					check_map_sides(char **map_tab);
char				*get_next_line(int fd);
void				free_tab(void **tab);
int					spaces(char c);

#endif
