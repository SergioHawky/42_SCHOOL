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

#include "../includes/so_long.h"

#define PIXEL_X (game->map_width * TILE)            //WIDTH in pixels
#define PIXEL_Y (game->map_height * TILE)           //HEIGHT in pixels

void    get_map_size(char *Map_Name, game_data *game)
{
    int fd;
    game->map_height = 0;
    game->map_width = 0;
    int     count_width = 0;
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
        if(c == '\r')
        {
            continue;
        }
        if(c == '\n')
        {
            game->map_height++;
            first_line = 0;
            
            if (game->map_width == 0) // Definir a largura na primeira linha
                game->map_width = count_width;

            if (count_width != game->map_width)
            {
                printf("linha: %d count: %d, game: %d\n", game->map_height, count_width, game->map_width);
                write(2, "Invalid width", 14);
                exit(1);
            }
            
            count_width = 0;
        }
        else
        {
            if (first_line)
                game->map_width++;
                
            count_width++;
        }
    }

    if (count_width > 0) // Verifica se a última linha não terminou com '\n'
    {
        game->map_height++;

        if (count_width != game->map_width)
        {
            printf("Erro na última linha: count_width=%d, esperado=%d\n", count_width, game->map_width);
            write(2, "Invalid width", 14);
            exit(1);
        }
    }
    minimum_map_size(game);
    close(fd);
}

char    **map(char *Map_Name, game_data *game)
{
    int     fd, bytes_read, i = 0;
    char    buffer[game->map_width + 2];
    
    char    **map = (char **)malloc(sizeof(char *) * (game->map_height + 1));
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
    while(i < game->map_height)
    {
        bytes_read = read(fd, buffer, game->map_width + 2);
        if(bytes_read <= 0)
        {
            close(fd);
            free_map(game);
            return NULL;
        }
        buffer[game->map_width] = '\0';
        map[i] = ft_strdup(buffer);
        if (!map[i])
        {
            close(fd);
            free_map(game);
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

    while(y < game->map_height && pixel_y < PIXEL_Y)
    {
        x = 0;
        pixel_x = 0;
        while(x < game->map_width && pixel_x < PIXEL_X)
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