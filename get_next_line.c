/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:15:41 by dimarque          #+#    #+#             */
/*   Updated: 2022/12/07 18:23:46 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd) {

	static char buffer[BUFFER_SIZE + 1];
	char		*ln;
	int			i;
	int			j;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (clear_error(buffer, fd));
	ln = NULL;
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		ln = ft_strjoin(ln, buffer);
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
		if (ln[ft_strlen(ln) - 1] == '\n')
			break ;
	}
	return (ln);
}

int	main(void)
{
	int		fd;
	char	*ln;
	fd = open("test.txt", O_RDONLY);
	// printf("%s", get_next_line(fd));
	while ((ln = get_next_ln(fd)))
	{
		printf("%s", ln);
		free(ln);
	}
	return (0);
}