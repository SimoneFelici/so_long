/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfelici <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:25:44 by sfelici           #+#    #+#             */
/*   Updated: 2025/02/21 15:26:30 by sfelici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libraries/minilibx-linux/mlx.h"
# include "libraries/libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define GRID_SIZE 64
# define MAX_ENEMIES 16

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_enemy
{
	int	x;
	int	y;
	int	dir_x;
	int	dir_y;
}	t_enemy;

typedef struct s_textures
{
	void	*wall_img;
	void	*exit_img_closed;
	void	*exit_img_open;
	void	*collectible_img;
	void	*player_img;
	void	*floor_img;
	void	*enemy_img;
	void	*explosion_img;
	void	*flint_img;
}	t_textures;

typedef struct s_map_info
{
	int	rows;
	int	cols;
	int	player_count;
	int	exit_count;
	int	collectible_count;
	int	player_x;
	int	player_y;
}	t_map_info;

typedef struct s_dfs_info
{
	char		**map;
	t_map_info	*info;
	int			*collectibles_found;
	int			*exit_found;
}	t_dfs_info;


typedef struct s_vars
{
	void		*mlx;
	void		*win;
	char		**map;
	int			move_count;
	t_map_info	map_info;
	t_textures	textures;
	t_point		player_pos;
	t_enemy		enemies[MAX_ENEMIES];
	int			enemy_count;
}	t_vars;

int		ft_printf(const char *format, ...);
char	**read_map(const char *file_path);
int		check_map_errors(char **map, t_map_info *info);
void	draw_map(t_vars *vars);
int		key_press(int keycode, t_vars *vars);
void	free_map(char **map);
int		check_path(char **map, t_map_info *info);
void	draw_floor(t_vars *vars, int x, int y);
void	draw_wall(t_vars *vars, int x, int y);
void	draw_collectible(t_vars *vars, int x, int y);
void	draw_exit(t_vars *vars, int x, int y);
void	draw_player(t_vars *vars, int x, int y);
void	ft_cleanup(t_vars *vars);
void	update_position(int keycode, int *new_x, int *new_y);
int		is_move_valid(t_vars *vars, int new_x, int new_y);
void	process_tile(t_vars *vars, int new_x, int new_y);

void	draw_enemy(t_vars *vars, int x, int y);
void	game_over(t_vars *vars);
void	kill_enemy(t_vars *vars, int x, int y);
void	show_flint(t_vars *vars);
void	init_enemies(t_vars *vars);
void	move_enemies(t_vars *vars);

#endif
