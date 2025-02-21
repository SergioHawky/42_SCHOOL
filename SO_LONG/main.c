/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:05:53 by seilkiv           #+#    #+#             */
/*   Updated: 2025/02/20 06:10:41 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int main()
{
    game_data game;
    
    get_map_size("Maps/map2.ber", &game);
    game.map = map("Maps/map2.ber", &game);
    //printf("%d\n", game.map_height);
    //printf("%d\n", game.map_width);
    is_map_valid(&game);
    game.mlx = mlx_init();
    game.window = mlx_new_window(game.mlx, (game.map_width * TILE), (game.map_height * TILE), "MY GAME");
    game.animation.moving = 0;
    game.collectible.all_collectible = 0;
    game.player.count_moves = 0;
    game.animation.moving_direction = 2;
    
    put_textures_struct(&game);
    put_image_player(&game);
    put_base_mov_player(&game);
    put_base_mov_player_backward(&game);
    put_forward_mov_player(&game);
    put_backward_mov_player(&game);
    put_img_collectible(&game);
    put_img_exit(&game);
    
    draw_map(&game);
    spawn_player(&game);
    spawn_collectibles(&game, 1);
    spawn_exit(&game);
    HUD(&game);

    mlx_hook(game.window, KeyPress, KeyPressMask, key_press, &game);
    mlx_hook(game.window, KeyRelease, KeyReleaseMask, key_release, &game);
    mlx_loop_hook(game.mlx, update, &game);
    mlx_loop(game.mlx);
    return(0);
}