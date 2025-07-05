/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:23:25 by seilkiv           #+#    #+#             */
/*   Updated: 2025/07/05 12:51:46 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static float	buttons1(int keysym, t_game_data *game)
{
	float	new_x;

	new_x = game->player.position_x;
	if (keysym == 65307)
	{
		free_all(game);
		exit(0);
	}
	else if (keysym == 97)
	{
		new_x -= SPEED;
		game->animation.moving = 1;
		game->animation.moving_direction = 1;
	}
	else if (keysym == 100)
	{
		new_x += SPEED;
		game->animation.moving = 1;
		game->animation.moving_direction = 2;
	}
	return (new_x);
}

static float	buttons2(int keysym, t_game_data *game)
{
	float	new_y;

	new_y = game->player.position_y;
	if (keysym == 119)
	{
		new_y -= SPEED;
		if (game->gravity == 0)
			game->animation.moving = 1;
	}
	else if (keysym == 115)
	{
		new_y += SPEED;
		if (game->gravity == 0)
			game->animation.moving = 1;
	}
	else if (keysym == 103)
	{
		game->animation.moving = 0;
		if (game->gravity == 0)
			game->gravity = 1;
		else
			game->gravity = 0;
	}
	return (new_y);
}

void	player(t_game_data *game, int new_x, int new_y)
{
	if (!player_touching_something(game, new_x, new_y))
	{
		game->player.position_x = new_x;
		game->player.position_y = new_y;
		if (game->animation.moving == 1)
		{
			game->player.count_moves++;
		}
	}
}

int	key_press(int keysym, t_game_data *game)
{
	float	new_x;
	float	new_y;

	new_x = buttons1(keysym, game);
	new_y = buttons2(keysym, game);
	player(game, new_x, new_y);
	return (0);
}

int	key_release(int keysym, t_game_data *game)
{
	if (keysym == 100 || keysym == 97)
	{
		game->animation.moving = 0;
	}
	return (0);
}
