/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:28:08 by seilkiv           #+#    #+#             */
/*   Updated: 2025/02/14 18:28:08 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void    player_on_tile(game_data *game, int new_x, int new_y)
{
    int row = new_y / TILE;
    int col = new_x / TILE;

    if (game->map[row][col] != '1')
    {
        game->player.position_x = new_x;
        game->player.position_y = new_y;
        mlx_clear_window(game->mlx, game->window);
        draw_map(game, 1);
    }
}

int key_press(int keysym, game_data *game)
{
    int new_x = game->player.position_x;
    int new_y = game->player.position_y;

    if(keysym == 65307)
    {
        mlx_destroy_window(game->mlx, game->window);
        exit(0);
    }

    if (keysym == 119)                      // W (cima)
        new_y -= TILE;
    else if (keysym == 115)                 // S (baixo)
        new_y += TILE;
    else if (keysym == 97)                  // A (esquerda)
        new_x -= TILE;
    else if (keysym == 100)                 // D (direita)
        new_x += TILE;

    player_on_tile(game, new_x, new_y);
    mlx_put_image_to_window(game->mlx, game->window, game->player.img_player, game->player.position_x, game->player.position_y);
    return (0);
}