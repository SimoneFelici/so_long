/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfelici <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:27:18 by sfelici           #+#    #+#             */
/*   Updated: 2025/02/21 15:27:47 by sfelici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_tile(t_vars *vars, char c, int x, int y)
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

void	draw_map(t_vars *vars)
{
	int	y;
	int	x;

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

int	key_press(int keycode, t_vars *vars)
{
	int	old_x = vars->map_info.player_x;
	int	old_y = vars->map_info.player_y;
	int	new_x = old_x;
	int	new_y = old_y;

	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else if (keycode == 119)
		new_y--;
	else if (keycode == 115)
		new_y++;
	else if (keycode == 97)
		new_x--;
	else if (keycode == 100)
		new_x++;
	if (vars->map[new_y][new_x] == '1')
		return (0);
	if (vars->map[new_y][new_x] == 'E' && vars->map_info.collectible_count > 0)
		return (0);
	if (vars->map[new_y][new_x] == 'C')
		vars->map_info.collectible_count--;
	if (vars->map[new_y][new_x] == 'E' && vars->map_info.collectible_count == 0)
	{
		ft_printf("You Won in %d moves!\n", vars->move_count++);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	vars->map[old_y][old_x] = '0';
	vars->map[new_y][new_x] = 'P';
	vars->map_info.player_x = new_x;
	vars->map_info.player_y = new_y;
	ft_printf("Number of moves: %d\n", vars->move_count);
	vars->move_count++;
	draw_map(vars);
	return (0);
}
