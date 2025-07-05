/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:23:36 by seilkiv           #+#    #+#             */
/*   Updated: 2025/07/05 12:51:46 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	spawn_player(t_game_data *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player.position_x = j * TILE;
				game->player.position_y = i * TILE;
				mlx_put_image_to_window(game->mlx, game->window,
					game->player.img_player, game->player.position_x,
					game->player.position_y + 5);
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	spawn_collectibles(t_game_data *game, int first_time)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
			{
				game->collectible.position_x = j * TILE;
				game->collectible.position_y = i * TILE;
				collectible_animation(game);
				if (first_time == 1)
					game->collectible.all_collectible++;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	spawn_exit(t_game_data *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
			{
				game->exit.position_x = j * TILE;
				game->exit.position_y = i * TILE;
				mlx_put_image_to_window(game->mlx, game->window,
					game->exit.img_exit, game->exit.position_x,
					game->exit.position_y);
			}
			j++;
		}
		j = 0;
		i++;
	}
}
