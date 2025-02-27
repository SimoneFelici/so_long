/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfelici <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:25:44 by sfelici           #+#    #+#             */
/*   Updated: 2025/02/23 00:00:00 by sfelici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	perform_dfs(t_dfs_info *dfs_data, int row, int col)
{
	if (row < 0 || row >= dfs_data->info->rows
		|| col < 0 || col >= dfs_data->info->cols)
		return ;
	if (dfs_data->map[row][col] == '1' || dfs_data->map[row][col] == 'V')
		return ;
	if (dfs_data->map[row][col] == 'C')
		(*(dfs_data->collectibles_found))++;
	else if (dfs_data->map[row][col] == 'E')
	{
		(*(dfs_data->exit_found))++;
		dfs_data->map[row][col] = 'V';
		return ;
	}
	dfs_data->map[row][col] = 'V';
	perform_dfs(dfs_data, row + 1, col);
	perform_dfs(dfs_data, row - 1, col);
	perform_dfs(dfs_data, row, col + 1);
	perform_dfs(dfs_data, row, col - 1);
}

static char	**alloc_map_copy(t_map_info *info)
{
	char	**map_copy;

	map_copy = malloc(sizeof(char *) * (info->rows + 1));
	if (!map_copy)
		return (NULL);
	return (map_copy);
}

static int	fill_map_copy(char **map, char **map_copy, t_map_info *info)
{
	int	i;

	i = 0;
	while (i < info->rows)
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			map_copy[i] = NULL;
			free_map(map_copy);
			return (1);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (0);
}

static int	check_path_result(int col_found, int ex_found, t_map_info *info)
{
	if (col_found == info->collectible_count && ex_found == 1)
		return (0);
	return (1);
}

int	check_path(char **map, t_map_info *info)
{
	char		**map_copy;
	t_dfs_info	dfs_data;
	int			collectibles_found;
	int			exit_found;

	collectibles_found = 0;
	exit_found = 0;
	map_copy = alloc_map_copy(info);
	if (!map_copy)
		return (1);
	if (fill_map_copy(map, map_copy, info))
		return (1);
	dfs_data.map = map_copy;
	dfs_data.info = info;
	dfs_data.collectibles_found = &collectibles_found;
	dfs_data.exit_found = &exit_found;
	perform_dfs(&dfs_data, info->player_y, info->player_x);
	if (check_path_result(collectibles_found, exit_found, info) == 0)
	{
		free_map(map_copy);
		return (0);
	}
	free_map(map_copy);
	return (1);
}
