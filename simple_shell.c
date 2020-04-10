#include "holberton.h"
/**
 * main - execve example
 *
 * Return: Always 0.
 */
int	main(int argc, char **argv, char **env)
{
    char *line = NULL;
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
        status = execute(text, argv);
	dobfreer(text);
        free(line);
    } while (status);
    free(line);
    dobfreer(text);
   return (0);
}
