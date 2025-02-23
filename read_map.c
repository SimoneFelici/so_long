/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfelici <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:14:18 by sfelici           #+#    #+#             */
/*   Updated: 2025/02/21 15:21:46 by sfelici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_opener(const char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nImpossibile aprire il file %s\n", file_path);
		return (NULL);
	}
	return (fd);
}

char	**read_map(const char *file_path)
{
	int		fd;
	char	*line;
	char	**map;
	char	*tmp_map;
	char	*tmp_join;

	fd = ft_opener(file_path);
	tmp_map = ft_calloc(1, 1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		tmp_join = ft_strjoin(tmp_map, line);
		free(tmp_map);
		tmp_map = tmp_join;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (!tmp_map || !*tmp_map)
	{
		ft_printf("Error\nFile vuoto o illeggibile\n");
		free(tmp_map);
		return (NULL);
	}
	map = ft_split(tmp_map, '\n');
	free(tmp_map);
	return (map);
}
