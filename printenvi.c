#include "holberton.h"

/**
 * printenvi - print environment variables
 * @environ: pointer to string array with environment varibles
 * @text: pointer arrays for free
 * Return: void
 */
void printenvi(char **text, char **environ)
{
	unsigned int cont, size;

	for (cont = 0; environ[cont] != NULL; cont++)
	{
		size = _strlen(environ[cont]);
		write(STDOUT_FILENO, environ[cont], size);
		write(STDOUT_FILENO, "\n", 1);
	}
	dobfreer(text);
}

/**
 * e_exit - produces output of simple_shell
 * @text: pointer arrays for free
 * Return: void
 */
void e_exit(char **text)
{
	dobfreer(text);
	exit(EXIT_SUCCESS);
}

