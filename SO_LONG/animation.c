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
    if (delay > 4000)
    {
        mlx_put_image_to_window(game->mlx, game->window, game->player.idle_sprites[frame], game->player.position_x, game->player.position_y);
        frame = (frame + 1) % ANIMATION;
        delay = 0;
    }
    return (0);
}
