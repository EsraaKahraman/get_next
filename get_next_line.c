/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esrkahra <esrkahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:32:08 by esrkahra          #+#    #+#             */
/*   Updated: 2025/01/26 17:42:13 by esrkahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static char	*ft_last(char *str)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		return (free(str), NULL);
	}
	temp = malloc(ft_strlen(str) - i + 1);
	if (!temp)
		return (free(str), NULL);
	i++;
	while (str[i])
		temp[j++] = str[i++];
	temp[j] = '\0';
	free(str);
	return (temp);
}

static char	*ft_line(char *str)
{
	char	*temp;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	temp = malloc(i + 2);
	if (!temp)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		temp[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

static char	*get_read(char *str, int fd)
{
	char	*temp;
	int		i;

	i = 1;
	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	while (!ft_strchr(str, '\n') && i != 0)
	{
		i = read(fd, temp, BUFFER_SIZE);
		if (i == -1)
		{
			return (free(str), str = NULL, free(temp), NULL);
		}
		temp[i] = '\0';
		str = ft_strjoin(str, temp);
		if (!str)
			return (free(temp), NULL);
	}
	free(temp);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*temp;
	static char	*str = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (free(str), str = NULL, NULL);
	}
	str = get_read(str, fd);
	if (!str)
	{
		return (free(str), str = NULL, NULL);
	}
	temp = ft_line(str);
	str = ft_last(str);
	return (temp);
}
