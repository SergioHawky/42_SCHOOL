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

int base_animation(game_data *game)
{
    static int frame = 0;
    static int delay = 0;

    delay++;
    if (delay > 10000)
    {
        frame = (frame + 1) % BASE_ANIM;
        mlx_put_image_to_window(game->mlx, game->window, game->animation.base_animation[frame], game->player.position_x, game->player.position_y);
        delay = 0;
    }
    return (0);
}

int move_forward_animation(game_data *game)
{
    static int frame = 0;
    static int delay = 0;
    
    if(!game->animation.moving)
        return (0);
        
    delay++;
    if (delay > 10000)
    {
        frame = (frame + 1) % FORW_ANIM;
        mlx_put_image_to_window(game->mlx, game->window, game->animation.move_forward_anim[frame], game->player.position_x, game->player.position_y);
        delay = 0;
    }
    return (0);
}