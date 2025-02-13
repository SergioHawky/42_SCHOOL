/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:05:53 by seilkiv           #+#    #+#             */
/*   Updated: 2025/02/13 22:55:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#define COLUMN (WIDTH/24)
#define ROW (HEIGHT/24)
#include <stdio.h>
#include <string.h>

int key_press(int keysym, game_data *game)
{
    if(keysym == 65307)
    {
        mlx_destroy_window(game->mlx, game->window);
        exit(0);
    }
    return(0);
}

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

    while(y < ROW && pixel_y < HEIGHT)
    {
        x = 0;
        pixel_x = 0;
        while(x < COLUMN && pixel_x < WIDTH)
        {
            if(map[y][x] == '1')
            {
                if (pixel_x == 0 && pixel_y == 0)
                    mlx_put_image_to_window(game->mlx, game->window, game->img_corner_LU, pixel_x, pixel_y);
                else if (pixel_x == (WIDTH - 24)  && pixel_y == 0)
                    mlx_put_image_to_window(game->mlx, game->window, game->img_corner_RU, pixel_x, pixel_y);
                else if (pixel_x == 0 && pixel_y == (HEIGHT - 24))
                    mlx_put_image_to_window(game->mlx, game->window, game->img_corner_LD, pixel_x, pixel_y);
                else if (pixel_x == (WIDTH - 24) && pixel_y == (HEIGHT - 24))
                    mlx_put_image_to_window(game->mlx, game->window, game->img_corner_RD, pixel_x, pixel_y);
                else if (pixel_x == 0)
                    mlx_put_image_to_window(game->mlx, game->window, game->img_walls_LEFT, pixel_x, pixel_y);
                else if (pixel_x == (WIDTH - 24))
                    mlx_put_image_to_window(game->mlx, game->window, game->img_walls_RIGHT, pixel_x, pixel_y);
                else if (pixel_y == 0)
                    mlx_put_image_to_window(game->mlx, game->window, game->img_walls_UP, pixel_x, pixel_y);
                else if (pixel_y == (HEIGHT - 24))
                    mlx_put_image_to_window(game->mlx, game->window, game->img_floor, pixel_x, pixel_y);
                else
                    mlx_put_image_to_window(game->mlx, game->window, game->img_platform, pixel_x, pixel_y);
            }
            x ++;
            pixel_x += 24;
        }
        y ++;
        pixel_y += 24;
    }
}

void    put_image_to_struct(game_data *game)
{
    game->img_walls_RIGHT = mlx_xpm_file_to_image(game->mlx, "/mnt/d/42/SO_LONG/Assets/TileSet/WALL_RIGHT.xpm", &game->img_width, &game->img_height);
    if(!game->img_walls_RIGHT)
    {
        write(2, "Erro ao carregar a imagem WALL_RIGHT", 25);
        exit(1);
    }
    game->img_walls_LEFT = mlx_xpm_file_to_image(game->mlx, "/mnt/d/42/SO_LONG/Assets/TileSet/WALL_LEFT.xpm", &game->img_width, &game->img_height);
    if(!game->img_walls_LEFT)
    {
        write(2, "Erro ao carregar a imagem WALL_LEFT", 25);
        exit(1);
    }
    game->img_walls_UP = mlx_xpm_file_to_image(game->mlx, "/mnt/d/42/SO_LONG/Assets/TileSet/WALL_UP.xpm", &game->img_width, &game->img_height);
    if(!game->img_walls_UP)
    {
        write(2, "Erro ao carregar a imagem WALL_UP", 25);
        exit(1);
    }
    game->img_floor = mlx_xpm_file_to_image(game->mlx, "/mnt/d/42/SO_LONG/Assets/TileSet/FLOOR.xpm", &game->img_width, &game->img_height);
    if(!game->img_floor)
    {
        write(2, "Erro ao carregar a imagem FLOOR", 25);
        exit(1);
    }
    game->img_corner_LU = mlx_xpm_file_to_image(game->mlx, "/mnt/d/42/SO_LONG/Assets/TileSet/CORNER_LU.xpm", &game->img_width, &game->img_height);
    if(!game->img_corner_LU)
    {
        write(2, "Erro ao carregar a imagem CORNER_LU", 25);
        exit(1);
    }
    game->img_corner_LD = mlx_xpm_file_to_image(game->mlx, "/mnt/d/42/SO_LONG/Assets/TileSet/CORNER_LD.xpm", &game->img_width, &game->img_height);
    if(!game->img_corner_LD)
    {
        write(2, "Erro ao carregar a imagem CORNER_LD", 25);
        exit(1);
    }
    game->img_corner_RD = mlx_xpm_file_to_image(game->mlx, "/mnt/d/42/SO_LONG/Assets/TileSet/CORNER_RD.xpm", &game->img_width, &game->img_height);
    if(!game->img_corner_RD)
    {
        write(2, "Erro ao carregar a imagem CORNER_RD", 25);
        exit(1);
    }
    game->img_corner_RU = mlx_xpm_file_to_image(game->mlx, "/mnt/d/42/SO_LONG/Assets/TileSet/CORNER_RU.xpm", &game->img_width, &game->img_height);
    if(!game->img_corner_RU)
    {
        write(2, "Erro ao carregar a imagem CORNER_RU", 25);
        exit(1);
    }
    game->img_platform = mlx_xpm_file_to_image(game->mlx, "/mnt/d/42/SO_LONG/Assets/TileSet/PLATFORM.xpm", &game->img_width, &game->img_height);
    if(!game->img_platform)
    {
        write(2, "Erro ao carregar a imagem PLATFORM", 25);
        exit(1);
    }
}

int main()
{
    game_data game;
    char **map1 = map("map1.ber");

    game.mlx = mlx_init();

    game.window = mlx_new_window(game.mlx, WIDTH, HEIGHT, "MY GAME");
    
    //game.img = mlx_xpm_file_to_image(game.mlx, "/home/seilkiv/42_School/SO_LONG/Assets/TileSet/WALL.xpm", &game.img_width, &game.img_height);
    put_image_to_struct(&game);
    
    draw_map(&game, map1);
    
    mlx_key_hook(game.window, key_press, &game);

    mlx_loop(game.mlx);

    return(0);
}