
#include "so_long.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_press(int keycode, t_vars *vars)
{
	ft_printf("Keycode: %d\n", keycode);

	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
	}
	else
	{
		ft_printf("Key pressed: %d\n", keycode);
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, key_press, &vars);
	mlx_loop(vars.mlx);
}
