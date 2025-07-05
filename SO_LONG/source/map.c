/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:23:19 by seilkiv           #+#    #+#             */
/*   Updated: 2025/07/05 12:51:46 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	draw_borders(t_game_data *game, int x, int y)
{
	if (x == 0 && y == 0)
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures[CORNER_LU], x * TILE, y * TILE);
	else if (x == (game->map_width - 1) && y == 0)
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures[CORNER_RU], x * TILE, y * TILE);
	else if (x == 0 && y == (game->map_height - 1))
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures[CORNER_LD], x * TILE, y * TILE);
	else if (x == (game->map_width - 1) && y == (game->map_height - 1))
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures[CORNER_RD], x * TILE, y * TILE);
}

static void	draw_walls(t_game_data *game, int x, int y)
{
	if (x == 0)
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures[WALL_LEFT], x * TILE, y * TILE);
	else if (x == (game->map_width - 1))
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures[WALL_RIGHT], x * TILE, y * TILE);
	else if (y == 0)
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures[WALL_UP], x * TILE, y * TILE);
	else if (y == (game->map_height - 1))
		mlx_put_image_to_window(game->mlx, game->window, game->textures[FLOOR],
			x * TILE, y * TILE);
}

static void	draw_map2(t_game_data *game, int x, int y)
{
	if ((x == 0 && y == 0) || (x == (game->map_width - 1) && y == 0) || (x == 0
			&& y == (game->map_height - 1)) || (x == (game->map_width - 1)
			&& y == (game->map_height - 1)))
		draw_borders(game, x, y);
	else if (x == 0 || y == 0 || x == (game->map_width - 1)
		|| y == (game->map_height - 1))
		draw_walls(game, x, y);
	else
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures[PLATFORM], x * TILE, y * TILE);
}

void	draw_map(t_game_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == '1')
				draw_map2(game, x, y);
			x++;
		}
		y++;
	}
}
