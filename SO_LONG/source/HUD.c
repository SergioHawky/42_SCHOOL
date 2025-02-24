/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HUD.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 23:58:20 by seilkiv           #+#    #+#             */
/*   Updated: 2025/02/20 01:26:13 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <unistd.h> // Para sleep()

int    game_over(game_data *game)
{
    mlx_string_put(game->mlx, game->window, (game->map_width * TILE) / 2 - 50, (game->map_height * TILE) / 2, 0xFFFFFF, "GAME OVER");
    mlx_string_put(game->mlx, game->window, (game->map_width * TILE) / 2 - 50, (game->map_height * TILE) / 2 + 20, 0xFFFFFF, "Press ESC to exit");
    return (0);
}

void    HUD(game_data *game)
{
    char *moves = ft_itoa(game->player.count_moves);
    mlx_string_put(game->mlx, game->window, 10, 10, 0xFFFFFF, "Moves: ");
    mlx_string_put(game->mlx, game->window, 50, 10, 0xFFFFFF, moves);
    
    free(moves);
}