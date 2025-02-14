/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:47:05 by seilkiv           #+#    #+#             */
/*   Updated: 2025/02/14 18:28:48 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>     //write
#include <fcntl.h>      //open e read
#include <string.h>     //strdup dps tirar

#define TOTAL_TXT   9

#define ROW     10
#define COLUMN  16

#define TILE    34

#define PIXEL_X (COLUMN * TILE)     //ROW in pixels
#define PIXEL_Y (ROW * TILE)        //COLUMN in pixels

typedef enum e_texture              //Nao esta diretamente no codigo so serve para ser mais legivel
{
    WALL_LEFT,
    WALL_RIGHT,
    WALL_UP,
    FLOOR,
    CORNER_LU,
    CORNER_LD,
    CORNER_RU,
    CORNER_RD,
    PLATFORM
}   texture;

typedef struct p_data 
{
    void    *img_player;
    int     player_width;
    int     player_heigth;
    int     position_x;
    int     position_y;
}   player_data;

typedef struct s_data
{
    void    *mlx;
    void    *window;
    void    *textures[TOTAL_TXT];
    char    **map;
    int     img_width;
    int     img_height;
    player_data player;
}   game_data;


void    put_image_to_struct(game_data *game);
char    **map(char *Map_Name);
void    draw_map(game_data *game, int flag);
void    put_image_to_player(game_data *game);
int     key_press(int keysym, game_data *game);

#endif