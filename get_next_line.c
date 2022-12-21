/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:15:41 by dimarque          #+#    #+#             */
/*   Updated: 2022/12/21 23:06:18 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i;
	int			j;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ctrl_L(buffer, fd));
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buffer);
		i = 0;
		j = -1;
		while (buffer[i])
		{
			if (j != -1)
				buffer[j++] = buffer[i];
			if (buffer[i] == '\n' && j == -1)
				j = 0;
			buffer[i++] = 0;
		}
		if (line[ft_strlen(line) - 1] == '\n')
			break ;
	}
	return (line);
}

/* int main(void)
{
	int fd;
	char *line;
	fd = open("test.txt", O_RDONLY);
	//printf("%s", get_next_line(fd));
	while ((ln = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	return (0);
} */