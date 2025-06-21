/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_border.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:31:05 by seilkiv           #+#    #+#             */
/*   Updated: 2025/02/19 21:31:22 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void player_touching_collectible(game_data *game, int left_col, int right_col, int top_row, int bottom_row)
{
    if(game->map[top_row][left_col] == 'C')
    { 
        game->map[top_row][left_col] = '0';
        game->collectible.all_collectible --;
    }
    else if(game->map[top_row][right_col] == 'C')
    {
        game->map[top_row][right_col] = '0';
        game->collectible.all_collectible --;
    }
    else if(game->map[bottom_row][left_col] == 'C')
    {
        game->map[bottom_row][left_col] = '0';
        game->collectible.all_collectible --;
    }
    else if(game->map[bottom_row][right_col] == 'C')
    { 
        game->map[bottom_row][right_col] = '0';
        game->collectible.all_collectible --;
    }
}

void player_touching_exit(game_data *game, int left_col, int right_col, int top_row, int bottom_row)
{
    if (game->map[top_row][left_col] == 'E')
    { 
        game->exit.touching_exit = 1;
    }
    else if(game->map[top_row][right_col] == 'E')
    {
        game->exit.touching_exit = 1;
    }
    else if(game->map[bottom_row][left_col] == 'E')
    {
        game->exit.touching_exit = 1;
    }
    else if(game->map[bottom_row][right_col] == 'E')
    { 
        game->exit.touching_exit = 1;
    }
    else
        game->exit.touching_exit = 0;
}

int player_touching_something(game_data *game, int x, int y)
{
    int left_col = x / TILE;
    int right_col = (x + game->player.player_width) / TILE;
    int top_row = y / TILE;
    int bottom_row = (y + game->player.player_heigth) / TILE;

    player_touching_collectible(game, left_col, right_col, top_row, bottom_row);
    player_touching_exit(game, left_col, right_col, top_row, bottom_row);
    player_touching_enemy(game, left_col, right_col, top_row, bottom_row);
    if (game->map[top_row][left_col] != '1' && game->map[top_row][right_col] != '1' &&        // Verifica se qualquer parte do personagem colide com um tile
        game->map[bottom_row][left_col] != '1' && game->map[bottom_row][right_col] != '1')
    {
        return (0);
    }
    return (1);
}