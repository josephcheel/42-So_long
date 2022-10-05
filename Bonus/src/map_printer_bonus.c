/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_printer_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:05:27 by jcheel-n          #+#    #+#             */
/*   Updated: 2022/07/28 18:11:03 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long_bonus.h"

static void	map_type(t_map *map, int x, int y)
{
	int	type;

	type = map->array[y / IMG_PXL][x / IMG_PXL];
	if (type == 'C' || type == 'P' || type == 'E' || type == 'X' || type == '0')
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x, y);
	if (type == 'C')
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.collectible, x, y);
	else if (type == 'P')
		mlx_put_image_to_window(map->mlx, map->wnd,
			map->img.player_down1, x + 8, y);
	else if (type == 'E')
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.exit, x, y);
	else if (type == '1')
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.wall, x, y);
	else if (type == 'X')
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.enemy, x + 8, y);
}

void	map_printer(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	file_to_image(map);
	while (y < map->y)
	{
		while (x < map->x)
		{
			map_type(map, x * IMG_PXL, y * IMG_PXL);
			x++;
		}
		x = 0;
		y++;
	}
	x = 0;
	while (x <= map->x)
	{
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.wall,
			x * IMG_PXL, map->y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.wall,
			x * IMG_PXL, map->y * IMG_PXL + IMG_PXL);
		x++;
	}
}
