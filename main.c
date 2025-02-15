#include "so_long.h"

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, MAP_WIDTH * GRID_SIZE, \ 
		MAP_HEIGHT * GRID_SIZE, "So Long");
	sleep(0.5);
	if (draw_texture(&vars) != 0)
		return (1);
	mlx_hook(vars.win, 2, 1L<<0, key_press, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
