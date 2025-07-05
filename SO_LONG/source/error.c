/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:22:28 by seilkiv           #+#    #+#             */
/*   Updated: 2025/07/05 12:51:46 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	initiation_variab(t_game_data *game)
{
	game->player.how_many_players = 0;
	game->collectible.how_many_collect = 0;
	game->exit.how_many_exit = 0;
}

static void	count_objects(t_game_data *game, int i, int j)
{
	if (i == 0 || i == (game->map_height - 1) || j == 0 || j == (game->map_width
			- 1))
	{
		if (game->map[i][j] != '1' || game->map[i][j] == '\0')
		{
			write(2, "Invalid map on borders", 22);
			free_map(game);
			exit(1);
		}
	}
	if (game->map[i][j] == 'P')
		game->player.how_many_players++;
	if (game->map[i][j] == 'C')
		game->collectible.how_many_collect++;
	if (game->map[i][j] == 'E')
		game->exit.how_many_exit++;
}

static void	player_collectibles_exit(t_game_data *game)
{
	if (game->player.how_many_players == 0 || game->player.how_many_players > 1)
	{
		write(2, "Invalid player", 14);
		free_map(game);
		exit(1);
	}
	if (game->collectible.how_many_collect == 0)
	{
		write(2, "Invalid collectibles", 20);
		free_map(game);
		exit(1);
	}
	if (game->exit.how_many_exit == 0 || game->exit.how_many_exit > 1)
	{
		write(2, "Invalid exit", 12);
		free_map(game);
		exit(1);
	}
}

void	is_map_valid(t_game_data *game)
{
	int	i;
	int	j;

	i = 0;
	initiation_variab(game);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '0' || game->map[i][j] == '1'
				|| game->map[i][j] == 'A' || game->map[i][j] == 'E'
				|| game->map[i][j] == 'P' || game->map[i][j] == 'C')
				count_objects(game, i, j);
			else
			{
				write(2, "Invalid letters", 16);
				free_map(game);
				exit(1);
			}
			j++;
		}
		i++;
	}
	player_collectibles_exit(game);
}

void	minimum_map_size(t_game_data *game)
{
	if (game->map_height < 3 || game->map_width < 3 || (game->map_width
			* game->map_height) < 15)
	{
		write(2, "Map does not have the minimum requirements", 42);
		exit(1);
	}
}
