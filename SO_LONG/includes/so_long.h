/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:21:28 by seilkiv           #+#    #+#             */
/*   Updated: 2025/07/05 12:51:46 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h" //mlx
# include "libft.h"
//#include <X11/X.h>                        //keysym
# include <fcntl.h> //open e read
# include <stdbool.h>
# include <string.h>
# include <unistd.h> //write

# define TILE 40

# define SPEED 6

# define GRAVITY 0.25

# define TOTAL_TXT 9

# define BASE_ANIM 6
# define FORW_ANIM 8
# define COLLEC_ANIM 6
# define ENEMY_ANIM 2

# define PIXEL_X (game->map_width * TILE)
# define PIXEL_Y (game->map_height * TILE)

typedef enum e_texture
{
	WALL_LEFT,
	WALL_RIGHT,
	WALL_UP,
	FLOOR,
	CORNER_LU,
	CORNER_LD,
	CORNER_RU,
	CORNER_RD,
	PLATFORM
}						t_texture;

typedef struct en_data // enemy
{
	int	width;
	int	heigth;
	int	position_x;
	int	position_y;
	int	touching_enemy;
}						t_enemy_data;

typedef struct p_data // player
{
	void	*img_player;
	int		player_width;
	int		player_heigth;
	float	position_x;
	float	position_y;
	int		count_moves;
	int		how_many_players;
}						t_player_data;

typedef struct b_data
{
	int					l_col;
	int					r_col;
	int					t_row;
	int					b_row;
}						t_border_data;

typedef struct a_data // animation
{
	int		moving;
	int		moving_direction;
	void	*base_animation[BASE_ANIM];
	void	*move_forward_anim[FORW_ANIM];
	void	*move_backward_anim[FORW_ANIM];
	void	*base_animation_backward[BASE_ANIM];
	void	*collect_animation[COLLEC_ANIM];
	void	*enemy_animation[ENEMY_ANIM];
}						t_animation_data;

typedef struct c_data // collectible
{
	int	width;
	int	heigth;
	int	position_x;
	int	position_y;
	int	all_collectible;
	int	how_many_collect;
}						t_collectible_data;

typedef struct e_data // exit
{
	void	*img_exit;
	int		width;
	int		heigth;
	int		position_x;
	int		position_y;
	int		touching_exit;
	int		how_many_exit;
}					t_exit_data;

typedef struct s_data
{
	void				*mlx;
	void				*window;
	void				*textures[TOTAL_TXT];
	char				**map;
	int					map_height;
	int					map_width;
	int					img_width;
	int					img_height;
	bool				gravity;
	t_player_data		player;
	t_animation_data	animation;
	t_collectible_data	collectible;
	t_exit_data			exit;
	t_enemy_data		enemy;
	t_border_data		b;
	int					game_over;
}						t_game_data;

char					**map(char *Map_Name, t_game_data *game);
void					draw_map(t_game_data *game);
int						key_press(int keysym, t_game_data *game);
int						key_release(int keysym, t_game_data *game);
void					spawn_player(t_game_data *game);
void					spawn_collectibles(t_game_data *game, int first_time);
void					spawn_exit(t_game_data *game);
void					spawn_enemy(t_game_data *game);
void					base_animation(t_game_data *game);
void					base_animation_backward(t_game_data *game);
void					move_forward_animation(t_game_data *game);
void					move_backward_animation(t_game_data *game);
void					collectible_animation(t_game_data *game);
void					free_map(t_game_data *game);
void					free_images(t_game_data *game);
void					free_all(t_game_data *game);
void					put_forward_mov_player(t_game_data *game);
void					put_backward_mov_player(t_game_data *game);
void					put_textures_struct(t_game_data *game);
void					put_image_player(t_game_data *game);
void					put_base_mov_player(t_game_data *game);
void					put_base_mov_player_backward(t_game_data *game);
void					put_animation_collectible(t_game_data *game);
void					put_enemy_animation(t_game_data *game);
void					put_img_exit(t_game_data *game);
int						update(t_game_data *game);
int						player_touching_something(t_game_data *game, int x,
							int y);
void					player_can_exit(t_game_data *game);
void					hud(t_game_data *game);
void					is_map_valid(t_game_data *game);
void					get_map_size(char *Map_Name, t_game_data *game);
void					minimum_map_size(t_game_data *game);
void					player_touching_enemy(t_game_data *game);
int						game_over(t_game_data *game);

void					apply_gravity(t_game_data *game);
int						close_window(t_game_data *game);

#endif