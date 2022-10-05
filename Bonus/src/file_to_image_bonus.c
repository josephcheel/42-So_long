/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_image_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:13:51 by jcheel-n          #+#    #+#             */
/*   Updated: 2022/07/28 18:22:22 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	file_to_image(t_map *map)
{
	int	a;

	a = IMG_PXL;
	map->img.empty = mlx_xpm_file_to_image(map->mlx,
			"Resources/empty.xpm", &a, &a);
	map->img.wall = mlx_xpm_file_to_image(map->mlx,
			"Resources/wall.xpm", &a, &a);
	map->img.exit = mlx_xpm_file_to_image(map->mlx,
			"Resources/door.xpm", &a, &a);
	map->img.collectible = mlx_xpm_file_to_image(map->mlx,
			"Resources/estrellita.xpm", &a, &a);
	map->img.enemy = mlx_xpm_file_to_image(map->mlx,
			"Resources/enemy.xpm", &a, &a);
	map->img.enemy2 = mlx_xpm_file_to_image(map->mlx,
			"Resources/enemy-2-2.xpm", &a, &a);
	file_to_image_player(map);
}

void	file_to_image_player(t_map *map)
{
	int	a;

	a = IMG_PXL;
	map->img.player_right1 = mlx_xpm_file_to_image(map->mlx,
			"Resources/right-1-40.xpm", &a, &a);
	map->img.player_right2 = mlx_xpm_file_to_image(map->mlx,
			"Resources/right-2-40.xpm", &a, &a);
	map->img.player_up1 = mlx_xpm_file_to_image(map->mlx,
			"Resources/up-1-40.xpm", &a, &a);
	map->img.player_up2 = mlx_xpm_file_to_image(map->mlx,
			"Resources/up-2-40.xpm", &a, &a);
	map->img.player_down1 = mlx_xpm_file_to_image(map->mlx,
			"Resources/down-1-40.xpm", &a, &a);
	map->img.player_down2 = mlx_xpm_file_to_image(map->mlx,
			"Resources/down-2-40.xpm", &a, &a);
	map->img.player_left1 = mlx_xpm_file_to_image(map->mlx,
			"Resources/left-1-40.xpm", &a, &a);
	map->img.player_left2 = mlx_xpm_file_to_image(map->mlx,
			"Resources/left-2-40.xpm", &a, &a);
}
