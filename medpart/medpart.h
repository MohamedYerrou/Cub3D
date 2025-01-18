#ifndef MEDPART_H
# define MEDPART_H

# include "../utils/Libft/libft.h"
// # include "./miniLibX/mlx.h"
// # include "get_next_line.h"
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>

# define RED		"\e[31m"

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

# define NORTH			0
# define SOUTH			1
# define EAST			2
# define WEST			3

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
}	t_data;

int		err_msg(char *detail, char *str, int code);
int		check_file(char *arg, bool cub);
void	init_data(t_data *data);

#endif
