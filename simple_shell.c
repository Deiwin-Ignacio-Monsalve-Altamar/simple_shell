#include "holberton.h"
/**
 * main - execve example
 *
 * Return: Always 0.
 */
int	main(int argc, char **argv, char **env)
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

        status = execute(text, p);
        
        dobfreer(text);
    } while (status);
    free(line);
    dobfreer(text);
   return (0);
}
