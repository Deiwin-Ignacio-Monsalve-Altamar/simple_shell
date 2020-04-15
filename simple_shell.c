#include "holberton.h"
/**
 * main - execve example
 * @argc: numbers of arguments
 * @argv: string of arguments
 * Return: Always 0.
 */

int main(int argc, char **argv)
{
	char *line = NULL, *p = argv[0];
	int status = 1;
	char **text = NULL;

	if (argc == 1)
	{

		signal(SIGINT, ctrl_c);

		do {
			prompt();
			line = _getline();
			if ((_strcmp(line, "\n")) == 0)
			{
				free(line);
				continue;
			}

			text = getargs(line);
			if (text[0] == NULL)
			{
				free(line);
				dobfreer(text);
				continue;
			}
			
			free(line);

			status = execute(text, p, environ);

			dobfreer(text);

		} while (status);
	}

	return (0);

}
