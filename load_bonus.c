/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:44:15 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/03/27 18:03:37 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void    load_enemy(t_bgame *bgame)
{
    load_imgs(&bgame->game);
    bgame->enemy[0].img = mlx_xpm_file_to_image(bgame->game.mlx, "tiles/enemy_2.xpm", &bgame->enemy[0].width, &bgame->enemy[0].height);
    check_img(bgame->enemy[0].img, &bgame->game);
    bgame->enemy[1].img = mlx_xpm_file_to_image(bgame->game.mlx, "tiles/enemy_2.xpm", &bgame->enemy[1].width, &bgame->enemy[1].height);
    check_img(bgame->enemy[1].img, &bgame->game);
    bgame->enemy[2].img = mlx_xpm_file_to_image(bgame->game.mlx, "tiles/enemy_3.xpm", &bgame->enemy[2].width, &bgame->enemy[2].height);
    check_img(bgame->enemy[2].img, &bgame->game);
}




int animate_enemy(t_bgame *bgame)
{
    static int frame_counter = 0;

    if (frame_counter++ < 1000) // Adjust speed (lower = faster animation)
        return (0);
    frame_counter = 0;

    bgame->enemy_frame = (bgame->enemy_frame + 1) % 3; // Cycle frames 0 → 1 → 2 → 0

    fill_map_b(bgame); // Refresh the entire map (including the enemy)

    return (0);
}



void fill_enemy(t_bgame *bgame, int i, int j)
{
    if (bgame->game.area->map[i][j] == 'S') // 'S' represents the enemy
        mlx_put_image_to_window(bgame->game.mlx, bgame->game.win, 
            bgame->enemy[bgame->enemy_frame].img, j * 70, i * 70);
}


void	fill_bg_bonus(t_bgame *bgame)
{
	int	i;
	int	j;

	if (!bgame->game.imgs.space.img)
	{
		free(&bgame->game);
		print_message("Error\nCan't load background image.\n");
	}
	i = 0;
	while (i < bgame->game.area->height)
	{
		j = 0;
		while (j < bgame->game.area->width)
		{
			mlx_put_image_to_window(bgame->game.mlx, bgame->game.win,
				bgame->game.imgs.space.img, j * 70, i * 70);
			fill_sides(&bgame->game, i, j);
			j++;
		}
		i++;
	}
}

void	fill_map_b(t_bgame *bgame)
{
	int	i;
	int	j;

	fill_bg_bonus(bgame);
	fill_corners(&bgame->game);
	i = 1;
	while (i < bgame->game.area->height - 1)
	{
		j = 1;
		while (j < bgame->game.area->width - 1)
		{
			if (bgame->game.area->map[i][j] == '0')
				fill_space(&bgame->game, i, j);
			else if (bgame->game.area->map[i][j] == 'C')
				fill_col(&bgame->game, i, j);
			else if (bgame->game.area->map[i][j] == 'P')
				fill_player(&bgame->game, i, j);
			else if (bgame->game.area->map[i][j] == 'E')
				fill_exit(&bgame->game, i, j);
			else if (bgame->game.area->map[i][j] == 'S')
                fill_enemy(bgame, i, j);
            else
				fill_wall(&bgame->game, i, j);
			j++;
		}
		i++;
	}
}
