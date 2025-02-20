#include "so_long.h"

char	**read_map(const char *file_path)
{
	int		fd;
	char	*line;
	char	**map;
	char	*tmp_map;
	char	*tmp_join;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nImpossibile aprire il file %s\n", file_path);
		return (NULL);
	}
	tmp_map = ft_calloc(1, 1);
	while ((line = get_next_line(fd)) != NULL)
	{
		tmp_join = ft_strjoin(tmp_map, line);
		free(tmp_map);
		tmp_map = tmp_join;
		free(line);
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
