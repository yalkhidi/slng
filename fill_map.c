/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:23:11 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/03/27 15:58:24 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_bg(t_game *game)
{
	int	i;
	int	j;

	if (!game->imgs.space.img)
	{
		free(game);
		print_message("Error\nCan't load background image.\n");
	}
	i = 0;
	while (i < game->area->height)
	{
		j = 0;
		while (j < game->area->width)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->imgs.space.img, j * 70, i * 70);
			fill_sides(game, i, j);
			j++;
		}
		i++;
	}
}

void	fill_map(t_game *game)
{
	int	i;
	int	j;

	fill_bg(game);
	fill_corners(game);
	i = 1;
	while (i < game->area->height - 1)
	{
		j = 1;
		while (j < game->area->width - 1)
		{
			if (game->area->map[i][j] == '0')
				fill_space(game, i, j);
			else if (game->area->map[i][j] == 'C')
				fill_col(game, i, j);
			else if (game->area->map[i][j] == 'P')
				fill_player(game, i, j);
			else if (game->area->map[i][j] == 'E')
				fill_exit(game, i, j);
			else
				fill_wall(game, i, j);
			j++;
		}
		i++;
	}
}

void	fill_corners(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->imgs.top_left.img,
		0 * 70, 0 * 70);
	mlx_put_image_to_window(game->mlx, game->win, game->imgs.top_right.img,
		(game->area->width - 1) * 70, 0 * 70);
	mlx_put_image_to_window(game->mlx, game->win, game->imgs.bot_left.img,
		0 * 70, (game->area->height - 1) * 70);
	mlx_put_image_to_window(game->mlx, game->win, game->imgs.bot_right.img,
		(game->area->width - 1) * 70, (game->area->height - 1) * 70);
}

void	fill_sides(t_game *game, int i, int j)
{
	if (j == 0 && (i > 0 && i < game->area->height - 1))
	{
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.left.img,
			j * 70, i * 70);
	}
	else if (j == game->area->width - 1 && (i != 0 && i < game->area->height))
	{
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.right.img,
			j * 70, i * 70);
	}
	if (i == 0 && j > 0 && j < game->area->width - 1)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.top_bot.img,
			j * 70, i * 70);
	}
	else if (i == game->area->height - 1
		&& (j > 0 && j < game->area->width - 1))
	{
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.top_bot.img,
			j * 70, i * 70);
	}
}

