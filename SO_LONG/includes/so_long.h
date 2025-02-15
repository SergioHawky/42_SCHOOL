/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:47:05 by seilkiv           #+#    #+#             */
/*   Updated: 2025/02/15 17:04:36 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../minilibx-linux/mlx.h"
#include <X11/X.h>
#include <stdlib.h>
#include <unistd.h>     //write
#include <fcntl.h>      //open e read
#include <string.h>     //strdup dps tirar

#define ROW     7
#define COLUMN  25

#define TILE    40

#define PIXEL_X (COLUMN * TILE)     //ROW in pixels
#define PIXEL_Y (ROW * TILE)        //COLUMN in pixels

#define SPEED   5

#define TOTAL_TXT   9

#define ANIMATION   6

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

typedef struct i_data
{
    int     up;
    int     down;
    int     left;
    int     right;
}   input_data;
typedef struct p_data               //player
{
    void    *img_player;
    int     player_width;
    int     player_heigth;
    int     position_x;
    int     position_y;
    void    *idle_sprites[6];
}   player_data;

typedef struct c_data               //collectible
{
    void    *img_collectible;
    int     collectible_width;
    int     collectible_heigth;
    int     position_x;
    int     position_y;
}   collectible_data;

typedef struct s_data
{
    void    *mlx;
    void    *window;
    void    *textures[TOTAL_TXT];
    char    **map;
    int     img_width;
    int     img_height;
    player_data player;
    collectible_data collectible;
    input_data input;
}   game_data;


void    put_image_to_struct(game_data *game);
char    **map(char *Map_Name);
void    draw_map(game_data *game);
void    put_image_to_player(game_data *game);
int     key_press(int keysym, game_data *game);
void    spawn_player(game_data *game);
int     animate_idle(game_data *game);
void    put_movement_to_player(game_data *game);
void    free_all(char **map, int row);
void    free_images(game_data *game);

#endif