/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:17:32 by seilkiv           #+#    #+#             */
/*   Updated: 2025/02/19 21:17:32 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void    get_map_size(char *Map_Name, game_data *game)
{
    int fd;
    game->map_height = 0;
    game->map_width = 0;
    int     first_line = 1;
    char    c;

    fd = open(Map_Name, O_RDONLY);
    if(fd < 0)
    {
        write(2, "Error opening fd", 16);
        exit(1);
    }

    while(read(fd, &c, 1) > 0)
    {
        if(c == '\n')
        {
            game->map_height ++;
            first_line = 0;
        }
        else if(first_line)
            game->map_width ++;
    }
    close(fd);
}

char    **map(char *Map_Name)
{
    int     fd, bytes_read, i = 0;
    char    buffer[COLUMN + 2];
    
    char    **map = (char **)malloc(sizeof(char *) * (ROW + 1));
    if(!map)
        return NULL;
    
    fd = open(Map_Name, O_RDONLY);
    if(fd < 0)
    {
        write(2, "Erro ao abrir o mapa", 20);
        free(map);
        return NULL;
    }
    
    i = 0;
    while(i < ROW)
    {
        bytes_read = read(fd, buffer, COLUMN + 2);
        if(bytes_read <= 0)
        {
            close(fd);
            free_map(map, i);
            return NULL;
        }
        buffer[COLUMN] = '\0';
        map[i] = ft_strdup(buffer);
        if (!map[i])
        {
            close(fd);
            free_map(map, i);
            return NULL;
        }
        i ++;
    }
    map[i] = NULL;
    close(fd);
    return (map);
}

void    draw_map(game_data *game)
{
    int x, y = 0;
    int pixel_x, pixel_y = 0; 

    while(y < ROW && pixel_y < PIXEL_Y)
    {
        x = 0;
        pixel_x = 0;
        while(x < COLUMN && pixel_x < PIXEL_X)
        {
            if(game->map[y][x] == '1')
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
            x ++;
            pixel_x += TILE;
        }
        y ++;
        pixel_y += TILE;
    }
}