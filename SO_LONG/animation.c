/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:16:08 by seilkiv           #+#    #+#             */
/*   Updated: 2025/02/19 21:16:08 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void base_animation(game_data *game)
{
    static int frame = 0;
    static int delay = 0;
      
    delay++;
    if (delay > 400)
    {
        frame = (frame + 1) % BASE_ANIM;
        delay = 0;
    }
    mlx_put_image_to_window(game->mlx, game->window, game->animation.base_animation[frame], game->player.position_x, game->player.position_y);
}

void base_animation_backward(game_data *game)
{
    static int frame = 0;
    static int delay = 0;
      
    delay++;
    if (delay > 400)
    {
        frame = (frame + 1) % BASE_ANIM;
        delay = 0;
    }
    mlx_put_image_to_window(game->mlx, game->window, game->animation.base_animation_backward[frame], game->player.position_x, game->player.position_y);
}

void move_forward_animation(game_data *game)
{
    static int frame = 0;
    static int delay = 0;
      
    delay++;
    if (delay > 400)
    {
        frame = (frame + 1) % FORW_ANIM;
        delay = 0;
    }
    mlx_put_image_to_window(game->mlx, game->window, game->animation.move_forward_anim[frame], game->player.position_x, game->player.position_y);
}

void move_backward_animation(game_data *game)
{
    static int frame = 0;
    static int delay = 0;
      
    delay++;
    if (delay > 400)
    {
        frame = (frame + 1) % FORW_ANIM;
        delay = 0;
    }
    mlx_put_image_to_window(game->mlx, game->window, game->animation.move_backward_anim[frame], game->player.position_x, game->player.position_y);
}