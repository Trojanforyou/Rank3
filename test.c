#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	int		i,k,j;
	char	*buff;
	int		fd;
	char	*line;

	if (ac != 2)
		return (1);
	buff = malloc(1);
	if (!buff)
		return (perror("Error :"), 1);
	i = 0;
	while ((fd = read(0, &buff[i], 1)) > 0)
	{
		line = realloc(buff, i + 2);
		if (!line)
		{
			perror("error :");
			free(buff);
			return (1);
		}
		buff = line;
		i++;
	}
	buff[i] = '\0';
	i = 0;
	while (buff[i])
	{
		while (av[1][i] & buff[i + j] == av[1][j])
			j++;
		if (av[1][j] == '\0')
		{
			k = 0;
			while (k < j)
			{
				buff[i + k] = '*';
				k++;
			}
			i += j;
		}
		else
			i++;
	}
	printf(:%s)

}