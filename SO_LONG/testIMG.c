#include "includes/so_long.h"

void    free_images(game_data *game)
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
    while (i < BASE_ANIM)
    {
        if (game->animation.base_animation[i])
            mlx_destroy_image(game->mlx, game->animation.base_animation[i]);
        i++;
    }
    i = 0;
    while (i < FORW_ANIM)
    {
        if (game->animation.move_forward_anim[i])
            mlx_destroy_image(game->mlx, game->animation.move_forward_anim[i]);
        i++;
    }
    
    if (game->player.img_player)
        mlx_destroy_image(game->mlx, game->player.img_player);
    
    if (game->collectible.img_collectible)
        mlx_destroy_image(game->mlx, game->collectible.img_collectible);
    
    if (game->exit.img_exit)
        mlx_destroy_image(game->mlx, game->exit.img_exit);
}

void free_map(char **map, int row) 
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

void free_all(game_data *game)
{
    free_images(game);
    free_map(game->map, ROW);
    mlx_destroy_window(game->mlx, game->window);
    mlx_destroy_display(game->mlx);
    free(game->mlx);
    exit(0);
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
        map[i] = strdup(buffer);  // lib
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

void    put_textures_struct(game_data *game)
{
    int i = 0;

    char *all_textures[TOTAL_TXT] = {
        "Assets/TileSet/WALL_LEFT.xpm",
        "Assets/TileSet/WALL_RIGHT.xpm",
        "Assets/TileSet/WALL_UP.xpm",
        "Assets/TileSet/FLOOR.xpm",
        "Assets/TileSet/CORNER_LU.xpm",
        "Assets/TileSet/CORNER_LD.xpm",
        "Assets/TileSet/CORNER_RU.xpm",
        "Assets/TileSet/CORNER_RD.xpm",
        "Assets/TileSet/PLATFORM.xpm"
    };

    while (i < TOTAL_TXT)
    {
        game->textures[i] = mlx_xpm_file_to_image(game->mlx, all_textures[i], &game->img_width, &game->img_height);
        if (!game->textures[i])
        {
            write(2, "Erro a carregar a imagem textures", 34);
            exit(1);
        }
        i ++;
    }
    
}

void    put_image_player(game_data *game)
{
    game->player.img_player = mlx_xpm_file_to_image(game->mlx, "Assets/character/char_0.xpm", &game->player.player_width, &game->player.player_heigth);
}

void    put_base_mov_player(game_data *game)
{
    int i = 0;

    char *all_sprites[BASE_ANIM] = {
        "Assets/character/char_0.xpm",
        "Assets/character/char_1.xpm",
        "Assets/character/char_2.xpm",
        "Assets/character/char_3.xpm",
        "Assets/character/char_4.xpm",
        "Assets/character/char_5.xpm"
    };

    while (i < BASE_ANIM)
    {
        game->animation.base_animation[i] = mlx_xpm_file_to_image(game->mlx, all_sprites[i], &game->player.player_width, &game->player.player_heigth);
        if (!game->animation.base_animation[i])
        {
            write(2, "Erro a carregar a imagem base animation", 40);
            exit(1);
        }
        i ++;
    }
}

void    put_forward_mov_player(game_data *game)
{
    int i = 0;

    char *all_sprites[FORW_ANIM] = {
        "Assets/character/char_mov_forward0.xpm",
        "Assets/character/char_mov_forward1.xpm",
        "Assets/character/char_mov_forward2.xpm",
        "Assets/character/char_mov_forward3.xpm",
        "Assets/character/char_mov_forward4.xpm",
        "Assets/character/char_mov_forward5.xpm",
        "Assets/character/char_mov_forward6.xpm",
        "Assets/character/char_mov_forward7.xpm"
    };

    while (i < FORW_ANIM)
    {
        game->animation.move_forward_anim[i] = mlx_xpm_file_to_image(game->mlx, all_sprites[i], &game->player.player_width, &game->player.player_heigth);
        if (!game->animation.move_forward_anim[i])
        {
            write(2, "Erro a carregar a imagem forward animation", 43);
            exit(1);
        }
        i ++;
    }
}

void    put_img_collectible(game_data *game)
{
    game->collectible.img_collectible = mlx_xpm_file_to_image(game->mlx, "Assets/collectible/coin.xpm", &game->collectible.width, &game->collectible.heigth);
    if(!game->collectible.img_collectible)
    {
        write(2, "Erro a carregar a imagem collectible", 37);
        exit(1);
    }
}

void    put_img_exit(game_data *game)
{
    game->exit.img_exit = mlx_xpm_file_to_image(game->mlx, "Assets/exit/shop.xpm", &game->exit.width, &game->exit.heigth);
    if(!game->exit.img_exit)
    {
        write(2, "Erro a carregar a imagem exit", 30);
        exit(1);
    }
}


int base_animation(game_data *game)
{
    static int frame = 0;
    static int delay = 0;

    delay++;
    if (delay > 10000)
    {
        frame = (frame + 1) % BASE_ANIM;
        mlx_put_image_to_window(game->mlx, game->window, game->animation.base_animation[frame], game->player.position_x, game->player.position_y);
        delay = 0;
    }
    return (0);
}

int move_forward_animation(game_data *game)
{
    static int frame1 = 0;
    static int delay1 = 0;
    
    if(!game->animation.moving)
        return (0);
        
    delay1++;
    if (delay1 > 10000)
    {
        frame1 = (frame1 + 1) % FORW_ANIM;
        mlx_put_image_to_window(game->mlx, game->window, game->animation.move_forward_anim[frame1], game->player.position_x, game->player.position_y);
        delay1 = 0;
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
                mlx_put_image_to_window(game->mlx, game->window, game->player.img_player, game->player.position_x, game->player.position_y += 5);
                return ;
            }
            j++;
        }
        j = 0;
        i++;
    }
}

void    spawn_collectibles(game_data *game)
{
    int i = 0;
    int j = 0;

    while (game->map[i])
    {
        while (game->map[i][j])
        {
            if (game->map[i][j] == 'C')
            {
                game->collectible.position_x = j * TILE;
                game->collectible.position_y = i * TILE;
                mlx_put_image_to_window(game->mlx, game->window, game->collectible.img_collectible, game->collectible.position_x + 15, game->collectible.position_y + 15);
            }
            j++;
        }
        j = 0;
        i++;
    }
}

void    spawn_exit(game_data *game)
{
    int i = 0;
    int j = 0;

    while (game->map[i])
    {
        while (game->map[i][j])
        {
            if (game->map[i][j] == 'E')
            {
                game->exit.position_x = j * TILE;
                game->exit.position_y = i * TILE;
                mlx_put_image_to_window(game->mlx, game->window, game->exit.img_exit, game->exit.position_x, game->exit.position_y);
            }
            j++;
        }
        j = 0;
        i++;
    }
}


void player_touching_collectible(game_data *game, int left_col, int right_col, int top_row, int bottom_row)
{
    if (game->map[top_row][left_col] == 'C') 
        game->map[top_row][left_col] = '0';
    if (game->map[top_row][right_col] == 'C') 
        game->map[top_row][right_col] = '0';
    if (game->map[bottom_row][left_col] == 'C') 
         game->map[bottom_row][left_col] = '0';
    if (game->map[bottom_row][right_col] == 'C') 
        game->map[bottom_row][right_col] = '0';
}

int player_touching_tile(game_data *game, int x, int y)
{
    int left_col = x / TILE;
    int right_col = (x + game->player.player_width) / TILE;
    int top_row = y / TILE;
    int bottom_row = (y + game->player.player_heigth) / TILE;

    player_touching_collectible(game, left_col, right_col, top_row, bottom_row);
    if (game->map[top_row][left_col] != '1' && game->map[top_row][right_col] != '1' &&        // Verifica se qualquer parte do personagem colide com um tile
        game->map[bottom_row][left_col] != '1' && game->map[bottom_row][right_col] != '1')
    {
        return (0);
    }
    return (1);
}


void    update(game_data *game)
{
    mlx_clear_window(game->mlx, game->window);
    draw_map(game);
    spawn_collectibles(game);
    spawn_exit(game);
    if (game->animation.moving)
    {
        move_forward_animation(game);
    }
    else
    {
        mlx_put_image_to_window(game->mlx, game->window, game->player.img_player, game->player.position_x, game->player.position_y);
    }
}


void player(game_data *game, int new_x, int new_y)
{
    if (!player_touching_tile(game, new_x, new_y))
    {
        game->player.position_x = new_x;
        game->player.position_y = new_y;
        update(game);
    }
}

int key_press(int keysym, game_data *game)
{
    int new_x = game->player.position_x;
    int new_y = game->player.position_y;

    if(keysym == 65307)
    {
        free_all(game);
        exit(0);
    }

    if (keysym == 119)                  // W (cima)
        new_y -= SPEED;  
    else if (keysym == 115)             // S (baixo)
        new_y += SPEED;
    else if (keysym == 97)              // A (esquerda)
    {
        new_x -= SPEED;
        game->animation.moving = 1;
        game->animation.moving_direction = 2; // Direção esquerda
    }
    else if (keysym == 100)             // D (direita)
    {
        new_x += SPEED;
        game->animation.moving = 1;
        game->animation.moving_direction = 1;
    }
    player(game, new_x, new_y);

    return (0);
}

int key_release(int keysym, game_data *game)
{
    if (keysym == 97 || keysym == 100)
    {
        game->animation.moving = 0;
        game->animation.moving_direction = 0;
        mlx_loop_hook(game->mlx, base_animation, game);
    }
    return (0);
}


int main()
{
    game_data game;
    
    game.map = map("Maps/map2.ber");
    game.mlx = mlx_init();
    game.window = mlx_new_window(game.mlx, PIXEL_X, PIXEL_Y, "MY GAME");
    game.animation.moving = 0;
    game.animation.moving_direction = 0;
    
    //game.img = mlx_xpm_file_to_image(game.mlx, "/home/seilkiv/42_School/SO_LONG/Assets/TileSet/WALL.xpm", &game.img_width, &game.img_height);
    put_textures_struct(&game);
    put_image_player(&game);
    put_base_mov_player(&game);
    put_forward_mov_player(&game);
    put_img_collectible(&game);
    put_img_exit(&game);
    
    draw_map(&game);
    spawn_player(&game);
    spawn_collectibles(&game);
    spawn_exit(&game);

    mlx_hook(game.window, KeyPress, KeyPressMask, key_press, &game);
    mlx_hook(game.window, KeyRelease, KeyReleaseMask, key_release, &game);
    mlx_loop(game.mlx);
    return(0);
}