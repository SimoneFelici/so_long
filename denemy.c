#include "so_long.h"

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
