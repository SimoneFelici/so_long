/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfelici <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:29:25 by sfelici           #+#    #+#             */
/*   Updated: 2025/02/21 15:29:33 by sfelici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	dfs(char **map, int row, int col, t_map_info *info, int *collectibles_found, int *exit_found)
{
	if (row < 0 || row >= info->rows || col < 0 || col >= info->cols)
		return ;
	if (map[row][col] == '1' || map[row][col] == 'V')
		return ;
	if (map[row][col] == 'C')
		(*collectibles_found)++;
	else if (map[row][col] == 'E')
		(*exit_found)++;
	map[row][col] = 'V';
	dfs(map, row + 1, col, info, collectibles_found, exit_found);
	dfs(map, row - 1, col, info, collectibles_found, exit_found);
	dfs(map, row, col + 1, info, collectibles_found, exit_found);
	dfs(map, row, col - 1, info, collectibles_found, exit_found);
}

int	check_path(char **map, t_map_info *info)
{
	char	**map_copy;
	int		i;
	int		collectibles_found;
	int		exit_found;

	i = 0;
	collectibles_found = 0;
	exit_found = 0;
	map_copy = malloc(sizeof(char *) * (info->rows + 1));
	if (!map_copy)
		return (1);
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
	dfs(map_copy, info->player_y, info->player_x, info, &collectibles_found, &exit_found);
	int result = (collectibles_found == info->collectible_count && exit_found == 1) ? 0 : 1;
	free_map(map_copy);
	return (result);
}
