#include "holberton.h"

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
