/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:37:05 by seilkiv           #+#    #+#             */
/*   Updated: 2025/07/05 12:51:46 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_backward_mov_player(t_game_data *game)
{
	int		i;
	char	*all_sprites[FORW_ANIM];

	all_sprites[0] = "Assets/character/BACK/char_mov_forward0B.xpm";
	all_sprites[1] = "Assets/character/BACK/char_mov_forward1B.xpm";
	all_sprites[2] = "Assets/character/BACK/char_mov_forward2B.xpm";
	all_sprites[3] = "Assets/character/BACK/char_mov_forward3B.xpm";
	all_sprites[4] = "Assets/character/BACK/char_mov_forward4B.xpm";
	all_sprites[5] = "Assets/character/BACK/char_mov_forward5B.xpm";
	all_sprites[6] = "Assets/character/BACK/char_mov_forward6B.xpm";
	all_sprites[7] = "Assets/character/BACK/char_mov_forward7B.xpm";
	i = 0;
	while (i < FORW_ANIM)
	{
		game->animation.move_backward_anim[i] = mlx_xpm_file_to_image(game->mlx,
				all_sprites[i], &game->player.player_width,
				&game->player.player_heigth);
		if (!game->animation.move_backward_anim[i])
		{
			write(2, "Erro a carregar a imagem backward animation", 44);
			exit(1);
		}
		i++;
	}
}

void	put_animation_collectible(t_game_data *game)
{
	int		i;
	char	*all_sprites[COLLEC_ANIM];

	all_sprites[0] = "Assets/collectible/coin.xpm";
	all_sprites[1] = "Assets/collectible/coin_2.xpm";
	all_sprites[2] = "Assets/collectible/coin_3.xpm";
	all_sprites[3] = "Assets/collectible/coin_4.xpm";
	all_sprites[4] = "Assets/collectible/coin_5.xpm";
	all_sprites[5] = "Assets/collectible/coin_6.xpm";
	i = 0;
	while (i < COLLEC_ANIM)
	{
		game->animation.collect_animation[i] = mlx_xpm_file_to_image(game->mlx,
				all_sprites[i], &game->collectible.width,
				&game->collectible.heigth);
		if (!game->animation.collect_animation[i])
		{
			write(2, "Erro a carregar a imagem collectible animation", 47);
			exit(1);
		}
		i++;
	}
}

void	put_img_exit(t_game_data *game)
{
	game->exit.img_exit = mlx_xpm_file_to_image(game->mlx,
			"Assets/exit/shop.xpm", &game->exit.width, &game->exit.heigth);
	if (!game->exit.img_exit)
	{
		write(2, "Erro a carregar a imagem exit", 30);
		exit(1);
	}
}
