/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:27:22 by seilkiv           #+#    #+#             */
/*   Updated: 2025/07/05 13:23:44 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_map_size(char *Map_Name, t_game_data *game)
{
	int		fd;
	int		count_width;
	int		first_line;
	char	c;

	game->map_height = 0;
	game->map_width = 0;
	count_width = 0;
	first_line = 1;
	fd = open(Map_Name, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error opening fd", 16);
		exit(1);
	}
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\r')
			continue ;
		if (c == '\n')
		{
			game->map_height++;
			first_line = 0;
			if (count_width != game->map_width)
			{
				write(2, "Invalid width", 14);
				exit(1);
			}
			count_width = 0;
		}
		else
		{
			if (first_line)
				game->map_width++;
			count_width++;
		}
	}
	if (count_width > 0)
	{
		game->map_height++;
		if (count_width != game->map_width)
		{
			write(2, "Invalid width", 14);
			exit(1);
		}
	}
	minimum_map_size(game);
	close(fd);
}

static char	*read_map_line(int fd, int width)
{
	char	buffer[width + 2];
	int		bytes_read;

	bytes_read = read(fd, buffer, width + 2);
	if (bytes_read <= 0)
		return (NULL);
	buffer[width] = '\0';
	return (ft_strdup(buffer));
}

static void	error(char **map)
{
	write(2, "Erro ao abrir o mapa\n", 22);
	free(map);
	exit(1);
}

char	**map(char *Map_Name, t_game_data *game)
{
	char	**map;
	int		fd;
	int		i;

	map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!map)
		return (NULL);
	fd = open(Map_Name, O_RDONLY);
	if (fd < 0)
	{
		error(map);
	}
	i = 0;
	while (i < game->map_height)
	{
		map[i] = read_map_line(fd, game->map_width);
		if (!map[i])
		{
			close(fd);
			free_map(game);
			return (NULL);
		}
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
