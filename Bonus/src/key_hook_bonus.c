/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:00:07 by jcheel-n          #+#    #+#             */
/*   Updated: 2022/09/30 13:56:20 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long_bonus.h"

void	scan_player(t_map *map)
{
	map->player.y = 0;
	map->player.x = 0;
	while (map->player.y < map->y)
	{
		while (map->player.x < map->x)
		{
			if (map->array[map->player.y][map->player.x] == 'P')
				break ;
			map->player.x++;
		}
		if (map->array[map->player.y][map->player.x] == 'P')
			break ;
		map->player.x = 0;
		map->player.y++;
	}
}

void	print_counter(t_map *map)
{
	int		x;
	char	*num;

	x = 0;
	while (x < map->x)
	{
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.wall,
			x * IMG_PXL, map->y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.wall,
			x * IMG_PXL, (map->y + 1) * IMG_PXL);
		x++;
	}
	num = ft_itoa(map->moves);
	mlx_string_put(map->mlx, map->wnd, (map->x / 2) * IMG_PXL / 5,
		map->y * IMG_PXL + IMG_PXL / 2, 0x00000, "MOVES:");
	mlx_string_put(map->mlx, map->wnd,
		(map->x / 2) * (IMG_PXL / 4) + (IMG_PXL / 2) + (IMG_PXL / 4),
		map->y * IMG_PXL + IMG_PXL / 2, 0xFFFF01, num);
	free(num);
}

int	key_hook(int keycode, t_map *map)
{
	scan_player(map);
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	if (map->exit == 1)
		return (0);
	else if (keycode == LEFT)
		move_left(map);
	else if (keycode == DOWN)
		move_down(map);
	else if (keycode == RIGHT)
		move_right(map);
	else if (keycode == UP)
		move_up(map);
	print_counter(map);
	return (0);
}
