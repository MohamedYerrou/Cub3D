#include "../../cub3d.h"

// void	set_pixel(t_img *image, int x, int y, int color)
// {
// 	int pixel;

// 	pixel = y * (image->size_line / 4) + x;
// 	image->addr[pixel] = color;
// }

// static void	set_frame_pixel(t_data *data, t_img *image, int x, int y)
// {
// 	if (data->texture_pixels[y][x] > 0)
// 		set_pixel(image, x, y, data->texture_pixels[y][x]);
// 	else if (y < data->h_map / 2)
// 		set_pixel(image, x, y, data->texdetail.hex_roof);
// 	else if (y < data->h_map - 1)
// 		set_pixel(image, x, y, data->texdetail.hex_floor);
// }

// void	render_frame(t_data *data)
// {
// 	t_img	image;
// 	int		x;
// 	int		y;

// 	image.img = NULL;
// 	init_img(data, &image, data->w_map, data->h_map);
// 	y = 0;
// 	while (y < data->h_map)
// 	{
// 		x = 0;
// 		while (x < data->w_map)
// 		{
// 			set_frame_pixel(data, &image, x, y);
// 			x++;
// 		}
// 		y++;
// 	}
// 	mlx_put_image_to_window(data->mlx, data->win, image.img, 0, 0);
// 	mlx_destroy_image(data->mlx, image.img);
// }
