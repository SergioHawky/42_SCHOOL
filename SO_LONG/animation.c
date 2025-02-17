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

int base_animation(game_data *game)
{
    static int frame = 0;
    static int delay = 0;

    delay++;
    if (delay > 4000)
    {
        frame = (frame + 1) % BASE_ANIM;
        mlx_put_image_to_window(game->mlx, game->window, game->animation.base_animation[frame], game->player.position_x, game->player.position_y);
        delay = 0;
    }
    return (0);
}

int move_forward_animation(game_data *game)
{
    static int frame1 = 0;
    static int delay1 = 0;
    
    if(!game->animation.moving)
        return (0);
        
    delay1++;
    if (delay1 > 2000)
    {
        frame1 = (frame1 + 1) % FORW_ANIM;
        mlx_put_image_to_window(game->mlx, game->window, game->animation.move_forward_anim[frame1], game->player.position_x, game->player.position_y);
        delay1 = 0;
    }
    return (0);
}