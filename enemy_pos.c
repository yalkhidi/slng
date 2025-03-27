/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:24:24 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/03/27 18:10:56 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	keys_b(int keycode, t_bgame *bgame)
{
	int	new_px;
	int	new_py;

	new_px = bgame->game.area->player_x;
	new_py = bgame->game.area->player_y;
	if (keycode == 53)
	{
		free_game(&bgame->game);
		exit (0);
	}
	else if (keycode == 0)
		new_px--;
	else if (keycode == 2)
		new_px++;
	else if (keycode == 1)
		new_py++;
	else if (keycode == 13)
		new_py--;
	else
		return (-1);
	check_new_postion_b(bgame, new_px, new_py);
	return (0);
}


void	check_new_postion_b(t_bgame *bgame, int new_x, int new_y)
{
	if (bgame->game.area->map[new_y][new_x] == 'E')
	{
		if (bgame->game.area->collect_count == 0)
		{
			write(1, "You Win\n", 9);
			free_game(&bgame->game);
			exit(0);
		}
		return ;
	}
	if (bgame->game.area->map[new_y][new_x] == 'S')
    {
        free_game(&bgame->game);
        print_message("You touched an enemy.");
    }
	if (bgame->game.area->map[new_y][new_x] == 'C')
		bgame->game.area->collect_count--;
	if (bgame->game.area->map[new_y][new_x] == '1')
		return ;
	bgame->game.area->map[bgame->game.area->player_y][bgame->game.area->player_x] = '0';
	bgame->game.area->map[new_y][new_x] = 'P';
	bgame->game.area->player_x = new_x;
	bgame->game.area->player_y = new_y;
	fill_map_b(bgame);
	bgame->game.moves++;
	print_moves_onscreen(&bgame->game);
}

void	print_moves_onscreen(t_game *game)
{
	char	*moves;

	mlx_string_put(game->mlx, game->win, 10, 10, 16777215, "Moves: ");
	moves = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, 55, 10, 16777215, moves);
}