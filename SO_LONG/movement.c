/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:17:43 by seilkiv           #+#    #+#             */
/*   Updated: 2025/02/19 21:17:43 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void player(game_data *game, int new_x, int new_y)
{
    if (!player_touching_tile(game, new_x, new_y))
    {
        game->player.position_x = new_x;
        game->player.position_y = new_y;
        game->player.count_moves ++;
        update(game);
    }
}

int key_press(int keysym, game_data *game)
{
    int new_x = game->player.position_x;
    int new_y = game->player.position_y;

    if(keysym == 65307)
    {
        free_all(game);
        exit(0);
    }

    if (keysym == 119)                  // W (cima)
    {
        new_y -= SPEED;
    }
    else if (keysym == 115)             // S (baixo)
    {
        new_y += SPEED;
    }
    else if (keysym == 97)              // A (esquerda)
    {
        new_x -= SPEED;
    }
    else if (keysym == 100)             // D (direita)
    {
        new_x += SPEED;
        game->animation.moving = 1;
    }
    player(game, new_x, new_y);

    return (0);
}

int key_release(int keysym, game_data *game)
{
    if (keysym == 100 || keysym == 97)
    {
        game->animation.moving = 0;
        mlx_loop_hook(game->mlx, base_animation, game);
    }
    return (0);
}