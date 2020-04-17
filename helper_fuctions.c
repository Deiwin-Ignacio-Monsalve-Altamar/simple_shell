#include "holberton.h"

/**
 * getargs - divide into arguments
 * @line: pointer to string
 * Return: pointer to string with arguments
 */
char **getargs(char *line)
{
	char *str = 0, *str2 = 0;
	char **array = 0, *tok = 0;
	int i = 0; /* , j = 0 */

	if (line)
	{
		/* duplicate str to avoid strtok damage and delete /n */
		str = _strdup(line);
		str2 = _strdup(str);

		tok = _strtok(str, DELIMI);

		/* count number of tokens */
		while (tok != NULL)
		{
			i++;
			tok = _strtok(NULL, DELIMI);
		}
		array = malloc(sizeof(char *) * (i + 1));
		tok = _strtok(str2, DELIMI);
		i = 0;

		/* fill array with each token */
		while (tok != NULL)
		{
			array[i] = _strdup(tok);
			i++;
			tok = _strtok(NULL, DELIMI);
		}
		array[i] = NULL;

		/* free memory */
		free(str);
		free(str2);
		return (array);
	}

	return (NULL);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(3, &c, 1));
}
/**
 * *_strcpy - print character
 * @src: pointr character
 * @dest : poinr character
 * Return: 0
 */
char *_strcpy(char *dest, char *src)
{
	int n;

	for (n = 0; src[n] != 0; n++)
	{
		dest[n] = src[n];
	}
	dest[n] = '\0';
	return (dest);
}

/**
 * _strlen - count a string
 * @s: string
 * Return: int
 */
int _strlen(char *s)
{
	char aux;
	int  cont = 0;

	aux = s[0];
	while (aux != '\0')
	{
		cont++;
		aux = s[cont];
	}
	return (cont);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy o	sign = sign * 1;
 * write(STDOUT_FILENO, "\n", 1);
 * write(STDOUT_FILENO, "Holber->$ ", 10);f the string given as a parameter.
 * @str: string
 * Return: pointer to the duplicated string
 */

char *_strdup(char *str)
{
	int x, y;
	char *copy = NULL;

	x = 0;

	if (str == NULL)
	{
		return (NULL);
	}
	else
	{
		while (str[x] != '\0')
		{
			x++;
		}
	}
		copy = malloc(sizeof(char) * (x + 1));
		if (copy == NULL)
		{
			return (NULL);
		}
		else
		{
			for (y = 0; str[y] != 0; y++)
			{
				copy[y] = str[y];
			}
			copy[y] = '\0';
		}
	return (copy);
}
