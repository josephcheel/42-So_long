/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:20:04 by jcheel-n          #+#    #+#             */
/*   Updated: 2022/02/17 20:38:26 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	size_t	len;
	char	find;

	find = (char)c;
	len = ft_strlen(s);
	str = (char *)s;
	if (!s)
		return (NULL);
	while (len + 1 > 0)
	{
		if (*str == find)
			return (str);
		str++;
		len--;
	}	
	return (NULL);
}
