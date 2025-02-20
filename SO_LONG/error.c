/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 02:32:57 by seilkiv           #+#    #+#             */
/*   Updated: 2025/02/20 03:23:37 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static void player_collectibles_exit(game_data *game, int P, int C, int E)
{
    if(P == 0 || P > 1)
    {
        write(2, "Invalid player", 14);
        free_map(game->map, ROW);
        exit(1);
    }
    if(C == 0)
    {
        write(2, "Invalid collectibles", 20);
        free_map(game->map, ROW);
        exit(1);
    }
    if(E == 0 || E > 1)
    {
        write(2, "Invalid exit", 12);
        free_map(game->map, ROW);
        exit(1);
    }
}

void    is_map_valid(game_data *game)
{
    int i = 0;
    int j;
    int P = 0;
    int C = 0;
    int E = 0;
    
    while(game->map[i])
    {
        j = 0;
        while(game->map[i][j])
        {
            if(i == 0 || i == (ROW - 1) || j == 0 || j == (COLUMN - 1) )
            {
                if(game->map[i][j] != '1')
                {
                    write(2, "Invalid map on borders", 22);
                    free_map(game->map, ROW);
                    exit(1);
                }
            }
            if(game->map[i][j] == 'P')
                P ++;
            if(game->map[i][j] == 'C')
                C ++;
            if(game->map[i][j] == 'E')
                E ++;
            j ++;
        }
        i ++;
    }
    player_collectibles_exit(game, P, C, E);
}
