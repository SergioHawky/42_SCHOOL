/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:58:37 by seilkiv           #+#    #+#             */
/*   Updated: 2025/02/15 16:58:37 by seilkiv          ###   ########.fr       */
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
    while (i < ANIMATION)
    {
        if (game->player.idle_sprites[i])
            mlx_destroy_image(game->mlx, game->player.idle_sprites[i]);
        i++;
    }
    
    if (game->player.img_player)
        mlx_destroy_image(game->mlx, game->player.img_player);
}

void free_map(char **map, int row) 
{
    int i;

    i = 0;
    while (i < row)
    {
        if (map[i])     
            free(map[i]);
        i++;
    }
    free(map);
}

void free_all(game_data *game)
{
    free_images(game);
    free_map(game->map, ROW);
    mlx_destroy_window(game->mlx, game->window);
    mlx_destroy_display(game->mlx);
    free(game->mlx);
    exit(0);
}