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

#include "../includes/so_long.h"

int    update(game_data *game)
{
    if (game->game_over == 1)
        return (0);

    mlx_clear_window(game->mlx, game->window);
    draw_map(game);
    spawn_collectibles(game, 0);
    spawn_exit(game);
    spawn_enemy(game);
    player_can_exit(game);
    HUD(game);

    if (game->gravity == 1)
        apply_gravity(game);
    if (game->animation.moving == 1)
    {
        if (game->animation.moving_direction == 1)
            move_backward_animation(game);
        else if (game->animation.moving_direction == 2)
            move_forward_animation(game);
    }
    else
    {
        if (game->animation.moving_direction == 1)
            base_animation_backward(game);
        else if (game->animation.moving_direction == 2)
            base_animation(game);
    }
    if (game->enemy.touching_enemy == 1)
    {
        game->game_over = 1;
        mlx_loop_hook(game->mlx, game_over, game);
    }
    return (0);
}