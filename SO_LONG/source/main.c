/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:23:12 by seilkiv           #+#    #+#             */
/*   Updated: 2025/07/05 13:18:26 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(t_game_data *game)
{
	free_all(game);
	exit(0);
	return (0);
}

static void	initiation(t_game_data *game)
{
	game->animation.moving = 0;
	game->collectible.all_collectible = 0;
	game->player.count_moves = 0;
	game->animation.moving_direction = 2;
	game->enemy.touching_enemy = 0;
	game->gravity = 1;
	put_textures_struct(game);
	put_image_player(game);
	put_base_mov_player(game);
	put_base_mov_player_backward(game);
	put_forward_mov_player(game);
	put_backward_mov_player(game);
	put_animation_collectible(game);
	put_enemy_animation(game);
	put_img_exit(game);
	draw_map(game);
	spawn_player(game);
	spawn_collectibles(game, 1);
	spawn_exit(game);
	spawn_enemy(game);
	hud(game);
}

int	main(int argc, char **argv)
{
	t_game_data	game;
	if (argc != 2)
	{
		write(2, "Uso: ./so_long <mapa.ber>\n", 27);
		return (1);
	}
	get_map_size(argv[1], &game);
	game.map = map(argv[1], &game);
	is_map_valid(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		write(2, "Erro ao iniciar a Minilibx\n", 27);
		exit(1);
	}
	game.window = mlx_new_window(game.mlx, (game.map_width * TILE),
			(game.map_height * TILE), "MY GAME");
	initiation(&game);
	mlx_hook(game.window, 17, 0, close_window, &game);
	mlx_hook(game.window, 2, 1, key_press, &game);
	mlx_hook(game.window, 3, 2, key_release, &game);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_loop(game.mlx);
	return (0);
}

