/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:52:28 by seilkiv           #+#    #+#             */
/*   Updated: 2025/02/14 19:52:28 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int animate_idle(game_data *game)
{
    static int frame = 0;   
    static int delay = 0;   // Controle de tempo entre frames

    delay++;
    if (delay > 4000) // 4000 é o tempo entre frames
    {
        frame = (frame + 1) % 6; // 6 é o total de frames(sprites)
        game->player.img_player = game->player.idle_sprites[frame]; 
        mlx_put_image_to_window(game->mlx, game->window, game->player.img_player, game->player.position_x, game->player.position_y);
        delay = 0;
    }
    return (0);
}
