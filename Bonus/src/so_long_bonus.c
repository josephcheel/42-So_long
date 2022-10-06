/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josephcheel <josephcheel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:55:50 by jcheel-n          #+#    #+#             */
/*   Updated: 2022/09/30 13:56:36 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long_bonus.h"

void	map_initializer(t_map *map)
{
	map->moves = 0;
	map->z = 0;
	map->action = 0;
	map->enemy.pos = 0;
	map->enemy.nbr = 0;
	map->e = 0;
	map->c = 0;
	map->p = 0;
	map->y = 0;
	map->player.y = 0;
	map->player.x = 0;
	map->exit = 0;
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac == 2)
	{
		map.filename = av[1];
		map_initializer(&map);
		map_checker(&map);
		map.mlx = mlx_init();
		map.wnd = mlx_new_window(map.mlx, map.x * IMG_PXL,
				map.y * IMG_PXL + IMG_PXL * 1.25, WND_NAME);
		map_printer(&map);
		scan_monster(&map);
		if (map.enemy.nbr > 0)
			mlx_loop_hook(map.mlx, move_monster, &map);
		mlx_hook(map.wnd, 17, 0, ft_close, &map);
		mlx_key_hook(map.wnd, key_hook, &map);
		mlx_loop(map.mlx);
	}
	write(2, "\033[1;31m🛑ERROR: ", 19);
	write(2, "Usage: ./so_long mapfile\n\033[0m", 30);
	exit(EXIT_FAILURE);
}
