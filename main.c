#include "medpart/medpart.h"

int main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (message("Path" ,"please add a .cub file", FAILURE));
	data = (t_data){0};
	if (handle_file_error(argv[1], true) == FAILURE)
		return (FAILURE);
	parse_file_data(argv[1], &data);
	// printf("map_tab[0] ==> %s\n", data.mapdetail.file[0]);
	if (bring_data(&data, data.mapdetail.file) == FAILURE)
		return (FAILURE);
	if (map_is_valid(&data, data.mapdetail.file) == FAILURE)
		return (FAILURE);
	init_mlx(&data);
	return (SUCCESS);
}
