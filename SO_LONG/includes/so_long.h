/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:47:05 by seilkiv           #+#    #+#             */
/*   Updated: 2025/02/12 20:28:22 by marvin           ###   ########.fr       */
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
    void    *img;
    int     img_width;
    int     img_height;
    
}   game_data;

#endif