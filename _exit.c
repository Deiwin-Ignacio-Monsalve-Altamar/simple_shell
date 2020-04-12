#include <holberton.h>

void _exit(char **text, *line)
{
	free(line);
	dobfreer(text);
	exit(EXIT_SUCCESS);
}
