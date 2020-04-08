#include "holberton.h"

/**
 * getargs - divide into arguments
 * @buff: pointer to string
 * @num_read: string character numbers
 * Return: pointer to string with arguments
 */
char **getargs(char *buff, ssize_t num_read)
{
	char *token, **args;
	int count;

	args = malloc(sizeof(char *));
	*args = malloc(sizeof(char) * num_read);
	if (args != NULL)
	{
		free(args);
		free(*args);
		exit(EXIT_FAILURE);
	}
	token = strtok(buff, "\n");
	for (count = 0; token != NULL; count++)
	{
		args[count] = token;
		token = strtok(NULL, "\n");
	}
	args[count] = NULL;
	return (args);
}


/**
 * fail_fork - fail fork
 * Return: void
 */
void fail_fork(void)
{
	perror("Error:");
	exit(EXIT_FAILURE);
}

/**
 * _strncpy - concatenates two strings
 * @dest: string 1
 * @src: string 2
 * @n: integer
 * Return: dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int x;

	for (x = 0; src[x] != '\0'; x++)
	{
		if (x < n)
		{
			dest[x] = src[x];
		}
	}
	for (; x < n ; x++)
	{
		dest[x] = '\0';
	}
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
 * which contains a copy of the string given as a parameter.
 * @str: string
 * Return: pointer to the duplicated string
 */

char *_strdup(char *str)
{
	int x, y;
	char *copy;

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
		}
	return (copy);
}
