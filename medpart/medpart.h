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

# define RED		"\e[31m"
# define CYAN		"\e[36m"

# define WINDOW_TITLE "Cub3D"
# ifndef O_DIRECTORY
#  define O_DIRECTORY	00200000
# endif

# define WIN_WIDTH		700
# define WIN_HEIGHT		500

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
# define MOVESPEED		5

# define NORTH			0
# define SOUTH			1
# define EAST			2
# define WEST			3

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

typedef struct s_player
{
	char	dir;
	int		move_x;
	int		move_y;
	int		plane_x;
	int		plane_y;
	int		dir_x;
	int		dir_y;
	int		pos_x;
	int		pos_y;
	int		rotate;
	int		has_moved;
}	t_player;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		**map;
	int			win_height;
	int			win_width;
	int			**textures;
	int			**texture_pixels;
	t_mapdetail	mapdetail;
	t_player	player;
}	t_data;

int		map_is_valid(t_data *data, char **map_tab);
int		handle_sides_of_map(t_mapdetail *map, char **map_tab);
int		create_map(t_data *data, char **file, int i);
int		message(char *detail, char *str, int code);
int		bring_data(t_data *data, char **map);
size_t	find_biggest_len(t_mapdetail *map, int i);
void	parse_file_data(char *path, t_data *data);
int		handle_file_error(char *arg, bool cub);
int		spaces(char c);
void	init_mlx(t_data *data);
char	*get_next_line(int fd);
void	free_tab(void **tab);

#endif
