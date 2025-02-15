/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:05:53 by seilkiv           #+#    #+#             */
/*   Updated: 2025/02/15 16:36:41 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include <stdio.h>
#include <string.h>


int main()
{
    game_data game;
    
    game.map = map("map2.ber");

    game.mlx = mlx_init();

    game.window = mlx_new_window(game.mlx, PIXEL_X, PIXEL_Y, "MY GAME");
    
    //game.img = mlx_xpm_file_to_image(game.mlx, "/home/seilkiv/42_School/SO_LONG/Assets/TileSet/WALL.xpm", &game.img_width, &game.img_height);
    put_image_to_struct(&game);
    put_image_to_player(&game);
    put_movement_to_player(&game);
    
    draw_map(&game);
    spawn_player(&game);

    mlx_loop_hook(game.mlx, animate_idle, &game);
    mlx_hook(game.window, KeyPress, KeyPressMask, key_press, &game);

    mlx_loop(game.mlx);
    return(0);
}