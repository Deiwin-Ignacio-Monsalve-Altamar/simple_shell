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
	int status = 1, cont = 0;
	char **text = NULL;

	if (argc == 1)
	{
		if (isatty(STDIN_FILENO) != 0)
		{
		signal(SIGINT, ctrl_c);

		do {
			prompt();
			line = _getline();
			cont++;
			if ((_strcmp(line, "\n")) == 0)
			{
				free(line);
				continue;
			}
			text = getargs(line);
			free(line);
			status = execute(text, p, environ, cont);
			dobfreer(text);
		} while (status);
		dobfreer(text);
		}
		else
		{
			no_intera(argv[0]);
		}
		
	}

	return (0);

}
/**
 * main - execve example
 * @argc: numbers of arguments
 * @argv: string of arguments
 * Return: Always 0.
 */
void no_intera(char *p)
{
	char *line = NULL;
	int status = 1, cont = 0;
	char **text = NULL;

	while (1)
	{
		line = 0;
		line = _getline();
			cont++;
			if ((_strcmp(line, "\n")) == 0)
			{
				free(line);
				continue;
			}
			text = getargs(line);
			free(line);
			status = execute(text, p, environ, cont);
			dobfreer(text);
	}
	exit(status);
}
