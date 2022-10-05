/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:19:13 by jcheel-n          #+#    #+#             */
/*   Updated: 2022/04/13 18:02:13 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# define BUFFER_SIZE 1048

char	*get_next_line(int fd);

// void	*ft_memcpy(void *dst, const void *src, size_t n);
// char	*ft_strchr(const char *s, int c);
// size_t	ft_strlen(char const *str);
//char	*ft_substr(char const *s, unsigned int start, size_t len, int freeme);
//char	*ft_strjoin(char *s1, char *s2);

#endif
