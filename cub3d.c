#include "cub3d.h"

// int main(int ac, char **av)
// {
//     (void)ac;
//     (void)av;
//     t_data  data;

//     char *map[] = {
//         "1111111111111111111111111",
//         "1000010000000000011000001",
//         "1100100010101010010011101",
//         "1000000000000000000001111",
//         "1000000000000000000000001",
//         "1000000000000011111000001",
//         "1000000000000000000000001",
//         "1000000000000000000000001",
//         "1111111111111111111111111",
//         NULL
//     };
//     data.map = map;
//     data.p = calloc(1, sizeof(t_paleyr));
//     data.ray = calloc(1, sizeof(t_ray));
//     data.p_x = 5;
//     data.p_y = 5;
//     data.w_map = 25;
//     data.h_map = 9;
//     data.W_W = data.w_map * TILE_SIZE;
//     data.H_W = data.h_map * TILE_SIZE;
//     data.p->player_x = data.p_x * TILE_SIZE + TILE_SIZE / 2;
//     data.p->player_y = data.p_y * TILE_SIZE + TILE_SIZE / 2;
//     data.p->angle = 0;
//     data.mlx = mlx_init();
//     data.mlx_win = mlx_new_window(data.mlx, data.W_W, data.H_W, "CUB3D_WINDOW");

//     data.img = mlx_new_image(data.mlx, data.W_W, data.H_W);

//     data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_length, &data.endian);
//     // render(&data);
//     mlx_loop_hook(data.mlx, render, &data);
//     mlx_hook(data.mlx_win, 02, 1L<<0,  key_hook, &data);
//     mlx_hook(data.mlx_win, 03, 1L<<1,  key_release, &data);
//     mlx_hook(data.mlx_win, 17, 0, close_window, &data);
//     mlx_loop(data.mlx);
//     return (0);
// }
