/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_monster_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:39:45 by jcheel-n          #+#    #+#             */
/*   Updated: 2022/08/01 12:39:50 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long_bonus.h"

int	count_monster(t_map *map)
{
	int	y;
	int	x;
	int	m;

	m = 0;
	y = 0;
	x = 0;
	while (y < map->y)
	{
		while (x < map->x)
		{
			if (map->array[y][x] == 'X')
				m++;
			x++;
		}
		x = 0;
		y++;
	}
	return (m);
}

void	alloc_monster(t_map *map)
{
	int	y;
	int	x;
	int	m;

	m = 0;
	y = 0;
	x = 0;
	while (y < map->y)
	{
		while (x < map->x && m < map->enemy.nbr)
		{
			if (map->array[y][x] == 'X')
			{
				map->enemy.array[0][m] = y;
				map->enemy.array[1][m] = x;
				m++;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	scan_monster(t_map *map)
{
	map->enemy.nbr = count_monster(map);
	if (map->enemy.nbr <= 0)
		return ;
	map->enemy.array = malloc(sizeof(int **) * 3);
	map->enemy.array[0] = malloc(sizeof(int *) * map->enemy.nbr + 1);
	map->enemy.array[1] = malloc(sizeof(int *) * map->enemy.nbr + 1);
	map->enemy.array[2] = 0;
	map->enemy.array[0][map->enemy.nbr] = 0;
	map->enemy.array[1][map->enemy.nbr] = 0;
	alloc_monster(map);
}
