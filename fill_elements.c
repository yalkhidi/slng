/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 13:50:38 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/03/27 13:47:41 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_wall(t_game *game, int i, int j)
{
	if (!game->imgs.top_bot.img)
	{
		free(game);
		print_message("Error\nFailed to load a wall.\n");
	}
	mlx_put_image_to_window(game->mlx, game->win, game->imgs.top_bot.img,
		j * 70, i * 70);
}

void	fill_space(t_game *game, int i, int j)
{
	if (!game->imgs.space.img)
	{
		free(game);
		print_message("Error\nFailed to load free space.\n");
	}
	mlx_put_image_to_window(game->mlx, game->win, game->imgs.space.img,
		j * 70, i * 70);
}

void	fill_col(t_game *game, int i, int j)
{
	fill_space(game, i, j);
	if (!game->imgs.collect.img)
	{
		free(game);
		print_message("Error\nFailed to load a collectible.\n");
	}
	mlx_put_image_to_window(game->mlx, game->win, game->imgs.collect.img,
		j * 70, i * 70);
}

void	fill_player(t_game *game, int i, int j)
{
	fill_space(game, i, j);
	if (!game->imgs.player.img)
	{
		free(game);
		print_message("Error\nFailed to load player.\n");
	}
	mlx_put_image_to_window(game->mlx, game->win, game->imgs.player.img,
		j * 70, i * 70);
}

void	fill_exit(t_game *game, int i, int j)
{
	if (!game->imgs.exit.img)
	{
		free(game);
		print_message("Error\nFailed to load exit.\n");
	}
	mlx_put_image_to_window(game->mlx, game->win, game->imgs.exit.img,
		j * 70, i * 70);
}
