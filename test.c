#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int	main(int ac, char **av)
{
	int	fd;
	char	*line;

	if (ac > 1)
		fd = open(line, O_RDONLY);
	line = get(fd);
	while (line)
	{
		printf("%s", line);
		line = get(fd);
	}
}