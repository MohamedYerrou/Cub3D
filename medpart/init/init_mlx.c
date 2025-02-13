#include "../medpart.h"

void	init_img_struct(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->pixel_bits = 0;
	img->size_line = 0;
	img->endian = 0;
}

void	init_img(t_data *data, t_img *image, int width, int height)
{
	init_img_struct(image);
	image->img = mlx_new_image(data->mlx, width, height);
	if (image->img == NULL)
	{

		message("mlx", "Error in mlx image create", 1);
		exit (1);
	}
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}

void	init_texture_img(t_data *data, t_img *image, char *path)
{
	init_img_struct(image);
	image->img = mlx_xpm_file_to_image(data->mlx, path, &data->texdetail.size,
				 &data->texdetail.size);
	if (!image->img)
	{
		message("mlx", "Error in mlx image create", 1);
		exit (1);
	}
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		message("mlx", "Error in starting mlx", 1);
		exit (1);
	}
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!data->win)
	{
		message("mlx", "Error in mlx window create", 1);
		exit (1);
	}
	return ;
}
