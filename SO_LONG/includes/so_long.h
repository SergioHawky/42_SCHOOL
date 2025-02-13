/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:47:05 by seilkiv           #+#    #+#             */
/*   Updated: 2025/02/13 17:55:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define HEIGHT 240
#define WIDTH 384


typedef struct s_data {
    void    *mlx;
    void    *window;
    void    *img_walls_LEFT;
    void    *img_walls_RIGHT;
    void    *img_walls_UP;
    void    *img_floor;
    void    *img_corner_LU;
    void    *img_corner_LD;
    void    *img_corner_RU;
    void    *img_corner_RD;
    void    *img_platform;
    int     img_width;
    int     img_height;
    
}   game_data;

#endif