/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:22:19 by seilkiv           #+#    #+#             */
/*   Updated: 2025/07/05 12:51:46 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	base_animation(t_game_data *game)
{
	static int	frame = 0;
	static int	delay = 0;

	delay++;
	if (delay > 100)
	{
		frame = (frame + 1) % BASE_ANIM;
		delay = 0;
	}
	mlx_put_image_to_window(game->mlx, game->window,
		game->animation.base_animation[frame], game->player.position_x,
		game->player.position_y);
}

void	base_animation_backward(t_game_data *game)
{
	static int	frame = 0;
	static int	delay = 0;

	delay++;
	if (delay > 100)
	{
		frame = (frame + 1) % BASE_ANIM;
		delay = 0;
	}
	mlx_put_image_to_window(game->mlx, game->window,
		game->animation.base_animation_backward[frame], game->player.position_x,
		game->player.position_y);
}

void	move_forward_animation(t_game_data *game)
{
	static int	frame = 0;
	static int	delay = 0;

	delay++;
	if (delay > 100)
	{
		frame = (frame + 1) % FORW_ANIM;
		delay = 0;
	}
	mlx_put_image_to_window(game->mlx, game->window,
		game->animation.move_forward_anim[frame], game->player.position_x,
		game->player.position_y);
}

void	move_backward_animation(t_game_data *game)
{
	static int	frame = 0;
	static int	delay = 0;

	delay++;
	if (delay > 100)
	{
		frame = (frame + 1) % FORW_ANIM;
		delay = 0;
	}
	mlx_put_image_to_window(game->mlx, game->window,
		game->animation.move_backward_anim[frame], game->player.position_x,
		game->player.position_y);
}

void	collectible_animation(t_game_data *game)
{
	static int	frame = 0;
	static int	delay = 0;

	delay++;
	if (delay > 500)
	{
		frame = (frame + 1) % COLLEC_ANIM;
		delay = 0;
	}
	mlx_put_image_to_window(game->mlx, game->window,
		game->animation.collect_animation[frame],
		game->collectible.position_x, game->collectible.position_y + 17);
}
