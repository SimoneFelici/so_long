#include "so_long.h"

void	ft_cleanup_textures(t_vars *vars)
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
	if (vars->textures.enemy_img)
		mlx_destroy_image(vars->mlx, vars->textures.enemy_img);
	if (vars->textures.explosion_img)
		mlx_destroy_image(vars->mlx, vars->textures.explosion_img);
	if (vars->textures.flint_img)
		mlx_destroy_image(vars->mlx, vars->textures.flint_img);
}
