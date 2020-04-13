#include "holberton.h"
/**
 * main - execve example
 * @argc: numbers of arguments
 * @argv: string of arguments
 * Return: Always 0.
 */

int main(int argc, char **argv)
{
	char *line = NULL, *p = argv[0], *exit_com = "exit", *envi = "env";
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
		if ((_strcmp(exit_com, text[0])) == 0)
		{
			dobfreer(text);
			exit(EXIT_SUCCESS);
		}
		if ((_strcmp(envi, text[0])) == 0)
		{
			printenvi(text, environ);
		}
		else
		{
			status = execute(text, p, environ);
			dobfreer(text);
		}
	} while (status);
	free(line);
	dobfreer(text);
	return (0);
}
