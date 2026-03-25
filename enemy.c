#include "so_long.h"

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

static void	show_flint(t_vars *vars)
{
	int	px;
	int	py;

	px = vars->map_info.player_x;
	py = vars->map_info.player_y;
	draw_flint(vars, (px + 1), py);
	mlx_do_sync(vars->mlx);
	usleep(150000);
	draw_map(vars);
}

void	handle_kill(t_vars *vars)
{
	int	px;
	int	py;

	show_flint(vars);
	px = vars->map_info.player_x;
	py = vars->map_info.player_y;
	if (vars->map[py - 1][px] == 'V')
		kill_enemy(vars, px, py - 1);
	else if (vars->map[py + 1][px] == 'V')
		kill_enemy(vars, px, py + 1);
	else if (vars->map[py][px - 1] == 'V')
		kill_enemy(vars, px - 1, py);
	else if (vars->map[py][px + 1] == 'V')
		kill_enemy(vars, px + 1, py);
}

void	init_enemies(t_vars *vars)
{
	int	i;
	int	j;
	int	n;

	n = 0;
	i = 0;
	while (i < vars->map_info.rows && n < MAX_ENEMIES)
	{
		j = 0;
		while (j < vars->map_info.cols && n < MAX_ENEMIES)
		{
			if (vars->map[i][j] == 'V')
			{
				vars->enemies[n].x = j;
				vars->enemies[n].y = i;
				vars->enemies[n].dir_x = 1;
				vars->enemies[n].dir_y = 0;
				n++;
			}
			j++;
		}
		i++;
	}
	vars->enemy_count = n;
}

void	move_enemies(t_vars *vars)
{
	int		i;
	int		nx;
	int		ny;
	char	next;

	i = 0;
	while (i < vars->enemy_count)
	{
		nx = vars->enemies[i].x + vars->enemies[i].dir_x;
		ny = vars->enemies[i].y + vars->enemies[i].dir_y;
		next = vars->map[ny][nx];
		if (next == '1' || next == 'C' || next == 'E' || next == 'P')
		{
			vars->enemies[i].dir_x *= -1;
			vars->enemies[i].dir_y *= -1;
		}
		else
		{
			vars->map[vars->enemies[i].y][vars->enemies[i].x] = '0';
			vars->enemies[i].x = nx;
			vars->enemies[i].y = ny;
			vars->map[ny][nx] = 'V';
		}
		i++;
	}
}
