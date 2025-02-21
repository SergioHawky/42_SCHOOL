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

int    update(game_data *game)
{
    mlx_clear_window(game->mlx, game->window);
    draw_map(game);
    spawn_collectibles(game, 0);
    spawn_exit(game);
    player_can_exit(game);
    HUD(game);

    apply_gravity(game);
    if (game->animation. moving == 1)
    {
        if (game->animation.moving_direction == 1)
        {
            move_backward_animation(game);
        }
        else if (game->animation.moving_direction == 2)
        {
            move_forward_animation(game);
        }
    }
    else
    {
        if (game->animation.moving_direction == 1)
        {
            base_animation_backward(game);
        }
        else if (game->animation.moving_direction == 2)
        {
            base_animation(game);
        }
    }
    return (0);
}