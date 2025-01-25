#include "../medpart.h"

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		message("mlx", "Could not start mlx", 1);
		exit (1);
	}
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!data->win)
	{
		message("mlx", "Could not create mlx window", 1);
		exit (1);
	}
	return ;
}
