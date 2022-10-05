/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:52:29 by jcheel-n          #+#    #+#             */
/*   Updated: 2022/09/30 13:55:14 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long_bonus.h"

void	move_on_paths(int x, int y, t_map *map)
{
	char	type;

	type = map->copy[y][x];
	if (type == 'C')
		map->c_check -= 1;
	else if (type == 'E')
		map->e_check -= 1;
	else if (type == '0' || type == 'P' || type == 'X')
		;
	else
		return ;
	map->copy[y][x] = '1';
	move_on_paths(x + 1, y, map);
	move_on_paths(x - 1, y, map);
	move_on_paths(x, y + 1, map);
	move_on_paths(x, y - 1, map);
}

void	check_valid_path(t_map *map)
{
	int	x;
	int	y;

	map->c_check = map->c;
	map->e_check = map->e;
	scan_player(map);
	x = map->player.x;
	y = map->player.y;
	move_on_paths(x, y, map);
	if (map->c_check != 0 || map->e_check == map->e)
	{
		write(2, "\033[1;31m🛑ERROR: ", 19);
		write(2, "NO VALID PATH\n\033[0m", 19);
		ft_free_array(map->array, map->y);
		ft_free_array(map->copy, map->y);
		exit(EXIT_FAILURE);
	}
}
