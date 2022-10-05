/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_animation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:09:33 by jcheel-n          #+#    #+#             */
/*   Updated: 2022/07/29 14:20:20 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	move_animation_right(t_map *map, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
		x * IMG_PXL, y * IMG_PXL);
	if (map->z == 0)
	{
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_right1,
			x * IMG_PXL + 8, y * IMG_PXL);
		map->z = 1;
	}
	else if (map->z == 1)
	{
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_right2,
			x * IMG_PXL + 8, y * IMG_PXL);
		map->z = 0;
	}
}

void	move_animation_left(t_map *map, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
		x * IMG_PXL, y * IMG_PXL);
	if (map->z == 0)
	{
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_left1,
			x * IMG_PXL + 8, y * IMG_PXL);
		map->z = 1;
	}
	else if (map->z == 1)
	{
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_left2,
			x * IMG_PXL + 8, y * IMG_PXL);
		map->z = 0;
	}
}

void	move_animation_up(t_map *map, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
		x * IMG_PXL, y * IMG_PXL);
	if (map->z == 0)
	{
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_up1,
			x * IMG_PXL + 8, y * IMG_PXL);
		map->z = 1;
	}
	else if (map->z == 1)
	{
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_up2,
			x * IMG_PXL + 8, y * IMG_PXL);
		map->z = 0;
	}
}

void	move_animation_down(t_map *map, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
		x * IMG_PXL, y * IMG_PXL);
	if (map->z == 0)
	{
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_down1,
			x * IMG_PXL + 8, y * IMG_PXL);
		map->z = 1;
	}
	else if (map->z == 1)
	{
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_down2,
			x * IMG_PXL + 8, y * IMG_PXL);
		map->z = 0;
	}
}
