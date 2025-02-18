/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:16:34 by seilkiv           #+#    #+#             */
/*   Updated: 2025/02/14 19:16:34 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void    spawn_player(game_data *game)
{
    int i = 0;
    int j = 0;

    while (game->map[i])
    {
        while (game->map[i][j])
        {
            if (game->map[i][j] == 'P')
            {
                game->player.position_x = j * TILE;
                game->player.position_y = i * TILE;
                mlx_put_image_to_window(game->mlx, game->window, game->player.img_player, game->player.position_x, game->player.position_y += 5);
                return ;
            }
            j++;
        }
        j = 0;
        i++;
    }
}

void    spawn_collectibles(game_data *game)
{
    int i = 0;
    int j = 0;

    while (game->map[i])
    {
        while (game->map[i][j])
        {
            if (game->map[i][j] == 'C')
            {
                game->collectible.position_x = j * TILE;
                game->collectible.position_y = i * TILE;
                mlx_put_image_to_window(game->mlx, game->window, game->collectible.img_collectible, game->collectible.position_x + 15, game->collectible.position_y + 15);
            }
            j++;
        }
        j = 0;
        i++;
    }
}

void    spawn_exit(game_data *game)
{
    int i = 0;
    int j = 0;

    while (game->map[i])
    {
        while (game->map[i][j])
        {
            if (game->map[i][j] == 'E')
            {
                game->exit.position_x = j * TILE;
                game->exit.position_y = i * TILE;
                mlx_put_image_to_window(game->mlx, game->window, game->exit.img_exit, game->exit.position_x, game->exit.position_y);
            }
            j++;
        }
        j = 0;
        i++;
    }
}