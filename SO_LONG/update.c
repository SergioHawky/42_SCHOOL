#include "includes/so_long.h"

void    update(game_data *game)
{
    mlx_clear_window(game->mlx, game->window);
    draw_map(game);
    spawn_collectibles(game);
    spawn_exit(game);
    mlx_put_image_to_window(game->mlx, game->window, game->player.img_player, game->player.position_x, game->player.position_y);
}