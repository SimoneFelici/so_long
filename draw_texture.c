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
	if (c == '1')
		draw_wall(vars, x, y);
	else if (c == 'C')
		draw_collectible(vars, x, y);
	else if (c == 'E')
		draw_exit(vars, x, y);
	else if (c == 'P')
		draw_player(vars, x, y);
	else
		draw_floor(vars, x, y);
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
	t_point	old_pos;
	t_point	new_pos;

	old_pos.x = vars->map_info.player_x;
	old_pos.y = vars->map_info.player_y;
	new_pos = old_pos;
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	update_position(keycode, &new_pos.x, &new_pos.y);
	if (!is_move_valid(vars, new_pos.x, new_pos.y))
		return (0);
	process_tile(vars, new_pos.x, new_pos.y);
	vars->map[old_pos.y][old_pos.x] = '0';
	vars->map[new_pos.y][new_pos.x] = 'P';
	vars->map_info.player_x = new_pos.x;
	vars->map_info.player_y = new_pos.y;
	ft_printf("Number of moves: %d\n", vars->move_count);
	vars->move_count++;
	draw_map(vars);
	return (0);
}
