/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HUD.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 23:58:20 by seilkiv           #+#    #+#             */
/*   Updated: 2025/02/20 01:26:13 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void    HUD(game_data *game)
{
    char *moves = ft_itoa(game->player.count_moves);
    mlx_string_put(game->mlx, game->window, 10, 10, 0xFFFFFF, "Moves: ");
    mlx_string_put(game->mlx, game->window, 50, 10, 0xFFFFFF, moves);
    
    free(moves);
}