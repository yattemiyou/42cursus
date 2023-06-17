#include "get_next_line.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	int fd;

	fd = open("files/empty", O_RDONLY);

	char *line = get_next_line(fd);

	write(1, line, strlen(line));

	return 0;
}
