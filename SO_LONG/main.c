/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:05:53 by seilkiv           #+#    #+#             */
/*   Updated: 2025/02/11 21:34:48 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>

#define HEIGHT 500
#define WIDTH 500

typedef struct s_data {
    void    *mlx;
    void    *win;
    void    *img;
    int     img_width;
    int     img_height;
} t_data;

int key_press(int keycode, t_data *data)
{
    if (keycode == 65307)
    {
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    return (0);
}

int main()
{
    t_data  data;

    
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Exibir XPM");

    // Carregar a imagem .xpm
    data.img = mlx_xpm_file_to_image(data.mlx, "WALL.xpm", &data.img_width, &data.img_height);
    if (!data.img)
    {
        write(2, "Erro ao carregar a imagem\n", 26);
        exit(1);
    }

    mlx_put_image_to_window(data.mlx, data.win, data.img, 100, 100);

    mlx_key_hook(data.win, key_press, &data);

    mlx_loop(data.mlx);

    return (0);
}
