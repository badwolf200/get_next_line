#include "get_next_line.h"

int main(void)
{
	int fd;
	char *str;

	fd = open("test.c", O_RDONLY);
	printf("%d |%s|\n", get_next_line(fd, &str), str);
	//printf("%d |%s|\n", get_next_line(fd, &str), str);
	return (0);
}