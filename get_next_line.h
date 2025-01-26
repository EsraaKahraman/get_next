/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esrkahra <esrkahra@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:08:26 by esrkahra          #+#    #+#             */
/*   Updated: 2025/01/26 15:36:14 by esrkahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_free(char *str);
int		ft_strchr(char *str, int c);
char	*ft_strjoin(char *str, char *temp);

#endif
