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

void player_on_tile(game_data *game, int new_x, int new_y)
{
    int left_col = new_x / TILE;                                        // B. esquerdo
    int right_col = (new_x + game->player.player_width - 1) / TILE;     // B. direito
    int top_row = new_y / TILE;                                         // B. topo
    int bottom_row = (new_y + game->player.player_heigth - 1) / TILE;   // B. base

    if (game->map[top_row][left_col] != '1' &&                          // Verifica se qualquer parte do personagem colide com um tile '1'
        game->map[top_row][right_col] != '1' &&
        game->map[bottom_row][left_col] != '1' &&
        game->map[bottom_row][right_col] != '1')
    {
        game->player.position_x = new_x;
        game->player.position_y = new_y;
        mlx_clear_window(game->mlx, game->window);
        draw_map(game);
        mlx_put_image_to_window(game->mlx, game->window, game->player.img_player, game->player.position_x, game->player.position_y);
    }
}

int key_press(int keysym, game_data *game)
{
    int new_x = game->player.position_x;
    int new_y = game->player.position_y;

    if(keysym == 65307)
    {
        //free_images(game);
        mlx_destroy_window(game->mlx, game->window);
        if (game->map)
            free_all(game->map, ROW);
        if (game->mlx)
        {
            mlx_destroy_display(game->mlx);
            free(game->mlx);
        }
        exit(0);
    }

    if (keysym == 119)                  // W (cima)
        new_y -= SPEED;  
    else if (keysym == 115)             // S (baixo)
        new_y += SPEED;
    else if (keysym == 97)              // A (esquerda)
        new_x -= SPEED;
    else if (keysym == 100)             // D (direita)
        new_x += SPEED;

    player_on_tile(game, new_x, new_y);

    return (0);
}