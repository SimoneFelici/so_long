#include "so_long.h"

int init_textures(t_vars *vars)
{
	int w;
	int h;

	vars->textures.wall_img = mlx_xpm_file_to_image(vars->mlx,
		"textures/cobblestone.xpm", &w, &h);
	if (!vars->textures.wall_img)
		return (ft_printf("Error\nImpossibile caricare wall.xpm\n"), 1);

	vars->textures.floor_img = mlx_xpm_file_to_image(vars->mlx,
		"textures/grass.xpm", &w, &h);
	if (!vars->textures.floor_img)
		return (ft_printf("Error\nImpossibile caricare background.xpm\n"), 1);

	vars->textures.collectible_img = mlx_xpm_file_to_image(vars->mlx,
		"textures/ender_eye.xpm", &w, &h);
	if (!vars->textures.collectible_img)
		return (ft_printf("Error\nImpossibile caricare collectable.xpm\n"), 1);

	vars->textures.exit_img_closed = mlx_xpm_file_to_image(vars->mlx,
		"textures/end_portal_closed.xpm", &w, &h);
	if (!vars->textures.exit_img_closed)
		return (ft_printf("Error\nImpossibile caricare exit.xpm\n"), 1);

	vars->textures.exit_img_open = mlx_xpm_file_to_image(vars->mlx,
		"textures/end_portal_open.xpm", &w, &h);
	if (!vars->textures.exit_img_open)
		return (ft_printf("Error\nImpossibile caricare exit.xpm\n"), 1);


	vars->textures.player_img = mlx_xpm_file_to_image(vars->mlx,
		"textures/player.xpm", &w, &h);
	if (!vars->textures.player_img)
		return (ft_printf("Error\nImpossibile caricare player.xpm\n"), 1);

	return (0);
}

int	main(int argc, char **argv)
{
	t_vars vars;

	if (argc != 2)
	{
		return (1);
	}
	
	vars.map = read_map(argv[1]);
	if (!vars.map)
		return (1);
	printf("Map before error checking (%d rows):\n", 5);
	for (int i = 0; i < 5; i++)
	{
		printf("Row %d: %s\n", i, vars.map[i]);
	}

	if (check_map_errors(vars.map, &vars.map_info))
	{
		free_map(vars.map);
		return (1);
	}

	printf("Map after error checking (%d rows):\n", vars.map_info.rows);
	for (int i = 0; i < vars.map_info.rows; i++)
	{
		printf("Row %d: %s\n", i, vars.map[i]);
	}

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx,
		vars.map_info.cols * GRID_SIZE,
		vars.map_info.rows * GRID_SIZE,
		"So Long");
	init_textures(&vars);
	sleep(1);
	draw_map(&vars);
	mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
	mlx_loop(vars.mlx);
	free_map(vars.map);
	return (0);
}
