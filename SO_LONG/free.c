/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:16:32 by seilkiv           #+#    #+#             */
/*   Updated: 2025/02/19 21:16:32 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void    free_images(game_data *game)
{
    int i;

    i = 0;
    while (i < TOTAL_TXT)
    {
        if (game->textures[i])
            mlx_destroy_image(game->mlx, game->textures[i]);
        i++;
    }
    i = 0;
    while (i < BASE_ANIM)
    {
        if (game->animation.base_animation[i])
            mlx_destroy_image(game->mlx, game->animation.base_animation[i]);
        i++;
    }
    i = 0;
    while (i < BASE_ANIM)
    {
        if (game->animation.base_animation_backward[i])
            mlx_destroy_image(game->mlx, game->animation.base_animation_backward[i]);
        i++;
    }
    i = 0;
    while (i < FORW_ANIM)
    {
        if (game->animation.move_forward_anim[i])
            mlx_destroy_image(game->mlx, game->animation.move_forward_anim[i]);
        i++;
    }
    i = 0;
    while (i < FORW_ANIM)
    {
        if (game->animation.move_backward_anim[i])
            mlx_destroy_image(game->mlx, game->animation.move_backward_anim[i]);
        i++;
    }
    i = 0;
    while (i < COLLEC_ANIM)
    {
        if (game->animation.collectible_animation[i])
            mlx_destroy_image(game->mlx, game->animation.collectible_animation[i]);
        i++;
    }
    if (game->player.img_player)
        mlx_destroy_image(game->mlx, game->player.img_player);
    
    if (game->collectible.img_collectible)
        mlx_destroy_image(game->mlx, game->collectible.img_collectible);
    
    if (game->exit.img_exit)
        mlx_destroy_image(game->mlx, game->exit.img_exit);
}

void free_map(game_data *game) 
{
    int i;

    i = 0;
    while (i < game->map_height)
    {
        if (game->map[i])     
            free(game->map[i]);
        i++;
    }
    free(game->map);
}

void free_all(game_data *game)
{
    free_images(game);
    free_map(game);
    mlx_destroy_window(game->mlx, game->window);
    mlx_destroy_display(game->mlx);
    free(game->mlx);
    exit(0);
}