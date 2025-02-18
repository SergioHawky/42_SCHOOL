#include "includes/so_long.h"

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