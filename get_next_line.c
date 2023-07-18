/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timelkon <timelkon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:28:41 by timelkon          #+#    #+#             */
/*   Updated: 2023/02/24 13:13:19 by timelkon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*spc;
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s1;
	spc = malloc(ft_strlen(str) * sizeof(char) + 1);
	if (spc == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		spc[i] = str[i];
		i++;
	}
	spc[i] = '\0';
	return (spc);
}

int	llen(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	return (i);
}

char	*ft_bla(char *line)
{
	char	*tmp;

	tmp = line;
	if (line[llen(line)] == '\n')
	{
		line = ft_substr_nofree(tmp, llen(tmp) + 1, ft_strlen(tmp) - llen(tmp));
		return (line);
	}
	else
		return (NULL);
}

char	*sdelai(char *line, int fd)
{
	char	*buf;
	int		check;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (!ft_strchr(line, '\n'))
	{
		check = read(fd, buf, BUFFER_SIZE);
		buf[check] = '\0';
		if (check == -1)
		{
			free(buf);
			return (0);
		}
		if (check == 0)
			break ;
		line = ft_strjoin_nl(line, buf);
	}
	free(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*nine;

	line = NULL;
	if (nine)
		line = nine;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = sdelai(line, fd);
	if (!line)
		return (NULL);
	nine = ft_bla(line);
	if (line && !*line)
	{
		free(line);
		free(nine);
		return (NULL);
	}	
	line = ft_substr(line, 0, llen(line) + 1);
	return (line);
}
