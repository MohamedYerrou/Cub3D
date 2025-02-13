#include "../medpart.h"

static int	*convert_xpm_img(t_data *data, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	init_texture_img(data, &tmp, path);
	buffer = ft_calloc(1,
			sizeof * buffer * data->texdetail.size * data->texdetail.size);
	if (!buffer)
	{
		message(NULL, "Error in malloc", 1);
		exit (1);
	}
	y = 0;
	while (y < data->texdetail.size)
	{
		x = 0;
		while (x < data->texdetail.size)
		{
			buffer[y * data->texdetail.size + x]
				= tmp.addr[y * data->texdetail.size + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, tmp.img);
	return (buffer);
}

void	init_textures(t_data *data)
{
	data->textures = ft_calloc(5, sizeof * data->textures);
	if (!data->textures)
	{
		message(NULL, "error in malloc", 1);
		exit (1);
	}
	data->textures[NORTH] = convert_xpm_img(data, data->texdetail.north);
	data->textures[SOUTH] = convert_xpm_img(data, data->texdetail.south);
	data->textures[EAST] = convert_xpm_img(data, data->texdetail.east);
	data->textures[WEST] = convert_xpm_img(data, data->texdetail.west);
}
