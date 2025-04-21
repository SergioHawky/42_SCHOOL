/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 02:32:57 by seilkiv           #+#    #+#             */
/*   Updated: 2025/02/20 06:16:34 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void player_collectibles_exit(game_data *game, int P, int C, int E)
{
    if(P == 0 || P > 1)
    {
        write(2, "Invalid player", 14);
        free_map(game);
        exit(1);
    }
    if(C == 0)
    {
        write(2, "Invalid collectibles", 20);
        free_map(game);
        exit(1);
    }
    if(E == 0 || E > 1)
    {
        write(2, "Invalid exit", 12);
        free_map(game);
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
            if (game->map[i][j] == '0' || game->map[i][j] == '1' || game->map[i][j] == 'A'
                || game->map[i][j] == 'E' || game->map[i][j] == 'P' || game->map[i][j] == 'C')
            {
                if(i == 0 || i == (game->map_height - 1) || j == 0 || j == (game->map_width - 1) )
                {
                    if(game->map[i][j] != '1' ||game->map[i][j] == '\0')
                    {
                        write(2, "Invalid map on borders", 22);
                        free_map(game);
                        exit(1);
                    }
                }
                if(game->map[i][j] == 'P')
                    P ++;
                if(game->map[i][j] == 'C')
                    C ++;
                if(game->map[i][j] == 'E')
                    E ++;
            }
            else
            {
                write(2, "Invalid characters", 19);
                free_map(game);
                exit(1);
            }
            j ++;
        }
        i ++;
    }
    player_collectibles_exit(game, P, C, E);
}

void    minimum_map_size(game_data *game)
{
    if(game->map_height < 3 || game->map_width < 3 || (game->map_width * game->map_height) < 15)
    {
        write(2, "Map does not have the minimum requirements", 42);
        exit(1);
    }
}
