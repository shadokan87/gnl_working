
#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char buff[BUFF_SIZE + 1];
	static char *stack[4094];
	int file;
	
	if (fd < 0 || line == NULL)
		return (-1);
	while (c_len(stack[fd], ENDL) == -1)
	{
		file = read(fd, buff, BUFF_SIZE);
		buff[file] = '\0';
		str_join(&stack[fd], buff);
		if (file == 0)
			break ;
	}
	return (return_value(&stack[fd], line));
}

/*
int	main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDONLY);
	char *line;
	int ret;

	int count = 0;
	int i = 0;
	while (i < 21)
	{
		ret = get_next_line(fd, &line);
		printf("--> %s |%d|\n", line, ret);
		i++;
	}
}*/
