/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:16:59 by seilkiv           #+#    #+#             */
/*   Updated: 2025/02/19 21:16:59 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void    put_textures_struct(game_data *game)
{
    int i = 0;

    char *all_textures[TOTAL_TXT] = {
        "Assets/TileSet/WALL_LEFT.xpm",
        "Assets/TileSet/WALL_RIGHT.xpm",
        "Assets/TileSet/WALL_UP.xpm",
        "Assets/TileSet/FLOOR.xpm",
        "Assets/TileSet/CORNER_LU.xpm",
        "Assets/TileSet/CORNER_LD.xpm",
        "Assets/TileSet/CORNER_RU.xpm",
        "Assets/TileSet/CORNER_RD.xpm",
        "Assets/TileSet/PLATFORM.xpm"
    };

    while (i < TOTAL_TXT)
    {
        game->textures[i] = mlx_xpm_file_to_image(game->mlx, all_textures[i], &game->img_width, &game->img_height);
        if (!game->textures[i])
        {
            write(2, "Erro a carregar a imagem textures", 34);
            exit(1);
        }
        i ++;
    }
    
}

void    put_image_player(game_data *game)
{
    game->player.img_player = mlx_xpm_file_to_image(game->mlx, "Assets/character/char_0.xpm", &game->player.player_width, &game->player.player_heigth);
}

void    put_base_mov_player(game_data *game)
{
    int i = 0;

    char *all_sprites[BASE_ANIM] = {
        "Assets/character/char_0.xpm",
        "Assets/character/char_1.xpm",
        "Assets/character/char_2.xpm",
        "Assets/character/char_3.xpm",
        "Assets/character/char_4.xpm",
        "Assets/character/char_5.xpm"
    };

    while (i < BASE_ANIM)
    {
        game->animation.base_animation[i] = mlx_xpm_file_to_image(game->mlx, all_sprites[i], &game->player.player_width, &game->player.player_heigth);
        if (!game->animation.base_animation[i])
        {
            write(2, "Erro a carregar a imagem base animation", 40);
            exit(1);
        }
        i ++;
    }
}

void    put_base_mov_player_backward(game_data *game)
{
    int i = 0;

    char *all_sprites[BASE_ANIM] = {
        "Assets/character/BACK/char_0B.xpm",
        "Assets/character/BACK/char_1B.xpm",
        "Assets/character/BACK/char_2B.xpm",
        "Assets/character/BACK/char_3B.xpm",
        "Assets/character/BACK/char_4B.xpm",
        "Assets/character/BACK/char_5B.xpm"
    };

    while (i < BASE_ANIM)
    {
        game->animation.base_animation_backward[i] = mlx_xpm_file_to_image(game->mlx, all_sprites[i], &game->player.player_width, &game->player.player_heigth);
        if (!game->animation.base_animation_backward[i])
        {
            write(2, "Erro a carregar a imagem base animation", 40);
            exit(1);
        }
        i ++;
    }
}

void    put_forward_mov_player(game_data *game)
{
    int i = 0;

    char *all_sprites[FORW_ANIM] = {
        "Assets/character/char_mov_forward0.xpm",
        "Assets/character/char_mov_forward1.xpm",
        "Assets/character/char_mov_forward2.xpm",
        "Assets/character/char_mov_forward3.xpm",
        "Assets/character/char_mov_forward4.xpm",
        "Assets/character/char_mov_forward5.xpm",
        "Assets/character/char_mov_forward6.xpm",
        "Assets/character/char_mov_forward7.xpm"
    };

    while (i < FORW_ANIM)
    {
        game->animation.move_forward_anim[i] = mlx_xpm_file_to_image(game->mlx, all_sprites[i], &game->player.player_width, &game->player.player_heigth);
        if (!game->animation.move_forward_anim[i])
        {
            write(2, "Erro a carregar a imagem forward animation", 43);
            exit(1);
        }
        i ++;
    }
}

void    put_backward_mov_player(game_data *game)
{
    int i = 0;

    char *all_sprites[FORW_ANIM] = {
        "Assets/character/BACK/char_mov_forward0B.xpm",
        "Assets/character/BACK/char_mov_forward1B.xpm",
        "Assets/character/BACK/char_mov_forward2B.xpm",
        "Assets/character/BACK/char_mov_forward3B.xpm",
        "Assets/character/BACK/char_mov_forward4B.xpm",
        "Assets/character/BACK/char_mov_forward5B.xpm",
        "Assets/character/BACK/char_mov_forward6B.xpm",
        "Assets/character/BACK/char_mov_forward7B.xpm"
    };

    while (i < FORW_ANIM)
    {
        game->animation.move_backward_anim[i] = mlx_xpm_file_to_image(game->mlx, all_sprites[i], &game->player.player_width, &game->player.player_heigth);
        if (!game->animation.move_backward_anim[i])
        {
            write(2, "Erro a carregar a imagem backward animation", 44);
            exit(1);
        }
        i ++;
    }
}

void    put_img_collectible(game_data *game)
{
    game->collectible.img_collectible = mlx_xpm_file_to_image(game->mlx, "Assets/collectible/coin.xpm", &game->collectible.width, &game->collectible.heigth);
    if(!game->collectible.img_collectible)
    {
        write(2, "Erro a carregar a imagem collectible", 37);
        exit(1);
    }
}

void    put_img_exit(game_data *game)
{
    game->exit.img_exit = mlx_xpm_file_to_image(game->mlx, "Assets/exit/shop.xpm", &game->exit.width, &game->exit.heigth);
    if(!game->exit.img_exit)
    {
        write(2, "Erro a carregar a imagem exit", 30);
        exit(1);
    }
}