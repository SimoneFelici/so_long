#include "so_long.h"

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

int	main()
{
	t_vars	vars;
	int		img_width;
	int		img_height;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 600, "Hello world!");

	vars.img = mlx_xpm_file_to_image(vars.mlx, "./textures/background.xpm", &img_width, &img_height);
	if (vars.img == NULL)
	{
		ft_printf("Errore nel caricamento dell'immagine.\n");
		return (1);
	}
	ft_printf("Immagine caricata: larghezza = %d, altezza = %d\n", img_width, img_height);

	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);

//	mlx_hook(vars.win, 2, 1L<<0, key_press, &vars);
	mlx_loop(vars.mlx);
}
