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
                mlx_put_image_to_window(game->mlx, game->window, game->player.img_player, game->player.position_x, game->player.position_y);
                return ;
            }
            j++;
        }
        j = 0;
        i++;
    }
}   