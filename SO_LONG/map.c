/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:09:03 by seilkiv           #+#    #+#             */
/*   Updated: 2025/02/14 15:09:03 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void free_all(char **map, int row) {
    for (int i = 0; i < row; i++) {
        free(map[i]);
    }
    free(map);
}

char    **map(char *Map_Name)
{
    int     fd, bytes_read, i = 0;
    char    buffer[COLUMN + 2];
    
    char    **map = (char **)malloc(sizeof(char *) * ROW + 1);
    if(!map)
        return NULL;
    
    fd = open(Map_Name, O_RDONLY);
    if(fd < 0)
    {
        write(2, "Erro ao abrir o mapa", 20);
        exit(1);
    }
    
    i = 0;
    while(i < ROW && fd >= 0)
    {
        bytes_read = read(fd, buffer, COLUMN+2);
        if(bytes_read < 0)
        {
            return(free_all(map, i), NULL); // fazer free para as columas preenchidas
        }
        buffer[bytes_read] = '\0';
        map[i] = strdup(buffer);  // lib
        if (!map[i])
        {
            free_all(map, i);
            return NULL;
        }
        i ++;
    }
    map[i] = NULL;
    close(fd);
    return (map);
}

void    draw_map(game_data *game, char **map)
{
    int x, y = 0;
    int pixel_x, pixel_y = 0; 

    while(y < ROW && pixel_y < PIXEL_Y)
    {
        x = 0;
        pixel_x = 0;
        while(x < COLUMN && pixel_x < PIXEL_X)
        {
            if(map[y][x] == '1')
            {
                if (pixel_x == 0 && pixel_y == 0)
                    mlx_put_image_to_window(game->mlx, game->window, game->textures[CORNER_LU], pixel_x, pixel_y);
                else if (pixel_x == (PIXEL_X - TILE)  && pixel_y == 0)
                    mlx_put_image_to_window(game->mlx, game->window, game->textures[CORNER_RU], pixel_x, pixel_y);
                else if (pixel_x == 0 && pixel_y == (PIXEL_Y - TILE))
                    mlx_put_image_to_window(game->mlx, game->window, game->textures[CORNER_LD], pixel_x, pixel_y);
                else if (pixel_x == (PIXEL_X - TILE) && pixel_y == (PIXEL_Y - TILE))
                    mlx_put_image_to_window(game->mlx, game->window, game->textures[CORNER_RD], pixel_x, pixel_y);
                else if (pixel_x == 0)
                    mlx_put_image_to_window(game->mlx, game->window, game->textures[WALL_LEFT], pixel_x, pixel_y);
                else if (pixel_x == (PIXEL_X - TILE))
                    mlx_put_image_to_window(game->mlx, game->window, game->textures[WALL_RIGHT], pixel_x, pixel_y);
                else if (pixel_y == 0)
                    mlx_put_image_to_window(game->mlx, game->window, game->textures[WALL_UP], pixel_x, pixel_y);
                else if (pixel_y == (PIXEL_Y - TILE))
                    mlx_put_image_to_window(game->mlx, game->window, game->textures[FLOOR], pixel_x, pixel_y);
                else
                    mlx_put_image_to_window(game->mlx, game->window, game->textures[PLATFORM], pixel_x, pixel_y);
            }
            else if (map[y][x] == 'P')
            {
                mlx_put_image_to_window(game->mlx, game->window, game->player.img_player, pixel_x, pixel_y);
            }
            
            x ++;
            pixel_x += TILE;
        }
        y ++;
        pixel_y += TILE;
    }
}