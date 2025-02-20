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
    mlx_clear_window(game->mlx, game->window);
    draw_map(game);
    spawn_collectibles(game, 0);
    spawn_exit(game);
    player_can_exit(game);
    HUD(game);
    mlx_put_image_to_window(game->mlx, game->window, game->player.img_player, game->player.position_x, game->player.position_y);
}