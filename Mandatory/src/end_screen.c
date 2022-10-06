/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:29:19 by jcheel-n          #+#    #+#             */
/*   Updated: 2022/07/28 15:52:30 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long.h"

int	ft_close(t_map *map)
{
	mlx_destroy_window(map->mlx, map->wnd);
	ft_free_array(map->array, map->y);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_win(t_map *map)
{
	map->exit = 1;
	map->moves++;
	mlx_clear_window(map->mlx, map->wnd);
	mlx_string_put(map->mlx, map->wnd,
		map->x / 2 * IMG_PXL, map->y / 2 * IMG_PXL, 0xFFFA9E, "YOU WON");
	write(1, "\n", 1);
	write(1, "\x1b[32;01m", 9);
	write(1, "🏆🏆YOU WON!!🏆🏆\n", 27);
	write(1, "\x1b[0m", 5);
}
