#include "medpart/medpart.h"

int main(int argc, char **argv)
{
	//create struct
	t_data	data;
	// if's!! check errors !! return -1
	(void)argv;
	if (argc != 2)
		return (err_msg("Path" ,"please add a .cub file", 1));
	init_data(&data);
	if (check_file(argv[1], true) == FAILURE)
		exit (1);
	// if (ac == 2)
	// {
	// 	//launch game
	// 	//something wrong exit everything
	// 	//mlx_hook
	// }
	printf("░█▀▀░█░█░█▀▄░▀▀█░█▀▄░\n");
	printf("░█░░░█░█░█▀▄░░▀▄░█░█░\n");
	printf("░▀▀▀░▀▀▀░▀▀░░▀▀░░▀▀░░\n");
	// else // exit everything
	return 0;
}
