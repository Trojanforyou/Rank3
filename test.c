#define _GNU_SOURCE
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc != 2 || !*argv[1])
		return (1);

	char buff[1024];
	char *pat = argv[1];
	size_t pat_len = strlen(pat);
	ssize_t byte;

	while ((byte = read(0, buff, 1024)) > 0)
	{
		char *curr = buff;
		char	*match;
		while ((match = memmem(curr, buff + byte - curr, pat, pat_len)))
		{
			write (1, curr, match - curr);
			size_t i = 0;
			while (i++ < pat_len)
				write (1, "*", 1);
			curr = match + pat_len;
		}
		if (curr < buff +byte)
			write (1, curr, buff + byte - curr);
	}
	return (byte < 0);
}
