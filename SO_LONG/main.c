/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:05:53 by seilkiv           #+#    #+#             */
/*   Updated: 2025/02/12 04:20:09 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int key_press(int keysym, game_data *game)
{
    if(keysym == 65307)
    {
        mlx_destroy_window(game->mlx, game->window);
        exit(0);
    }
    return(0);
}

char    **map(char *Map_Name)
{
    int     fd, bytes_read, i = 0;
    int     column = WIDTH/24, row = HEIGHT/24;
    char    buffer[column + 1];
    
    char    **map = (char **)malloc(sizeof(char *) * row);
    if(!map)
        return NULL;
    
    while(i < row)
    {
        map[i] = (char *)malloc(sizeof(char) * (column + 1));
        if(!map[i])
        {
            free_all();//funcao para libertar tudo o que aloquei ??e necessario??
            return NULL;
        }
        i ++;
    }
    
    fd = open(Map_Name, O_RDONLY);
    if(fd < 0)
    {
        write(2, "Erro ao abrir o mapa", 20);
        exit(1);
    }
    
    i = 0;
    while(i < row && fd >= 0)
    {
        bytes_read = read(fd, buffer, column);
        if(bytes_read < 0)
        {
            return(free_all, NULL); // fazer free para as columas preenchidas
        }
        buffer[bytes_read] = '\0';
        map[i] = strdup(buffer);    //incluir libft
        i ++;
    }
    map[i] = NULL;
    close(fd);
    return (map);
}

void    draw_map(char **map)
{
    
}

int main()
{
    game_data game;

    game.mlx = mlx_init();

    game.window = mlx_new_window(game.mlx, WIDTH, HEIGHT, "MY GAME");
    
    game.img = mlx_xpm_file_to_image(game.mlx, "/home/seilkiv/42_School/SO_LONG/Assets/TileSet/WALL.xpm", &game.img_width, &game.img_height);
    if(!game.img)
    {
        write(2, "Erro ao carregar a imagem", 25);
        exit(1);
    }
    
    mlx_put_image_to_window(game.mlx, game.window, game.img, 0, 0);
    
    mlx_key_hook(game.window, key_press, &game);

    mlx_loop(game.mlx);

    return(0);
}