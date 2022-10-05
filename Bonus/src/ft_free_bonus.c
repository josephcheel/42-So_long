/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:55:21 by jcheel-n          #+#    #+#             */
/*   Updated: 2022/09/30 13:55:24 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long_bonus.h"

int	ft_free_array(char **ret, int max)
{
	while (max > 0)
		free(ret[--max]);
	free(ret);
	return (0);
}

void	ft_exit_free(char *str)
{
	free(str);
	exit(EXIT_FAILURE);
}
