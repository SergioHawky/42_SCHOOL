/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:47:05 by seilkiv           #+#    #+#             */
/*   Updated: 2025/02/20 05:58:00 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "libft.h"
#include "../minilibx-linux/mlx.h"          //mlx
#include <X11/X.h>                          //keysym
#include <unistd.h>                         //write
#include <fcntl.h>                          //open e read
#include <string.h>                         
#include <stdio.h>                          //strdup dps tirar

#define TILE    40

#define SPEED   5

#define TOTAL_TXT   9

#define BASE_ANIM   6
#define FORW_ANIM   8
#define COLLEC_ANIM 6

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

typedef struct p_data               //player
{
    void    *img_player;
    int     player_width;
    int     player_heigth;
    float   position_x;
    float   position_y;
    float   gravity_velocity;
    int     count_moves;
}   player_data;

typedef struct a_data               //animation
{
    int     moving;
    int     moving_direction;
    void    *base_animation[BASE_ANIM];
    void    *move_forward_anim[FORW_ANIM];
    void    *move_backward_anim[FORW_ANIM];
    void    *base_animation_backward[BASE_ANIM];
    void    *collectible_animation[COLLEC_ANIM];
}   animation_data;

typedef struct c_data               //collectible
{
    void    *img_collectible;
    int     width;
    int     heigth;
    int     position_x;
    int     position_y;
    int     all_collectible;
}   collectible_data;

typedef struct e_data               //exit
{
    void    *img_exit;
    int     width;
    int     heigth;
    int     position_x;
    int     position_y;
    int     touching_exit;
}   exit_data;

typedef struct s_data
{
    void    *mlx;
    void    *window;
    void    *textures[TOTAL_TXT];
    char    **map;
    int     map_height;
    int     map_width;
    int     img_width;
    int     img_height;
    player_data player;
    animation_data animation;
    collectible_data collectible;
    exit_data exit;
}   game_data;


char    **map(char *Map_Name, game_data *game);
void    draw_map(game_data *game);
int     key_press(int keysym, game_data *game);
int     key_release(int keysym, game_data *game);
void    spawn_player(game_data *game);
void    spawn_collectibles(game_data *game, int first_time);
void    spawn_exit(game_data *game);
void    base_animation(game_data *game);
void    base_animation_backward(game_data *game);
void    move_forward_animation(game_data *game);
void    move_backward_animation(game_data *game);
void    collectible_animation(game_data *game);
void    free_map(game_data *game);
void    free_images(game_data *game);
void    free_all(game_data *game);
void    put_forward_mov_player(game_data *game);
void    put_backward_mov_player(game_data *game);
void    put_textures_struct(game_data *game);
void    put_image_player(game_data *game);
void    put_base_mov_player(game_data *game);
void    put_base_mov_player_backward(game_data *game);
void    put_img_collectible(game_data *game);
void    put_animation_collectible(game_data *game);
void    put_img_exit(game_data *game);
int     update(game_data *game);
int     player_touching_tile(game_data *game, int x, int y);
void    player_can_exit(game_data *game);
void    HUD(game_data *game);
void    is_map_valid(game_data *game);
void    get_map_size(char *Map_Name, game_data *game);
void    minimum_map_size(game_data *game);

void    apply_gravity(game_data *game);

#endif