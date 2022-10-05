/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:38:09 by jcheel-n          #+#    #+#             */
/*   Updated: 2022/02/21 19:21:38 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needlelen;

	needlelen = ft_strlen(needle);
	if (!needle)
		return ((char *)haystack);
	while (*haystack && len > needlelen
		&& ft_strncmp(haystack, needle, needlelen))
	{
		haystack++;
		len--;
	}
	if (len >= needlelen && !ft_strncmp(haystack, needle, needlelen))
		return ((char *)haystack);
	return (NULL);
}
