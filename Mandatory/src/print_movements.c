/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:53:00 by jcheel-n          #+#    #+#             */
/*   Updated: 2022/07/28 15:53:03 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long.h"

void	print_movements(t_map *map)
{
	char	*move;

	move = ft_itoa(map->moves);
	write(1, "\r", 1);
	write(1, "\x1b[33;01m", 9);
	write(1, move, ft_strlen(move));
	write(1, "\x1b[0m", 5);
	write(1, " movements", 11);
	free(move);
}
