/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:07:23 by codespace         #+#    #+#             */
/*   Updated: 2025/03/27 14:09:21 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// void	check_filename(char *filename)
// {
// 	char	*ext;

// 	ext = ft_strrchr(filename, '.');
// 	if (!ext || ft_strncmp(ext, ".ber", 4) || ext[4] != '\0' || ext == filename)
// 		print_message("Error\nInvalid map filename.\n");
// }

t_area	*check_map_bonus(char *filename)
{
	t_area	*area;

	area = NULL;
	check_filename(filename);
	printf("validated filename\n");
	validate_map_walls(filename);
	printf("validated walls\n");
	validate_map_shape(filename);
	printf("validated shape\n");
	validate_map_elements(filename);
	printf("validated elements\n");
	validate_map_elements_bonus(filename);
	printf("validated elements bonus\n");
	validate_invalid_elements_bonus(filename);
	printf("validated invalid elements bonus\n");
	validate_start_exit(filename);
	printf("validated start/exit\n");
	area = collect_info(filename);
	printf("validated start/exit\n");
	if (is_valid_map_bonus(area))
		return (area);
	print_message("Error\nNovalid path in the map.\n");
	return (NULL);
}
