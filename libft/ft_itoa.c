/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:50:16 by jcheel-n          #+#    #+#             */
/*   Updated: 2022/02/17 20:33:52 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_intlenght(int c)
{
	size_t	ret;

	ret = 0;
	if (c == 0)
		return (1);
	if (c < 0)
		ret++;
	while (c)
	{
		c = c / 10;
			ret++;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	lenght;
	size_t	i;

	lenght = ft_intlenght(n);
	str = malloc(sizeof(char) * (lenght + 1));
	if (!str || n > INT_MAX || n < INT_MIN)
		return (NULL);
	str[lenght] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		i = 1;
	}
	else
		i = 0;
	while (lenght-- > i)
	{
		if (n < 0)
			str[lenght] = 48 + (n % 10) * (-1);
		else
			str[lenght] = (n % 10) + 48;
		n = n / 10;
	}
	return (str);
}
