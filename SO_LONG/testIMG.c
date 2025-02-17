#include "includes/so_long.h"

void free_map1(char **map, int row) 
{
    int i;

    i = 0;
    while (i < row)
    {
        if (map[i])     
            free(map[i]);
        i++;
    }
    free(map);
}

void    free_images1(game_data *game)
{
    int i;

    i = 0;
    while (i < TOTAL_TXT)
    {
        if (game->textures[i])
            mlx_destroy_image(game->mlx, game->textures[i]);
        i++;
    }
    i = 0;
    while (i < ANIMATION)
    {
        if (game->player.idle_sprites[i])
            mlx_destroy_image(game->mlx, game->player.idle_sprites[i]);
        i++;
    }
    
    if (game->player.img_player)
        mlx_destroy_image(game->mlx, game->player.img_player);
}

void clean_up(game_data *game)
{
    free_images1(game); // Liberta as imagens carregadas
    free_map1(game->map, ROW);
    mlx_destroy_window(game->mlx, game->window);
    mlx_destroy_display(game->mlx); // Liberta o display da MiniLibX
    free(game->mlx); // Liberta a estrutura mlx
}


char    **map1(char *Map_Name)
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
            free_map1(map, i);
            return NULL;
        }
        buffer[COLUMN] = '\0';
        map[i] = strdup(buffer);  // lib
        if (!map[i])
        {
            close(fd);
            free_map1(map, i);
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

void    put_image_to_struct1(game_data *game)
{
    int i = 0;

    char *all_textures[TOTAL_TXT] = {
        "/mnt/d/42/SO_LONG/Assets/TileSet/WALL_LEFT.xpm",
        "/mnt/d/42/SO_LONG/Assets/TileSet/WALL_RIGHT.xpm",
        "/mnt/d/42/SO_LONG/Assets/TileSet/WALL_UP.xpm",
        "/mnt/d/42/SO_LONG/Assets/TileSet/FLOOR.xpm",
        "/mnt/d/42/SO_LONG/Assets/TileSet/CORNER_LU.xpm",
        "/mnt/d/42/SO_LONG/Assets/TileSet/CORNER_LD.xpm",
        "/mnt/d/42/SO_LONG/Assets/TileSet/CORNER_RU.xpm",
        "/mnt/d/42/SO_LONG/Assets/TileSet/CORNER_RD.xpm",
        "/mnt/d/42/SO_LONG/Assets/TileSet/PLATFORM.xpm"
    };

    while (i < TOTAL_TXT)
    {
        game->textures[i] = mlx_xpm_file_to_image(game->mlx, all_textures[i], &game->img_width, &game->img_height);
        if (!game->textures[i])
        {
            write(2, "Erro a carregar a imagem", 25);
            exit(1);
        }
        i ++;
    }
    
}

void    put_image_to_player1(game_data *game)
{
    game->player.img_player = mlx_xpm_file_to_image(game->mlx, "/mnt/d/42/SO_LONG/Assets/character/char.xpm", &game->player.player_width, &game->player.player_heigth);
}

void    put_movement_to_player1(game_data *game)
{
    int i = 0;

    char *all_sprites[6] = {
        "/mnt/d/42/SO_LONG/Assets/character/char.xpm",
        "/mnt/d/42/SO_LONG/Assets/character/char_1.xpm",
        "/mnt/d/42/SO_LONG/Assets/character/char_2.xpm",
        "/mnt/d/42/SO_LONG/Assets/character/char_3.xpm",
        "/mnt/d/42/SO_LONG/Assets/character/char_4.xpm",
        "/mnt/d/42/SO_LONG/Assets/character/char_5.xpm"
    };

    while (i < 6)
    {
        game->player.idle_sprites[i] = mlx_xpm_file_to_image(game->mlx, all_sprites[i], &game->player.player_width, &game->player.player_heigth);
        if (!game->player.idle_sprites[i])
        {
            write(2, "Erro a carregar a imagem", 25);
            exit(1);
        }
        i ++;
    }
}


int animate_idle(game_data *game)
{
    static int frame = 0;   
    static int delay = 0;   // Controle de tempo entre frames

    delay++;
    if (delay > 4000) // 4000 é o tempo entre frames
    {
        mlx_put_image_to_window(game->mlx, game->window, game->player.idle_sprites[frame], game->player.position_x, game->player.position_y);
        frame = (frame + 1) % ANIMATION;
        delay = 0;
    }
    return (0);
}


void    spawn_player(game_data *game)
{
    int i = 0;
    int j = 0;

    while (game->map[i])
    {
        while (game->map[i][j])
        {
            if (game->map[i][j] == 'P')
            {
                game->player.position_x = j * TILE;
                game->player.position_y = i * TILE;
                mlx_put_image_to_window(game->mlx, game->window, game->player.img_player, game->player.position_x, game->player.position_y);
                return ;
            }
            j++;
        }
        j = 0;
        i++;
    }
}


void player_on_tile(game_data *game, int new_x, int new_y)
{
    int left_col = new_x / TILE;                                        // B. esquerdo
    int right_col = (new_x + game->player.player_width - 1) / TILE;     // B. direito
    int top_row = new_y / TILE;                                         // B. topo
    int bottom_row = (new_y + game->player.player_heigth - 1) / TILE;   // B. base

    if (game->map[top_row][left_col] != '1' &&                          // Verifica se qualquer parte do personagem colide com um tile '1'
        game->map[top_row][right_col] != '1' &&
        game->map[bottom_row][left_col] != '1' &&
        game->map[bottom_row][right_col] != '1')
    {
        game->player.position_x = new_x;
        game->player.position_y = new_y;
        mlx_clear_window(game->mlx, game->window);
        draw_map(game);
        mlx_put_image_to_window(game->mlx, game->window, game->player.img_player, game->player.position_x, game->player.position_y);
    }
}

int key_press(int keysym, game_data *game)
{
    int new_x = game->player.position_x;
    int new_y = game->player.position_y;

    if(keysym == 65307)
    {
        clean_up(game);
        exit(0);
    }

    if (keysym == 119)                  // W (cima)
        new_y -= SPEED;  
    else if (keysym == 115)             // S (baixo)
        new_y += SPEED;
    else if (keysym == 97)              // A (esquerda)
        new_x -= SPEED;
    else if (keysym == 100)             // D (direita)
        new_x += SPEED;

    player_on_tile(game, new_x, new_y);

    return (0);
}


int main()
{
    game_data game;

    game.map = map1("Maps/map2.ber");
    game.mlx = mlx_init();
    game.window = mlx_new_window(game.mlx, PIXEL_X, PIXEL_Y, "MY GAME");
    
    put_image_to_player1(&game);
    put_image_to_struct1(&game);
    put_movement_to_player1(&game);
    
    draw_map(&game);
    spawn_player(&game);

    mlx_loop_hook(game.mlx, animate_idle, &game);
    mlx_hook(game.window, KeyPress, KeyPressMask, key_press, &game);
    mlx_loop(game.mlx);
    return (0);
}