/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:05:53 by seilkiv           #+#    #+#             */
/*   Updated: 2025/02/12 02:32:02 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

    game.mlx = mlx_init();

    game.window = mlx_new_window(game.mlx, WIDTH, HEIGHT, "MY GAME");
    
    game.img = mlx_xpm_file_to_image(game.mlx, "/home/seilkiv/42_School/SO_LONG/Assets/TileSet/WALL.xpm", &game.img_width, &game.img_height);
    if(!game.img)
    {
        write(2, "Erro ao carregar a imagem", 25);
        exit(1);
    }
    
    mlx_put_image_to_window(game.mlx, game.window, game.img, 0, 0);
    
    mlx_key_hook(game.window, key_press, &game);

    mlx_loop(game.mlx);

    return(0);
}