/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gravity.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:22:50 by seilkiv           #+#    #+#             */
/*   Updated: 2025/07/05 12:51:46 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	apply_gravity(t_game_data *game)
{
	float	new_x;
	float	new_y;

	new_x = game->player.position_x;
	new_y = game->player.position_y + GRAVITY;
	if (!player_touching_something(game, new_x, new_y))
	{
		game->player.position_y = new_y;
	}
}
