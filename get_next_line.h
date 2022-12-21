#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h> // O_RDONLY
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

char	*get_next_line(int fd);

int		ft_strlen(char *str);

char	*ctrl_L(char *buffer, int fd);

char	*ft_strjoin(char *s1, char *s2);

#endif