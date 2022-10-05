/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josephcheel <josephcheel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:55:37 by jcheel-n          #+#    #+#             */
/*   Updated: 2022/07/28 17:50:53 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long_bonus.h"

static void	checker_file(char *map)
{
	size_t	len;

	len = ft_strlen(map);
	if (map[len - 1] != 'r')
		error_filename();
	if (map[len - 2] != 'e')
		error_filename();
	if (map[len - 3] != 'b')
		error_filename();
	if (map[len - 4] != '.')
		error_filename();
	if (!ft_strnstr(map, ".ber", ft_strlen(map)))
		error_filename();
}

static void	checker_params(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->y)
	{
		while (x < map->x)
		{
			if (map->array[y][x] == 'C')
				map->c += 1;
			else if (map->array[y][x] == 'E')
				map->e += 1;
			else if (map->array[y][x] == 'P')
				map->p += 1;
			else if (map->array[y][x] == '0' || map->array[y][x] == '1'
				|| map->array[y][x] == 'X');
			else
				error_map_elements(map);
			x++;
		}
		x = 0;
		y++;
	}
	if (map->c < 1 || map->e < 1 || map->p != 1)
		error_map_elements(map);
}

static void	checker_wall(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (map->array[0][x] == '1' && map->array[1][x])
		x++;
	if (map->array[1][x] != '\0')
		error_wall(map);
	y = 1;
	while (y < map->y)
	{
		if (map->array[y][0] != '1' ||
				map->array[y][map->x - 1] != '1')
			error_wall(map);
		y++;
	}
	x = 0;
	while (map->array[map->y - 1][x] == '1')
		x++;
	if (map->array[map->y - 1][x] != '\0')
		error_wall(map);
}

void	checker_size(t_map *map)
{
	int	y;
	int	x;
	int	max;

	y = 0;
	x = 0;
	max = ft_strlen(map->array[y]);
	while (y < map->y)
	{
		x = ft_strlen(map->array[y]);
		if (max != x)
			error_size(map);
		y++;
	}
	map->x = max;
}

void	map_checker(t_map *map)
{
	checker_file(map->filename);
	map_array(map);
	checker_size(map);
	checker_wall(map);
	checker_params(map);
	check_valid_path(map);
	ft_free_array(map->copy, map->y);
}
