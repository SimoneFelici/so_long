/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pencils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfelici <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:50:44 by sfelici           #+#    #+#             */
/*   Updated: 2025/02/23 18:50:45 by sfelici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_floor(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->textures.floor_img, x * GRID_SIZE, y * GRID_SIZE);
}

void	draw_wall(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->textures.wall_img, x * GRID_SIZE, y * GRID_SIZE);
}

void	draw_collectible(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->textures.collectible_img, x * GRID_SIZE, y * GRID_SIZE);
}

void	draw_exit(t_vars *vars, int x, int y)
{
	if (vars->map_info.collectible_count > 0)
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->textures.exit_img_closed, x * GRID_SIZE, y * GRID_SIZE);
	else
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->textures.exit_img_open, x * GRID_SIZE, y * GRID_SIZE);
}

void	draw_player(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->textures.player_img, x * GRID_SIZE, y * GRID_SIZE);
}
