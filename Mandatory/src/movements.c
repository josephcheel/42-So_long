/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:10:35 by jcheel-n          #+#    #+#             */
/*   Updated: 2022/07/28 15:52:51 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long.h"

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
	if (map->array[y][x] == 'C')
	{
		map->array[y][x] = '0';
		map->c--;
	}
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
		if (map->array[y - 1][x] == 'E' && (map->c != 0 || map->exit == 1))
			return ;
		map->moves++;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
			x * IMG_PXL, y * IMG_PXL);
		map->array[y][x] = '0';
		y--;
		print_movements(map);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
			x * IMG_PXL, y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_up1,
			x * IMG_PXL + 8, y * IMG_PXL);
		map->array[y][x] = 'P';
		map->player.x = x;
	}
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
		if (map->array[y][x - 1] == 'E' && (map->c != 0 || map->exit == 1))
			return ;
		map->moves++;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
			x * IMG_PXL, y * IMG_PXL);
		map->array[y][x] = '0';
		x--;
		print_movements(map);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
			x * IMG_PXL, y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_left1,
			x * IMG_PXL + 8, y * IMG_PXL);
		map->array[y][x] = 'P';
	map->player.y = y;
	}
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
		if (map->array[y + 1][x] == 'E' && (map->c != 0 || map->exit == 1))
			return ;
		map->moves++;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
			x * IMG_PXL, y * IMG_PXL);
		map->array[y][x] = '0';
		y++;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
			x * IMG_PXL, y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_down1,
			x * IMG_PXL + 8, y * IMG_PXL);
		map->array[y][x] = 'P';
		print_movements(map);
		map->player.y = y;
	}
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
		if (map->array[y][x + 1] == 'E' && (map->c != 0 || map->exit == 1))
			return ;
		map->moves++;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
			x * IMG_PXL, y * IMG_PXL);
		map->array[y][x] = '0';
		x++;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
			x * IMG_PXL, y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_right1,
			x * IMG_PXL + 8, y * IMG_PXL);
		map->array[y][x] = 'P';
		print_movements(map);
	}
	map->player.x = x;
}
