/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:18:16 by seilkiv           #+#    #+#             */
/*   Updated: 2025/02/19 21:18:16 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void    update(game_data *game)
{
    static int frame = 0;
    static int delay = 0;

    mlx_clear_window(game->mlx, game->window);
    draw_map(game);
    spawn_collectibles(game, 0);
    spawn_exit(game);
    player_can_exit(game);
    HUD(game);
    if (game->animation. moving == 1)
    {
        delay++;
        if (delay > 1)
        {
            frame = (frame + 1) % FORW_ANIM;
            mlx_put_image_to_window(game->mlx, game->window, game->animation.move_forward_anim[frame], game->player.position_x, game->player.position_y);
            delay = 0;
        }
    }
}