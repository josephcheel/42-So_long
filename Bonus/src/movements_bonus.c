/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:35:36 by jcheel-n          #+#    #+#             */
/*   Updated: 2022/07/29 13:43:54 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long_bonus.h"

static void	move_resume(t_map *map, int x, int y, int dir)
{
	if (dir == UP)
		y -= 1;
	if (dir == DOWN)
		y += 1;
	if (dir == LEFT)
		x -= 1;
	if (dir == RIGHT)
		x += 1;
	if (map->array[y][x] == 'E' && map->c == 0)
		return (ft_win(map));
	if (map->array[y][x] == 'X')
		return (ft_lose(map));
	if (map->array[y][x] == 'C')
	{
		map->array[y][x] = '0';
		map->c--;
	}
	map->moves++;
}

void	move_up(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (y > 0 && map->array[y - 1][x] != '1')
	{
		move_resume(map, x, y, UP);
		if ((map->array[y - 1][x] == 'E' && map->c != 0) || map->exit == 1)
			return ;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
			x * IMG_PXL, y * IMG_PXL);
		map->array[y][x] = '0';
		y--;
		print_movements(map);
	}
	move_animation_up(map, x, y);
	map->array[y][x] = 'P';
	map->player.x = x;
}

void	move_left(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (x > 0 && map->array[y][x - 1] != '1')
	{
		move_resume(map, x, y, LEFT);
		if ((map->array[y][x - 1] == 'E' && map->c != 0) || map->exit == 1)
			return ;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
			x * IMG_PXL, y * IMG_PXL);
		map->array[y][x] = '0';
		x--;
		print_movements(map);
	}
	move_animation_left(map, x, y);
	map->array[y][x] = 'P';
	map->player.y = y;
}

void	move_down(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (y < map->y && map->array[y + 1][x] != '1')
	{
		move_resume(map, x, y, DOWN);
		if ((map->array[y + 1][x] == 'E' && map->c != 0) || map->exit == 1)
			return ;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
			x * IMG_PXL, y * IMG_PXL);
		map->array[y][x] = '0';
		y++;
		print_movements(map);
	}
	move_animation_down(map, x, y);
	map->array[y][x] = 'P';
	map->player.y = y;
}

void	move_right(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (x < map->x && map->array[y][x + 1] != '1')
	{
		move_resume(map, x, y, RIGHT);
		if ((map->array[y][x + 1] == 'E' && map->c != 0) || map->exit == 1)
			return ;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
			x * IMG_PXL, y * IMG_PXL);
		map->array[y][x] = '0';
		x++;
		print_movements(map);
	}
	move_animation_right(map, x, y);
	map->array[y][x] = 'P';
	map->player.x = x;
}
