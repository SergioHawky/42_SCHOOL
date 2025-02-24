/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:16:14 by seilkiv           #+#    #+#             */
/*   Updated: 2025/02/20 01:28:31 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    player_can_exit(game_data *game)
{
    if(game->collectible.all_collectible == 0 && game->exit.touching_exit == 1)
    {
        printf(" GG \n");
        free_all(game);
        exit(0);
    }
}