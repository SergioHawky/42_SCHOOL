/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:05:53 by seilkiv           #+#    #+#             */
/*   Updated: 2025/02/12 20:13:36 by marvin           ###   ########.fr       */
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
                mlx_put_image_to_window(game->mlx, game->window, game->img, pixel_x, pixel_y);
            //else if(map[y][x] == '0')
               // mlx_put_image_to_window(game->mlx, game->window, game->img, pixel_x, pixel_y);
            x ++;
            pixel_x += 24;
        }
        y ++;
        pixel_y += 24;
    }
}

int main()
{
    game_data game;
    char **map1 = map("map1.ber");

    game.mlx = mlx_init();

    game.window = mlx_new_window(game.mlx, WIDTH, HEIGHT, "MY GAME");
    
    //game.img = mlx_xpm_file_to_image(game.mlx, "/home/seilkiv/42_School/SO_LONG/Assets/TileSet/WALL.xpm", &game.img_width, &game.img_height);
    game.img = mlx_xpm_file_to_image(game.mlx, "/mnt/d/42/SO_LONG/Assets/TileSet/WALL.xpm", &game.img_width, &game.img_height);
    if(!game.img)
    {
        write(2, "Erro ao carregar a imagem", 25);
        exit(1);
    }
    
    draw_map(&game, map1);
    
    mlx_key_hook(game.window, key_press, &game);

    mlx_loop(game.mlx);

    return(0);
}