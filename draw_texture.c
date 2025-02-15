#include "so_long.h"

int draw_background(t_vars *vars)
{
    int bg_width;
    int bg_height;
    int x;
    int y;

    vars->background_img = mlx_xpm_file_to_image(vars->mlx, 
        "./textures/background.xpm", &bg_width, &bg_height);
    if (!vars->background_img)
        return (ft_printf("Errore background\n"), 1);

    y = 0;
    while (y < MAP_HEIGHT * GRID_SIZE)
    {
        x = 0;
        while (x < MAP_WIDTH * GRID_SIZE)
        {
            mlx_put_image_to_window(vars->mlx, vars->win, 
                vars->background_img, x, y);
            x += bg_width;
        }
        y += bg_height;
    }
    return (0);
}

int draw_player(t_vars *vars)
{
    int pl_width;
    int pl_height;

    vars->player_img = mlx_xpm_file_to_image(vars->mlx, 
        "./textures/player.xpm", &pl_width, &pl_height);
    if (!vars->player_img)
        return (ft_printf("Errore player\n"), 1);

    /* Posiziona il player al centro della mappa (griglia) */
    vars->player.x = (MAP_WIDTH / 2) * GRID_SIZE;
    vars->player.y = (MAP_HEIGHT / 2) * GRID_SIZE;
    mlx_put_image_to_window(vars->mlx, vars->win, vars->player_img, 
        vars->player.x, vars->player.y);
    return (0);
}

int draw_texture(t_vars *vars)
{
    if (draw_background(vars) != 0)
        return (1);
    if (draw_player(vars) != 0)
        return (1);
    return (0);
}
