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
		ft_printf("Error\nCan't open file %s\n", file_path);
		return (-1);
	}
	return (fd);
}

static char	*validate_tmp_map(char *tmp_map)
{
	if (!tmp_map || !*tmp_map)
	{
		ft_printf("Error\nFile blank or can't read it\n");
		free(tmp_map);
		return (NULL);
	}
	return (tmp_map);
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
	tmp_map = validate_tmp_map(tmp_map);
	if (!tmp_map)
		return (NULL);
	map = ft_split(tmp_map, '\n');
	free(tmp_map);
	return (map);
}
