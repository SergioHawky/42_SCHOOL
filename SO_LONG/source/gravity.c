#include "../includes/so_long.h"

void player_jump(game_data *game)
{
    if (!game->player.is_jumping) // Só pode pular se estiver no chão
    {
        game->player.gravity_velocity = -1.0; // Força inicial do salto (valor negativo sobe)
        game->player.is_jumping = 1; // Define que está no ar
    }
}

void apply_gravity(game_data *game)
{
    static float gravity_force = 0.01; 
    static float max_fall_speed = 0.1;
    float jump_speed = 5.0;

    if (game->player.gravity_velocity == 0) // iniciar a variavel
        game->player.gravity_velocity = 0.1;

    float new_x = game->player.position_x;
    float new_y = game->player.position_y + game->player.gravity_velocity - 0.015;
    
    if (game->player.is_jumping)
    {
        if (game->animation.moving_direction == 1) // Pulando para a esquerda
            new_x -= jump_speed;
        else if (game->animation.moving_direction == 2) // Pulando para a direita
            new_x += jump_speed; 
    }

    // Aumenta gradualmente a velocidade da queda, mas limita a um valor máximo
    if (game->player.gravity_velocity < max_fall_speed)
        game->player.gravity_velocity += gravity_force;

    if (!player_touching_something(game, new_x, new_y))
    {
        game->player.position_y = new_y;
    }
    else
    {
        game->player.gravity_velocity = 0.0;
        game->player.is_jumping = 0; // Quando toca no chão, pode pular novamente
    }
}
