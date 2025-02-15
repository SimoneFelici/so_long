#include "so_long.h"

int	key_press(int keycode, t_vars *vars)
{
	int	old_x = vars->player.x;
	int	old_y = vars->player.y;

	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else if (keycode == 119)
		vars->player.y -= GRID_SIZE;
	else if (keycode == 115)
		vars->player.y += GRID_SIZE;
	else if (keycode == 97)
		vars->player.x -= GRID_SIZE;
	else if (keycode == 100)
		vars->player.x += GRID_SIZE;
	else
		return (0);
	mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->background_img, old_x, old_y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->player_img, \
		vars->player.x, vars->player.y);
	return (0);
}
