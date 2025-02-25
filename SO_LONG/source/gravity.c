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

void jump(game_data *game)
{
    int max_jump = 2;

    if (!player_touching_something(game, game->player.position_x, game->player.position_y - max_jump))
    {
        game->player.position_y -= max_jump;
    }
}