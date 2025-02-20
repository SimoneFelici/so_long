#ifndef SO_LONG_H
# define SO_LONG_H

# include "libraries/minilibx-linux/mlx.h"
# include "libraries/libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define GRID_SIZE 64

typedef struct s_textures {
	void	*wall_img;
	void	*exit_img_closed;
	void	*exit_img_open;
	void	*collectible_img;
	void	*player_img;
	void	*player_img2;
	void	*floor_img;
}	t_textures;

typedef struct s_map_info {
	int	rows;
	int	cols;
	int	player_count;
	int	exit_count;
	int	collectible_count;
	int	player_x;
	int	player_y;
}	t_map_info;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	char		**map;
	t_map_info	map_info;
	t_textures	textures;
}	t_vars;

int		ft_printf(const char *format, ...);
char	**read_map(const char *file_path);
int		check_map_errors(char **map, t_map_info *info);
void	draw_map(t_vars *vars);
int		key_press(int keycode, t_vars *vars);
void	free_map(char **map);
int	check_path(char **map, t_map_info *info);

#endif
