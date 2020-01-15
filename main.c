#include "get_next_line.h"
#include <stdio.h>
#include <pthread.h>

void	arrow(void)
{
		printf("\033[0;33m");
		printf("-->");
		printf("\033[0;0m");
}

int	main(int argc, char **argv)
{
	int fd1, fd2, fd3, fd4;
	char *line1, *line2, *line3, *line4;
	int ret;
	int count;

	count = 0;
	ret = 0;
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	fd3 = open(argv[3], O_RDONLY);
	fd4 = open(argv[4], O_RDONLY);
	
	printf("\033[0;36m");
	printf("----------------------------------------------------------------------------------------------------\n");
	printf("\033[0;33m");
	printf("                                          Test arg 1\n");
	printf("\033[0;36m");
	printf("----------------------------------------------------------------------------------------------------\n");
	printf("\033[0;0m");
	if (!argv[1] || fd1 == -1)
		printf("No file for arg 1");
	while ((ret = get_next_line(fd1, &line1) > 0))
	{
		count++;
		arrow();
		printf(" %s |%d|\n", line1, ret);
	}
	printf("\033[0;33m");
	printf("\nLines count --> %d", count);
	printf("\033[0;0m");
	count = 0;
	ret = 0;
	printf("\033[0;36m");
	printf("\n----------------------------------------------------------------------------------------------------\n");
	printf("\033[0;33m");
	printf("                                          Test arg 2\n");
	printf("\033[0;36m");
	printf("----------------------------------------------------------------------------------------------------\n");
	printf("\033[0;0m");

	if (!argv[2] || fd2 == -1)
	printf("No file for arg 2");
	while ((ret = get_next_line(fd2, &line2) > 0))
	{
		count++;
		arrow();
		printf(" %s |%d|\n", line2, ret);

	}
	printf("\033[0;33m");
	printf("\nLines count --> %d", count);
	printf("\033[0;0m");
	count = 0;
	ret = 0;
	printf("\033[0;36m");
	printf("\n----------------------------------------------------------------------------------------------------\n");
	printf("\033[0;33m");
	printf("                                          Test arg 3\n");
	printf("\033[0;36m");
	printf("----------------------------------------------------------------------------------------------------\n");
	printf("\033[0;0m");
	if (!argv[3] || fd3 == -1)
	printf("No file for arg 3");
	while ((ret = get_next_line(fd3, &line3) > 0))
	{
		count++;
		arrow();
		printf(" %s |%d|\n", line3, ret);
	}
	printf("\033[0;33m");
	printf("\nLines count --> %d", count);
	printf("\033[0;0m");
	count = 0;
	ret = 0;
	printf("\033[0;36m");
	printf("\n----------------------------------------------------------------------------------------------------\n");
	printf("\033[0;33m");
	printf("                                          Test arg 4\n");
	printf("\033[0;36m");
	printf("----------------------------------------------------------------------------------------------------\n");
	printf("\033[0;0m");
	if (!argv[4] || fd4 == -1)
	printf("No file for arg 4");
	while ((ret = get_next_line(fd4, &line4) > 0))
	{
		count++;
		arrow();
		printf(" %s |%d|\n", line4, ret);
	}
	printf("\033[0;33m");
	printf("\nLines count --> %d", count);
	printf("\033[0;0m");
	while(1);
}
