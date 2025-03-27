/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:50:05 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/03/27 17:56:35 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "so_long.h"

typedef struct s_enemy
{
    int x;
    int y;
}   t_enemy;

typedef struct s_bgame
{
	t_game game;
	t_img	enemy[3];
	int		enemy_frame;
	t_enemy enemy_pos;
}	t_bgame;
//          MAP Validation             //
t_area	*check_map_bonus(char *filename);

//          Map elements		
void	check_elements_bonus(char *line, int *wall, int *space, int *sprite);
void	validate_map_elements_bonus(char *filename);
//          Map invalid elements		
void	invalid_elements_bonus(char *line, int fd);
void	validate_invalid_elements_bonus(char *filename);
//			Map Path			
void	flood_fill_bonus(t_area *area, char **map, int x, int y);
void	check_path_bonus(int x, int y, char **map, t_area *area);
int	is_valid_map_bonus(t_area *area);
int	keys_b(int keycode, t_bgame *bgame);
void	print_moves_onscreen(t_game *game);
void    load_enemy(t_bgame *bgame);
int		animate_enemy(t_bgame *bgame);
void    fill_enemy(t_bgame *bgame, int i, int j);
void	fill_bg_bonus(t_bgame *bgame);
void	fill_map_b(t_bgame *bgame);
void	check_new_postion_b(t_bgame *bgame, int new_x, int new_y);
void    move_enemy(t_bgame *bgame);
#endif