#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i = 0;

	if (!str)
		return 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strchr(char *str, char c)
{
	if (!str)
		return 0;
	while (*str != '\0' && *str != c)
		str++;
	if (*str == c)
		return (str);
	return 0;
}


char *ft_strjoin(char *str1, char *str2)
{
	char *spc = malloc (ft_strlen(str1) + ft_strlen(str2) 
			* sizeof(char) + 1);
	if (spc == NULL)
		return (NULL);
	size_t i = 0;
	while (str1 && str1[i])
	{
		spc[i] = str1[i];
		i++;
	}
	while (*str2)
		spc[i++] = *(str2++);
	spc[i] = '\0';
	free(str1);
	return (spc);
}

char *memjoin(char *line, int fd)
{
	int check;
	char *buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (!ft_strchr(line, '\n'))
	{
		check = read(fd, buf, BUFFER_SIZE);
		buf[check] = '\0';
		if (check == -1)
		{
			free(buf);
			return 0;
		}
		if (check == 0)
			break ;
		line = ft_strjoin(line, buf);
	}
	free(buf);
	return (line);
}

char *ft_substr(char *str, int start, int len, int f)
{
	char *spc;
	char *c;
	int i = 0;

	if (!str)
		return(NULL);
	if (len > ft_strlen(str))
		len = ft_strlen(str);
	spc = malloc(len + 1);
	if (!spc)
		return 0;
	while (i != len)
		spc[i++] = str[start++];
	spc[i] = '\0';
	if (f == 1)
		free(str);
	return (spc);
}

char *create_prev(char *line)
{
	int i = 0;

	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n')
	{
		line = ft_substr(line, i + 1, ft_strlen(line) - i, 0);
		return (line);
	}
	else
		return (NULL);
}

char *get_next_line (int fd)
{
	char *line = NULL;
	static char *prev_line;

	if (prev_line)
		line = prev_line;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = memjoin(line, fd);
	if (!line)
		return (NULL);
	prev_line = create_prev(line);
	if (line && !*line)
	{
		free(line);
		free(prev_line);
		return (NULL);
	}
	int i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	line = ft_substr(line, 0, i + 1, 1);
	return (line);
}

int main()
{
	int fd = open ("file", O_RDONLY);
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	close (fd);
}
