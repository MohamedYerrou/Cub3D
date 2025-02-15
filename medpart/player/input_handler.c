#include "../../cub3d.h"

// static int	press_handler(int key, t_data *data)
// {
// 	if (key == XK_Escape)
// 		exit(0);
// 	if (key == XK_Left)
// 		data->player.rotate -= 1;
// 	if (key == XK_Right)
// 		data->player.rotate += 1;
// 	if (key == XK_w)
// 		data->player.move_y = 1;
// 	if (key == XK_a)
// 		data->player.move_x = -1;
// 	if (key == XK_s)
// 		data->player.move_y = -1;
// 	if (key == XK_d)
// 		data->player.move_x = 1;
// 	return (0);
// }

// static int	release_handler(int key, t_data *data)
// {
// 	if (key == XK_Escape)
// 		exit(0);
// 	if (key == XK_w && data->player.move_y == 1)
// 		data->player.move_y = 0;
// 	if (key == XK_s && data->player.move_y == -1)
// 		data->player.move_y = 0;
// 	if (key == XK_a && data->player.move_x == -1)
// 		data->player.move_x += 1;
// 	if (key == XK_d && data->player.move_x == 1)
// 		data->player.move_x -= 1;
// 	if (key == XK_Left && data->player.rotate <= 1)
// 		data->player.rotate = 0;
// 	if (key == XK_Right && data->player.rotate >= -1)
// 		data->player.rotate = 0;
// 	return (0);
// }

// void	input_handler(t_data *data)
// {
// 	mlx_hook(data->win, KeyPress, KeyPressMask, press_handler, data);
// 	mlx_hook(data->win, KeyRelease, KeyReleaseMask, release_handler, data);
// }
