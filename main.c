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
		"textures/diamond.xpm", &w, &h);
	if (!vars->textures.collectible_img)
		return (ft_printf("Error\nImpossibile caricare collectable.xpm\n"), 1);

	vars->textures.exit_img_closed = mlx_xpm_file_to_image(vars->mlx,
		"textures/portal-closed.xpm", &w, &h);
	if (!vars->textures.exit_img_closed)
		return (ft_printf("Error\nImpossibile caricare exit.xpm\n"), 1);

	vars->textures.exit_img_open = mlx_xpm_file_to_image(vars->mlx,
		"textures/portal-open.xpm", &w, &h);
	if (!vars->textures.exit_img_open)
		return (ft_printf("Error\nImpossibile caricare exit.xpm\n"), 1);


	vars->textures.player_img = mlx_xpm_file_to_image(vars->mlx,
		"textures/player.xpm", &w, &h);
	if (!vars->textures.player_img)
		return (ft_printf("Error\nImpossibile caricare player.xpm\n"), 1);

	return (0);
}

int main(int argc, char **argv)
{
	t_vars vars;

	if (argc != 2)
	{
		ft_printf("Error\nUso: ./so_long map.ber\n");
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
	if (!vars.mlx)
	{
		ft_printf("Error\nmlx_init fallita\n");
		free_map(vars.map);
		return (1);
	}
	vars.win = mlx_new_window(vars.mlx,
		vars.map_info.cols * GRID_SIZE,
		vars.map_info.rows * GRID_SIZE,
		"So Long");
	if (!vars.win)
	{
		ft_printf("Error\nmlx_new_window fallita\n");
		free_map(vars.map);
		return (1);
	}
	if (init_textures(&vars) != 0)
	{
		free_map(vars.map);
		mlx_destroy_window(vars.mlx, vars.win);
		return (1);
	}
	sleep(1);
	draw_map(&vars);
	mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
	mlx_loop(vars.mlx);
	free_map(vars.map);
	return (0);
}
