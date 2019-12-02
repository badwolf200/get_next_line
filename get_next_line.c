/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rkowalsk <rkowalsk@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/18 15:16:37 by rkowalsk     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/27 16:06:49 by rkowalsk    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int		str_c(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char	**store_buffer(char *rest, char *buffer, char **line)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(*line);
	i = 0;
	if(!(*line = malloc(sizeof(char) * (j + ft_strlen(buffer) + 1))))
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		*line[j++] = buffer[i++];
	if (buffer[i] == '\n')
		*line[j++] = buffer[i++];
	*line[j] = '\0';
	j = 0;
	if (buffer[i] != '\0')
	{
		if (!(rest = malloc(sizeof(char) * (ft_strlen(buffer + i) + 1))))
			return (NULL);
		while (buffer[i])
			rest[j++] = buffer[i++];
		rest[j] = '\0';
	}
	return (line);
}

int 	get_next_line(int fd, char **line)
{
	static char	*rest;
	int			ret;
	char		buffer[BUFFER_SIZE + 1];

	if (!rest)
	{
		while (!rest)
		{
			ret = read(fd, buffer, BUFFER_SIZE - 1);
			buffer[ret] = '\0';
			if (!(line = store_buffer(rest, buffer, line)))
				return (-1);
		}
	}
	return (-1);
}
