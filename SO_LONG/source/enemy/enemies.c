#include "../includes/so_long.h"

void put_enemy_animation(game_data *game)
{
    int i = 0;

    char *all_sprites[ENEMY_ANIM] = {
        "../Assets/enemy/Fro_Green1.xpm",
        "../Assets/enemy/Fro_Green2.xpm",
    };

    while (i < ENEMY_ANIM)
    {
        game->animation.enemy_animation[i] = mlx_xpm_file_to_image(game->mlx, all_sprites[i], &game->enemy.width, &game->enemy.heigth);
        if (!game->animation.enemy_animation[i])
        {
            write(2, "Error loading enemy animation", 30);
            exit(1);
        }
        i ++;
    }
}

void    enemy_animation(game_data *game)
{
    static int frame = 0;
    static int delay = 0;
      
    delay++;
    if (delay > 1500)
    {
        frame = (frame + 1) % ENEMY_ANIM;
        delay = 0;
    }
    mlx_put_image_to_window(game->mlx, game->window, game->animation.enemy_animation[frame], game->enemy.position_x + 10, game->enemy.position_y +20);
}

void    spawn_enemy(game_data *game)
{
    int i;
    int j;

    i = 0;
    while (i < game->map_height)
    {
        j = 0;
        while (j < game->map_width)
        {
            if (game->map[i][j] == 'A')
            {
                game->enemy.position_x = j * TILE;
                game->enemy.position_y = i * TILE;
                enemy_animation(game);
            }
            j++;
        }
        i++;
    }
}

void    player_touching_enemy(game_data *game, int left_col, int right_col, int top_row, int bottom_row)
{
    if(game->map[top_row][left_col] == 'A')
    { 
        free_all(game);
        exit(0);
    }
    else if(game->map[top_row][right_col] == 'A')
    {
        free_all(game);
        exit(0);
    }
    else if(game->map[bottom_row][left_col] == 'A')
    {
        free_all(game);
        exit(0);
    }
    else if(game->map[bottom_row][right_col] == 'A')
    { 
        free_all(game);
        exit(0);
    }
}