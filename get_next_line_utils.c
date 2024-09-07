/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:07:43 by heda-sil          #+#    #+#             */
/*   Updated: 2023/01/08 13:07:55 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *) &s[i]);
		i++;
	}
	if (!s[i] && c == 0)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char *r_line, char *buff)
{
	char	*str;
	int		i;
	int		j;

	if (!r_line || !buff)
		return (NULL);
	str = ft_calloc(ft_strlen(r_line) + ft_strlen(buff) + 1, sizeof(char));
	i = 0;
	if (r_line)
	{
		while (r_line[i])
		{
			str[i] = r_line[i];
			i++;
		}
	}
	j = 0;
	while (buff[j])
	{
		str[i + j] = buff[j];
		j++;
	}
	free(r_line);
	return (str);
}

size_t	ft_strlen(char *s)
{
	size_t	length;

	length = 0;
	if (!s)
		return (0);
	while (s[length])
		length++;
	return (length);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = s;
	while (n > 0)
	{
		*str = 0;
		str++;
		n--;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*array;

	array = (void *)malloc(nmemb * size);
	if (!array)
		return (NULL);
	ft_bzero (array, nmemb * size);
	return (array);
}
