/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HUD.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:22:57 by seilkiv           #+#    #+#             */
/*   Updated: 2025/07/05 12:51:46 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	game_over(t_game_data *game)
{
	mlx_string_put(game->mlx, game->window, (game->map_width * TILE) / 2 - 50,
		(game->map_height * TILE) / 2, 0xFFFFFF, "GAME OVER");
	mlx_string_put(game->mlx, game->window, (game->map_width * TILE) / 2 - 50,
		(game->map_height * TILE) / 2 + 20, 0xFFFFFF, "Press ESC to exit");
	return (0);
}

void	hud(t_game_data *game)
{
	char	*moves;

	moves = ft_itoa(game->player.count_moves);
	mlx_string_put(game->mlx, game->window, 10, 10, 0xFFFFFF, "Moves: ");
	mlx_string_put(game->mlx, game->window, 50, 10, 0xFFFFFF, moves);
	free(moves);
}
