/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:05:53 by seilkiv           #+#    #+#             */
/*   Updated: 2025/02/14 15:59:58 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include <stdio.h>
#include <string.h>

int key_press(int keysym, game_data *game)
{
    if(keysym == 65307)
    {
        mlx_destroy_window(game->mlx, game->window);
        exit(0);
    }
    return(0);
}

int main()
{
    game_data game;
    
    char **map1 = map("map1.ber");

    game.mlx = mlx_init();

    game.window = mlx_new_window(game.mlx, PIXEL_X, PIXEL_Y, "MY GAME");
    
    //game.img = mlx_xpm_file_to_image(game.mlx, "/home/seilkiv/42_School/SO_LONG/Assets/TileSet/WALL.xpm", &game.img_width, &game.img_height);
    put_image_to_struct(&game);
    put_image_to_player(&game);
    
    draw_map(&game, map1);
    
    mlx_key_hook(game.window, key_press, &game);

    mlx_loop(game.mlx);

    return(0);
}