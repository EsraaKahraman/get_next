/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esrkahra <esrkahra@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:23:07 by esrkahra          #+#    #+#             */
/*   Updated: 2025/01/26 15:41:02 by esrkahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_free(char *str)
{
	if (str)
	{
		free(str);
	}
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char *str, int c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *str, char *temp)
{
	char	*uni;
	int		i;
	int		j;

	if (!str)
	{
		str = malloc(1);
		if (!str)
			return (ft_free(str));
		str[0] = '\0';
	}
	if (!str || !temp)
		return (NULL);
	uni = malloc(ft_strlen(str) + ft_strlen(temp) + 1);
	if (!uni)
		return (ft_free(str));
	i = -1;
	while (str[++i])
		uni[i] = str[i];
	j = 0;
	while (temp[j])
		uni[i++] = temp[j++];
	uni[i] = '\0';
	free(str);
	return (uni);
}
