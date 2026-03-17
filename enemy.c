#include "so_long.h"

void	draw_enemy(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->textures.enemy_img, x * GRID_SIZE, y * GRID_SIZE);
}

void	game_over(t_vars *vars)
{
	kill_enemy(vars, vars->map_info.player_x, vars->map_info.player_y);
	mlx_string_put(vars->mlx, vars->win, 10, 10, 0xFF0000, "GAME OVER!");
	mlx_do_sync(vars->mlx);
	sleep(2);
	ft_cleanup(vars);
	exit(0);
}

void	kill_enemy(t_vars *vars, int x, int y)
{
	int	i;

	i = 0;
	while (i < vars->enemy_count)
	{
		if (vars->enemies[i].x == x && vars->enemies[i].y == y)
		{
			vars->enemies[i] = vars->enemies[vars->enemy_count - 1];
			vars->enemy_count--;
			break ;
		}
		i++;
	}
	vars->map[y][x] = '0';
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->textures.explosion_img, x * GRID_SIZE, y * GRID_SIZE);
	mlx_do_sync(vars->mlx);
	usleep(400000);
	draw_map(vars);
}

void	show_flint(t_vars *vars)
{
	int	px;
	int	py;

	px = vars->map_info.player_x;
	py = vars->map_info.player_y;
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->textures.flint_img, (px + 1) * GRID_SIZE, py * GRID_SIZE);
	mlx_do_sync(vars->mlx);
	usleep(150000);
	draw_map(vars);
}
