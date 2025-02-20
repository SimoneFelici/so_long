#include "so_long.h"

/*
 * Legge il file .ber riga per riga con get_next_line
 * e ne costruisce una singola stringa. Poi la splitta su '\n'
 * in modo da ottenere un array di stringhe "map".
 */
char **read_map(const char *file_path)
{
	int   fd;
	char  *line;
	char  **map;
	char  *tmp_map;
	char  *tmp_join;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nImpossibile aprire il file %s\n", file_path);
		return (NULL);
	}
	tmp_map = ft_calloc(1, 1);
	if (!tmp_map)
	{
		close(fd);
		return (NULL);
	}
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
