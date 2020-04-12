#include "holberton.h"
/**
 * main - execve example
 * @argc: numbers of arguments
 * @argv: string of arguments
 * @env:  pointer to environment Variables
 * Return: Always 0.
 * 
 */
extern char **environ;
int	main(int argc, char **argv)
{
	char *line = NULL, *p = argv[0];
	int status = 1;
	char **text;

	do {
		prompt();
		line = _getline();
		if ((_strcmp(line, "\n")) == 0)
		{
			continue;
		}

		text = getargs(line);
		free(line);
		status = execute(text, p, environ);
		dobfreer(text);
	} while (status);
	free(line);
	dobfreer(text);
	return (0);
}
