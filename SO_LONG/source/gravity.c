#include "../includes/so_long.h"

void apply_gravity(game_data *game)
{
    float new_x = game->player.position_x;
    float new_y = game->player.position_y + GRAVITY;

    if (!player_touching_something(game, new_x, new_y))
    {
        game->player.position_y = new_y;
    }
}

/*void jump(game_data *game)
{
    float max_jump = 85 + game->player.player_heigth;
    float jump_force = 0.5;
    static float jump = 0;
    float new_y;
    float new_x;

    jump += jump_force;
    if (jump <= max_jump)
    {
        new_y = game->player.position_y - jump_force;
        if (game->animation.moving_direction == 1)
            new_x = game->player.position_x - jump_force;
        else if (game->animation.moving_direction == 2)
            new_x = game->player.position_x + jump_force;
        if (!player_touching_something(game, game->player.position_x, new_y))
        {
            game->player.position_y = new_y;
            game->player.position_x = new_x;
            mlx_put_image_to_window(game->mlx, game->window, game->player.img_player, game->player.position_x, game->player.position_y);
        }
    }
    else
    {
        jump = 0; // Reseta o salto ao atingir a altura máxima
        game->player.is_jumping = false;
    }

    if (player_touching_something(game, game->player.position_x, game->player.position_y))
    {
        jump = 0;
        game->player.is_jumping = false;
    }
}*/