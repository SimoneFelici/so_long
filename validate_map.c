#include "so_long.h"

/*
 * Controlla se la mappa è rettangolare (tutte le righe stessa lunghezza).
 */
static int check_rectangular(char **map, t_map_info *info)
{
	int i;

	info->cols = ft_strlen(map[0]);
	info->rows = 0;
	i = 0;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != info->cols)
			return (1);
		i++;
	}
	info->rows = i;
	return (0);
}

static int check_walls(char **map, t_map_info *info)
{
	int i;

	i = 0;
	while (i < info->cols)
	{
		if (map[0][i] != '1' || map[info->rows - 1][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < info->rows)
	{
		if (map[i][0] != '1' || map[i][info->cols - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

static int check_chars_and_count(char **map, t_map_info *info)
{
	int i;
	int j;

	info->player_count = 0;
	info->exit_count = 0;
	info->collectible_count = 0;
	i = 0;
	while (i < info->rows)
	{
		j = 0;
		while (j < info->cols)
		{
			if (map[i][j] == 'P')
			{
				info->player_count++;
				if (info->player_count == 1)
				{
					info->player_x = j;
					info->player_y = i;
				}
			}
			else if (map[i][j] == 'E')
				info->exit_count++;
			else if (map[i][j] == 'C')
				info->collectible_count++;
			else if (map[i][j] != '0' && map[i][j] != '1')
				return (1);
			j++;
		}
		i++;
	}
	if (info->player_count != 1 || info->exit_count != 1 || info->collectible_count < 1)
		return (1);
	return (0);
}

int check_map_errors(char **map, t_map_info *info)
{
	if (check_rectangular(map, info))
	{
		ft_printf("Error\nMappa non rettangolare\n");
		return (1);
	}
	if (check_walls(map, info))
	{
		ft_printf("Error\nMappa non è chiusa dai muri (bordo)\n");
		return (1);
	}
	if (check_chars_and_count(map, info))
	{
		ft_printf("Error\nCaratteri invalidi o numero errato di P/E/C\n");
		return (1);
	}
	return (0);
}
