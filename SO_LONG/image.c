/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:32:17 by seilkiv           #+#    #+#             */
/*   Updated: 2025/02/14 14:32:17 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void    put_textures_struct(game_data *game)
{
    int i = 0;

    char *all_textures[TOTAL_TXT] = {
        "/mnt/d/42/SO_LONG/Assets/TileSet/WALL_LEFT.xpm",
        "/mnt/d/42/SO_LONG/Assets/TileSet/WALL_RIGHT.xpm",
        "/mnt/d/42/SO_LONG/Assets/TileSet/WALL_UP.xpm",
        "/mnt/d/42/SO_LONG/Assets/TileSet/FLOOR.xpm",
        "/mnt/d/42/SO_LONG/Assets/TileSet/CORNER_LU.xpm",
        "/mnt/d/42/SO_LONG/Assets/TileSet/CORNER_LD.xpm",
        "/mnt/d/42/SO_LONG/Assets/TileSet/CORNER_RU.xpm",
        "/mnt/d/42/SO_LONG/Assets/TileSet/CORNER_RD.xpm",
        "/mnt/d/42/SO_LONG/Assets/TileSet/PLATFORM.xpm"
    };

    while (i < TOTAL_TXT)
    {
        game->textures[i] = mlx_xpm_file_to_image(game->mlx, all_textures[i], &game->img_width, &game->img_height);
        if (!game->textures[i])
        {
            write(2, "Erro a carregar a imagem", 25);
            exit(1);
        }
        i ++;
    }
    
}

void    put_image_player(game_data *game)
{
    game->player.img_player = mlx_xpm_file_to_image(game->mlx, "/mnt/d/42/SO_LONG/Assets/character/char.xpm", &game->player.player_width, &game->player.player_heigth);
}

void    put_base_mov_player(game_data *game)
{
    int i = 0;

    char *all_sprites[BASE_ANIM] = {
        "/mnt/d/42/SO_LONG/Assets/character/char.xpm",
        "/mnt/d/42/SO_LONG/Assets/character/char_1.xpm",
        "/mnt/d/42/SO_LONG/Assets/character/char_2.xpm",
        "/mnt/d/42/SO_LONG/Assets/character/char_3.xpm",
        "/mnt/d/42/SO_LONG/Assets/character/char_4.xpm",
        "/mnt/d/42/SO_LONG/Assets/character/char_5.xpm"
    };

    while (i < BASE_ANIM)
    {
        game->animation.base_animation[i] = mlx_xpm_file_to_image(game->mlx, all_sprites[i], &game->player.player_width, &game->player.player_heigth);
        if (!game->animation.base_animation[i])
        {
            write(2, "Erro a carregar a imagem", 25);
            exit(1);
        }
        i ++;
    }
}

void    put_forward_mov_player(game_data *game)
{
    int i = 0;

    char *all_sprites[FORW_ANIM] = {
        "/mnt/d/42/SO_LONG/Assets/character/char_mov_forward0.xpm",
        "/mnt/d/42/SO_LONG/Assets/character/char_mov_forward1.xpm",
        "/mnt/d/42/SO_LONG/Assets/character/char_mov_forward2.xpm",
        "/mnt/d/42/SO_LONG/Assets/character/char_mov_forward3.xpm",
        "/mnt/d/42/SO_LONG/Assets/character/char_mov_forward4.xpm",
        "/mnt/d/42/SO_LONG/Assets/character/char_mov_forward5.xpm",
        "/mnt/d/42/SO_LONG/Assets/character/char_mov_forward6.xpm",
        "/mnt/d/42/SO_LONG/Assets/character/char_mov_forward7.xpm"
    };

    while (i < FORW_ANIM)
    {
        game->animation.move_forward_anim[i] = mlx_xpm_file_to_image(game->mlx, all_sprites[i], &game->player.player_width, &game->player.player_heigth);
        if (!game->animation.move_forward_anim[i])
        {
            write(2, "Erro a carregar a imagem", 25);
            exit(1);
        }
        i ++;
    }
}