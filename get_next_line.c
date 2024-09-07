/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:18:28 by heda-sil          #+#    #+#             */
/*   Updated: 2023/01/08 13:10:42 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd, char *r_line)
{
	char	*buff;
	int		r;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(*buff));
	if (!buff)
		return (NULL);
	r = 1;
	while (r != 0 && !ft_strchr(r_line, '\n'))
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r == -1)
		{
			free(r_line);
			free(buff);
			return (NULL);
		}
		buff[r] = 0;
		if (!r_line)
			r_line = ft_calloc(1, sizeof(*r_line));
		r_line = ft_strjoin(r_line, buff);
	}
	free(buff);
	return (r_line);
}

char	*ft_get_line(char *r_line)
{
	char	*line;
	int		i;

	i = 0;
	if (!r_line[i])
		return (NULL);
	while (r_line[i] && r_line[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(*line));
	i = 0;
	while (r_line[i] && r_line[i] != '\n')
	{
			line[i] = r_line[i];
			i++;
	}
	if (r_line[i] == '\n')
		line[i] = r_line[i];
	return (line);
}

char	*ft_get_new_line(char *r_line)
{
	char	*new_r_line;
	int		i;
	int		j;

	i = 0;
	while (r_line[i] && r_line[i] != '\n')
		i++;
	if (!r_line[i])
	{
		free(r_line);
		return (NULL);
	}
	new_r_line = ft_calloc((ft_strlen(r_line) - i + 1), sizeof(*new_r_line));
	i += 1;
	j = 0;
	while (r_line[i + j])
	{
		new_r_line[j] = r_line[i + j];
		j++;
	}
	free(r_line);
	return (new_r_line);
}

char	*get_next_line(int fd)
{
	static char	*r_line;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	r_line = ft_read_file(fd, r_line);
	if (!r_line)
		return (NULL);
	line = ft_get_line(r_line);
	r_line = ft_get_new_line(r_line);
	return (line);
}

/* #include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("file", O_RDONLY);
	if (fd == -1)
	{
		printf("File failed to open\n");
		return (0);
	}
	i = 1;
	while (fd)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("              <<<<<<<<<<<<line %i>>>>>>>>>>>> \n", i++);
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
} */
