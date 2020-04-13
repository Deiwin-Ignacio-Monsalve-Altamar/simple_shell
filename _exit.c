#include "holberton.h"

void print_exit(char **text, char *line)
{
	free(line);
	dobfreer(text);
	exit(EXIT_SUCCESS);
}
