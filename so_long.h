#ifndef SO_LONG_H
# define SO_LONG_H

# include "libraries/minilibx-linux/mlx.h"
# include "libraries/libft/libft.h"
# include "fcntl.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*img;
}				t_vars;

int		ft_printf(const char *format, ...);

#endif
