/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfelici <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:06:57 by sfelici           #+#    #+#             */
/*   Updated: 2025/02/21 15:13:53 by sfelici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_vars *vars)
{
	ft_cleanup(vars);
	exit(0);
	return (0);
}

int	init_textures(t_vars *vars)
{
	int	w;
	int	h;

	vars->textures.wall_img = mlx_xpm_file_to_image(vars->mlx, \
		"textures/cobblestone.xpm", &w, &h);
	vars->textures.floor_img = mlx_xpm_file_to_image(vars->mlx, \
		"textures/grass.xpm", &w, &h);
	vars->textures.collectible_img = mlx_xpm_file_to_image(vars->mlx, \
		"textures/ender_eye.xpm", &w, &h);
	vars->textures.exit_img_closed = mlx_xpm_file_to_image(vars->mlx, \
		"textures/end_portal_closed.xpm", &w, &h);
	vars->textures.exit_img_open = mlx_xpm_file_to_image(vars->mlx, \
		"textures/end_portal_open.xpm", &w, &h);
	vars->textures.player_img = mlx_xpm_file_to_image(vars->mlx, \
		"textures/player.xpm", &w, &h);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
	{
		return (1);
	}
	vars.map = read_map(argv[1]);
	if (!vars.map)
		return (1);
	if (check_map_errors(vars.map, &vars.map_info))
	{
		free_map(vars.map);
		return (1);
	}
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, \
		vars.map_info.cols * GRID_SIZE, \
		vars.map_info.rows * GRID_SIZE, \
		"So Long");
	init_textures(&vars);
	draw_map(&vars);
	mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
	mlx_hook(vars.win, 17, 0, close_game, &vars);
	mlx_loop(vars.mlx);
	free_map(vars.map);
}
