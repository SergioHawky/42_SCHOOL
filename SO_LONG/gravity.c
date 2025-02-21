#include "includes/so_long.h"

void apply_gravity(game_data *game)
{
    //static float gravity_force = 0.01; 
    //static float max_fall_speed = 0.1;

    //if (game->player.gravity_velocity == 0) // iniciar a variavel
    game->player.gravity_velocity = 0.1;

    float new_x = game->player.position_x;
    float new_y = game->player.position_y + game->player.gravity_velocity - 0.015;

    // Aumenta gradualmente a velocidade da queda, mas limita a um valor máximo
    //if (game->player.gravity_velocity < max_fall_speed)
    //    game->player.gravity_velocity += gravity_force;

    if (!player_touching_tile(game, new_x, new_y))
    {
        game->player.position_y = new_y;
    }
    /*else
    {
        game->player.gravity_velocity = 0.0;
    }*/
}
