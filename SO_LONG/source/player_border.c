/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_border.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:23:31 by seilkiv           #+#    #+#             */
/*   Updated: 2025/07/05 12:51:46 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_touching_collectible(t_game_data *game)
{
	if (game->map[game->b.t_row][game->b.l_col] == 'C')
	{
		game->map[game->b.t_row][game->b.l_col] = '0';
		game->collectible.all_collectible--;
	}
	else if (game->map[game->b.t_row][game->b.r_col] == 'C')
	{
		game->map[game->b.t_row][game->b.r_col] = '0';
		game->collectible.all_collectible--;
	}
	else if (game->map[game->b.b_row][game->b.l_col] == 'C')
	{
		game->map[game->b.b_row][game->b.l_col] = '0';
		game->collectible.all_collectible--;
	}
	else if (game->map[game->b.b_row][game->b.r_col] == 'C')
	{
		game->map[game->b.b_row][game->b.r_col] = '0';
		game->collectible.all_collectible--;
	}
}

void	player_touching_exit(t_game_data *game)
{
	if (game->map[game->b.t_row][game->b.l_col] == 'E')
	{
		game->exit.touching_exit = 1;
	}
	else if (game->map[game->b.t_row][game->b.r_col] == 'E')
	{
		game->exit.touching_exit = 1;
	}
	else if (game->map[game->b.b_row][game->b.l_col] == 'E')
	{
		game->exit.touching_exit = 1;
	}
	else if (game->map[game->b.b_row][game->b.r_col] == 'E')
	{
		game->exit.touching_exit = 1;
	}
	else
		game->exit.touching_exit = 0;
}

int	player_touching_something(t_game_data *game, int x, int y)
{
	game->b.l_col = x / TILE;
	game->b.r_col = (x + game->player.player_width) / TILE;
	game->b.t_row = y / TILE;
	game->b.b_row = (y + game->player.player_heigth) / TILE;
	player_touching_collectible(game);
	player_touching_exit(game);
	player_touching_enemy(game);
	if (game->map[game->b.t_row][game->b.l_col] != '1'
		&& game->map[game->b.t_row][game->b.r_col] != '1'
		&& game->map[game->b.b_row][game->b.l_col] != '1'
		&& game->map[game->b.b_row][game->b.r_col] != '1')
	{
		return (0);
	}
	return (1);
}
