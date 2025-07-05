/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:23:04 by seilkiv           #+#    #+#             */
/*   Updated: 2025/07/05 12:51:46 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_textures_struct(t_game_data *game)
{
	int		i;
	char	*all_textures[TOTAL_TXT];

	all_textures[0] = "Assets/TileSet/WALL_LEFT.xpm";
	all_textures[1] = "Assets/TileSet/WALL_RIGHT.xpm";
	all_textures[2] = "Assets/TileSet/WALL_UP.xpm";
	all_textures[3] = "Assets/TileSet/FLOOR.xpm";
	all_textures[4] = "Assets/TileSet/CORNER_LU.xpm";
	all_textures[5] = "Assets/TileSet/CORNER_LD.xpm";
	all_textures[6] = "Assets/TileSet/CORNER_RU.xpm";
	all_textures[7] = "Assets/TileSet/CORNER_RD.xpm";
	all_textures[8] = "Assets/TileSet/PLATFORM.xpm";
	i = 0;
	while (i < TOTAL_TXT)
	{
		game->textures[i] = mlx_xpm_file_to_image(game->mlx, all_textures[i],
				&game->img_width, &game->img_height);
		if (!game->textures[i])
		{
			write(2, "Erro a carregar a imagem textures", 34);
			exit(1);
		}
		i++;
	}
}

void	put_image_player(t_game_data *game)
{
	game->player.img_player = mlx_xpm_file_to_image(game->mlx,
			"Assets/character/char_0.xpm", &game->player.player_width,
			&game->player.player_heigth);
}

void	put_base_mov_player(t_game_data *game)
{
	int		i;
	char	*all_sprites[BASE_ANIM];

	all_sprites[0] = "Assets/character/char_0.xpm";
	all_sprites[1] = "Assets/character/char_1.xpm";
	all_sprites[2] = "Assets/character/char_2.xpm";
	all_sprites[3] = "Assets/character/char_3.xpm";
	all_sprites[4] = "Assets/character/char_4.xpm";
	all_sprites[5] = "Assets/character/char_5.xpm";
	i = 0;
	while (i < BASE_ANIM)
	{
		game->animation.base_animation[i] = mlx_xpm_file_to_image(game->mlx,
				all_sprites[i], &game->player.player_width,
				&game->player.player_heigth);
		if (!game->animation.base_animation[i])
		{
			write(2, "Erro a carregar a imagem base animation", 40);
			exit(1);
		}
		i++;
	}
}

void	put_base_mov_player_backward(t_game_data *game)
{
	int		i;
	char	*all_sprites[BASE_ANIM];

	all_sprites[0] = "Assets/character/BACK/char_0B.xpm";
	all_sprites[1] = "Assets/character/BACK/char_1B.xpm";
	all_sprites[2] = "Assets/character/BACK/char_2B.xpm";
	all_sprites[3] = "Assets/character/BACK/char_3B.xpm";
	all_sprites[4] = "Assets/character/BACK/char_4B.xpm";
	all_sprites[5] = "Assets/character/BACK/char_5B.xpm";
	i = 0;
	while (i < BASE_ANIM)
	{
		game->animation.base_animation_backward[i] = mlx_xpm_file_to_image(
				game->mlx, all_sprites[i], &game->player.player_width,
				&game->player.player_heigth);
		if (!game->animation.base_animation_backward[i])
		{
			write(2, "Erro a carregar a imagem base animation", 40);
			exit(1);
		}
		i++;
	}
}

void	put_forward_mov_player(t_game_data *game)
{
	int		i;
	char	*all_sprites[FORW_ANIM];

	all_sprites[0] = "Assets/character/char_mov_forward0.xpm";
	all_sprites[1] = "Assets/character/char_mov_forward1.xpm";
	all_sprites[2] = "Assets/character/char_mov_forward2.xpm";
	all_sprites[3] = "Assets/character/char_mov_forward3.xpm";
	all_sprites[4] = "Assets/character/char_mov_forward4.xpm";
	all_sprites[5] = "Assets/character/char_mov_forward5.xpm";
	all_sprites[6] = "Assets/character/char_mov_forward6.xpm";
	all_sprites[7] = "Assets/character/char_mov_forward7.xpm";
	i = 0;
	while (i < FORW_ANIM)
	{
		game->animation.move_forward_anim[i] = mlx_xpm_file_to_image(game->mlx,
				all_sprites[i], &game->player.player_width,
				&game->player.player_heigth);
		if (!game->animation.move_forward_anim[i])
		{
			write(2, "Erro a carregar a imagem forward animation", 43);
			exit(1);
		}
		i++;
	}
}
