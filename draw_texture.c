#include "so_long.h"

static void draw_tile(t_vars *vars, char c, int x, int y)
{
	if (c != '1')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->textures.floor_img,
			x * GRID_SIZE, y * GRID_SIZE);
	}
	if (c == '1')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->textures.wall_img,
			x * GRID_SIZE, y * GRID_SIZE);
	}
	else if (c == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->textures.collectible_img,
			x * GRID_SIZE, y * GRID_SIZE);
	}
	else if (c == 'E')
	{
		if (vars->map_info.collectible_count > 0)
		{
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->textures.exit_img_closed,
				x * GRID_SIZE, y * GRID_SIZE);
		}
		else
		{
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->textures.exit_img_open,
				x * GRID_SIZE, y * GRID_SIZE);
		}
	}
	else if (c == 'P')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->textures.player_img,
			x * GRID_SIZE, y * GRID_SIZE);
	}
}

void draw_map(t_vars *vars)
{
	int y;
	int x;

	y = 0;
	while (y < vars->map_info.rows)
	{
		x = 0;
		while (x < vars->map_info.cols)
		{
			draw_tile(vars, vars->map[y][x], x, y);
			x++;
		}
		y++;
	}
}

int key_press(int keycode, t_vars *vars)
{
	int old_x = vars->map_info.player_x;
	int old_y = vars->map_info.player_y;

	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else if (keycode == 119 && (vars->map[vars->map_info.player_y - 1][vars->map_info.player_x] != 49))
		vars->map_info.player_y -= 1;
	else if (keycode == 115 && (vars->map[vars->map_info.player_y + 1][vars->map_info.player_x] != 49))
		vars->map_info.player_y += 1;
	else if (keycode == 97 && (vars->map[vars->map_info.player_y][vars->map_info.player_x - 1] != 49))
		vars->map_info.player_x -= 1;
	else if (keycode == 100 && (vars->map[vars->map_info.player_y][vars->map_info.player_x + 1] != 49))
		vars->map_info.player_x += 1;
	if(vars->map[vars->map_info.player_y][vars->map_info.player_x] == 67)
		vars->map_info.collectible_count -= 1;
	if(vars->map[vars->map_info.player_y][vars->map_info.player_x] == 69 && (vars->map_info.collectible_count == 0))
	{
		ft_printf("You Won! :fire:\n");
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}

	vars->map[old_y][old_x] = '0';
	vars->map[vars->map_info.player_y][vars->map_info.player_x] = 'P';
	draw_map(vars);
	return (0);
}
