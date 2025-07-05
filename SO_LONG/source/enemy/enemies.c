/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:22:11 by seilkiv           #+#    #+#             */
/*   Updated: 2025/07/05 12:51:46 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_enemy_animation(t_game_data *game)
{
	int		i;
	char	*all_sprites[ENEMY_ANIM];

	i = 0;
	all_sprites[0] = "Assets/enemy/Fro_Green1.xpm";
	all_sprites[1] = "Assets/enemy/Fro_Green2.xpm";
	while (i < ENEMY_ANIM)
	{
		game->animation.enemy_animation[i] = mlx_xpm_file_to_image(game->mlx,
				all_sprites[i], &game->enemy.width, &game->enemy.heigth);
		if (!game->animation.enemy_animation[i])
		{
			write(2, "Error loading enemy animation", 30);
			exit(1);
		}
		i++;
	}
}

void	enemy_animation(t_game_data *game)
{
	static int	frame = 0;
	static int	delay = 0;

	delay++;
	if (delay > 1500)
	{
		frame = (frame + 1) % ENEMY_ANIM;
		delay = 0;
	}
	mlx_put_image_to_window(game->mlx, game->window,
		game->animation.enemy_animation[frame], game->enemy.position_x + 10,
		game->enemy.position_y + 20);
}

void	spawn_enemy(t_game_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'A')
			{
				game->enemy.position_x = j * TILE;
				game->enemy.position_y = i * TILE;
				enemy_animation(game);
			}
			j++;
		}
		i++;
	}
}

void	player_touching_enemy(t_game_data *game)
{
	if (game->map[game->b.t_row][game->b.l_col] == 'A'
		|| game->map[game->b.t_row][game->b.r_col] == 'A'
		|| game->map[game->b.b_row][game->b.l_col] == 'A'
		|| game->map[game->b.b_row][game->b.r_col] == 'A')
	{
		game->enemy.touching_enemy = 1;
	}
}
