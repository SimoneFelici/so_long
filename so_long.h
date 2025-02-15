#ifndef SO_LONG_H
# define SO_LONG_H

# include "libraries/minilibx-linux/mlx.h"
# include "libraries/libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define GRID_SIZE 32
# define MAP_WIDTH 25
# define MAP_HEIGHT 19

typedef struct	s_player {
	int	x;
	int	y;
}	t_player;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	void		*background_img;
	void		*player_img;
	t_player	player;
}	t_vars;

int	ft_printf(const char *format, ...);
int	key_press(int keycode, t_vars *vars);
int	draw_texture(t_vars *vars);

#endif
