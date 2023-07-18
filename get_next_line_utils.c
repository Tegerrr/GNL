/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timelkon <timelkon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:40:00 by timelkon          #+#    #+#             */
/*   Updated: 2023/02/24 11:51:55 by timelkon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_nl(char *str1, char *str2)

{
	char	*spc;
	size_t	i;

	i = 0;
	spc = malloc (ft_strlen(str1) + ft_strlen(str2) * sizeof(char) + 1);
	if (spc == NULL)
		return (NULL);
	while (str1 && str1[i])
	{
		spc[i] = str1[i];
		i++;
	}
	while (*str2)
	{
		spc[i] = *str2;
		i++;
		str2++;
	}
	spc[i] = '\0';
	free(str1);
	return (spc);
}

size_t	ft_strlen(const char *str)

{
	size_t	a;
	char	*len;

	if (!str)
		return (0);
	a = 0;
	len = (char *)str;
	while (len[a] != '\0')
	{
		a++;
	}
	return (a);
}

char	*ft_substr(char *s, unsigned int start, size_t len)

{
	char	*spc;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	spc = malloc(len + 1);
	if (!spc)
		return (0);
	i = 0;
	while (i != len)
	{
		spc[i] = s[start];
		i++;
		start++;
	}
	spc[i] = '\0';
	free(s);
	return (spc);
}

char	*ft_strchr(const char *s, int c)

{
	char	*cop;

	if (!s)
		return (0);
	cop = (char *)s;
	while (*cop != '\0' && *cop != (char)c)
		cop++;
	if (*cop == (char)c)
		return (cop);
	return (0);
}

char	*ft_substr_nofree(char *s, unsigned int start, size_t len)

{
	char	*spc;
	char	*c;
	size_t	i;

	if (!s)
		return (NULL);
	c = s;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	spc = malloc(len + 1);
	if (!spc)
		return (0);
	i = 0;
	while (i != len)
	{
		spc[i] = s[start];
		i++;
		start++;
	}
	spc[i] = '\0';
	return (spc);
}
