/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfelici <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:22:28 by sfelici           #+#    #+#             */
/*   Updated: 2025/02/21 15:22:42 by sfelici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_cleanup(t_vars *vars)
{
	if (vars->textures.player_img)
		mlx_destroy_image(vars->mlx, vars->textures.player_img);
	if (vars->textures.floor_img)
		mlx_destroy_image(vars->mlx, vars->textures.floor_img);
	if (vars->textures.wall_img)
		mlx_destroy_image(vars->mlx, vars->textures.wall_img);
	if (vars->textures.collectible_img)
		mlx_destroy_image(vars->mlx, vars->textures.collectible_img);
	if (vars->textures.exit_img_closed)
		mlx_destroy_image(vars->mlx, vars->textures.exit_img_closed);
	if (vars->textures.exit_img_open)
		mlx_destroy_image(vars->mlx, vars->textures.exit_img_open);
	free_map(vars->map);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	update_position(int keycode, int *new_x, int *new_y)
{
	if (keycode == 119)
		(*new_y)--;
	else if (keycode == 115)
		(*new_y)++;
	else if (keycode == 97)
		(*new_x)--;
	else if (keycode == 100)
		(*new_x)++;
}

int	is_move_valid(t_vars *vars, int new_x, int new_y)
{
	if (vars->map[new_y][new_x] == '1')
		return (0);
	if (vars->map[new_y][new_x] == 'E' && vars->map_info.collectible_count > 0)
		return (0);
	return (1);
}

void	process_tile(t_vars *vars, int new_x, int new_y)
{
	if (vars->map[new_y][new_x] == 'C')
		vars->map_info.collectible_count--;
	if (vars->map[new_y][new_x] == 'E' && vars->map_info.collectible_count == 0)
	{
		ft_printf("You Won in %d moves!\n", ++vars->move_count);
		ft_cleanup(vars);
		exit(0);
	}
}
