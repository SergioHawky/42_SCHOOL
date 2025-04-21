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

#include "../includes/so_long.h"

void player(game_data *game, int new_x, int new_y)
{
    if (!player_touching_something(game, new_x, new_y))
    {
        game->player.position_x = new_x;
        game->player.position_y = new_y;
        if (game->animation.moving == 1)
        {
            game->player.count_moves ++;
        }
    }
}

int key_press(int keysym, game_data *game)
{
    float new_x = game->player.position_x;
    float new_y = game->player.position_y;

    if(keysym == 65307)                         // ESC (sair do jogo)
    {
        free_all(game);
        exit(0);
    }
    else if (keysym == 97)                      // A (esquerda)
    {
        new_x -= SPEED;
        game->animation.moving = 1;
        game->animation.moving_direction = 1;
    }
    else if (keysym == 100)                     // D (direita)
    {
        new_x += SPEED;
        game->animation.moving = 1;
        game->animation.moving_direction = 2;
    }
    else if (keysym == 119)                     // W (cima)
    {  
       new_y -= SPEED;
       if (game->gravity == 0)                  //move count
            game->animation.moving = 1;
    }
    else if(keysym == 115)                      // S (baixo)
    {
        new_y += SPEED;
        if (game->gravity == 0)
            game->animation.moving = 1;
    }
    else if (keysym == 103)                     // G (gravidade)
    {
        game->animation.moving = 0;
        if (game->gravity == 0)
            game->gravity = 1;
        else
            game->gravity = 0;
    }
    player(game, new_x, new_y);
    return (0);
}

int key_release(int keysym, game_data *game)
{
    if (keysym == 100 || keysym == 97)
    {
        game->animation.moving = 0;
    }
    return (0);
}

int close_window(game_data *game)
{
    free_all(game);  // Libera memória e fecha o jogo corretamente
    exit(0);
    return (0);
}
