/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esrkahra <esrkahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:32:08 by esrkahra          #+#    #+#             */
/*   Updated: 2025/01/26 15:08:08 by esrkahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static char	*get_read(char *str, int fd)
{
	char		*temp;
	ssize_t		i;

	i = 1;
	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	while (!ft_strchr(str, '\n') && i != 0)
	{
		i = read(fd, temp, BUFFER_SIZE);
		if (i == -1)
		{
			ft_free(str);
			return (ft_free(temp));
		}
		temp[i] = '\0';
		str = ft_strjoin(str, temp);
		if (!str)
			return (ft_free(temp));
	}
	free(temp);
	return (str);
}

static char	*get_line(char *str)
{
	char	*temp;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
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

static char	*get_last(char *str)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (ft_free(str));
	temp = malloc(ft_strlen(str) - i + 1);
	if (!temp)
		return (ft_free(str));
	i++;
	while (str[i])
		temp[j++] = str[i++];
	temp[j] = '\0';
	free(str);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*temp;
	static char	*str = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (ft_free(str));
	}
	str = get_read(str, fd);
	if (str == NULL)
	{
		return (ft_free(str));
	}
	temp = get_line(str);
	str = get_last(str);
	return (temp);
}
