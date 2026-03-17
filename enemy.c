#include "so_long.h"

void	draw_enemy(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->textures.enemy_img, x * GRID_SIZE, y * GRID_SIZE);
}
