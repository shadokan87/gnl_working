#ifndef GET_NEXT_LINE_H
 #define GET_NEXT_LINE_H

 #define BUFF_SIZE 4096
 #define ENDL '\n'

 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/uio.h>
 #include <stdlib.h>
 #include <fcntl.h>
#include "Memd/mem.h"

int		get_next_line(int fd, char **line);
int		c_len(char *Str, char c);
char	*ft_strndup(char *str, int len);
void	str_join(char **dst, char *src);
int		return_value(char **stack, char **line);

#endif
