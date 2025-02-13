#ifndef MEDPART_H
# define MEDPART_H

// # include "./miniLibX/mlx.h"
# include "../utils/Get_next_line/get_next_line.h"
# include <X11/keysym.h>
# include <stdbool.h>
# include <string.h>
# include <stdarg.h>
# include <X11/X.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include "libft.h"
# include <math.h>
# include <mlx.h>

#define BRED    "\e[1;31m"
#define BGREEN  "\e[1;32m"
#define BBLUE   "\e[1;34m"

# define WINDOW_TITLE "Cub3D"
# ifndef O_DIRECTORY
#  define O_DIRECTORY	00200000
# endif

# define WIN_WIDTH		640
# define WIN_HEIGHT		480

# define MLXKY_A 		0
# define MLXKY_S 		1
# define MLXKY_D 		2
# define MLXKY_W 		13
# define MLXKY_ESC 		53
# define MLXKY_LEFT		123
# define MLXKY_RIGHT	124

# define SUCCESS		0
# define FAILURE		1
# define ERR			2
# define BREAK			3
# define CONTINUE		4
# define MOVESPEED		0.0125
# define ROTSPEED 		0.015

# define NORTH			0
# define SOUTH			1
# define EAST			2
# define WEST			3

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}	t_img;

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

typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		move_x;
	int		move_y;
	int		rotate;
}	t_player;

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

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		**map;
	int			win_height;
	int			win_width;
	int			**textures;
	int			**texture_pixels;
	t_texdetail	texdetail;
	t_player	player;
	t_mapdetail	mapdetail;
}	t_data;

int		fill_color_textures(t_data *data, t_texdetail *textures, char *line, int j);
void	init_img(t_data *data, t_img *image, int width, int height);
int		texture_is_valid(t_data *data, t_texdetail *textures);
void	init_texture_img(t_data *data, t_img *image, char *path);
int		validate_move(t_data *data, double new_x, double new_y);
int		check_map_sides(t_mapdetail *map, char **map_tab);
int		create_map(t_data *data, char **file, int i);
int		message_val(int detail, char *str, int code);
int		map_is_valid(t_data *data, char **map_tab);
int		rotate_player(t_data *data, double rotdir);
int		message(char *detail, char *str, int code);
size_t	max_len(t_mapdetail *map, int i);
void	parse_file_data(char *path, t_data *data);
int		handle_file_error(char *arg, bool cub);
int		bring_data(t_data *data, char **map);
void	init_player(t_data *data);
void	input_handler(t_data *data);
void	init_textures(t_data *data);
void	render_frame(t_data *data);
int		move_player(t_data *data);
void	init_mlx(t_data *data);
char	*get_next_line(int fd);
void	free_tab(void **tab);
int		spaces(char c);

#endif
