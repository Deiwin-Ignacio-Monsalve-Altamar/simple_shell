#include "holberton.h"

/**
 * getargs - divide into arguments
 * @buff: pointer to string
 * Return: pointer to string with arguments
 */
char **getargs(char *buff)
{
	char *token, **args;
	int count;
	unsigned int i;

	if (buff != NULL)
	{
		buff[_strlen(buff) - 1] = '\0';
		i = contokens(buff);
		args = malloc(sizeof(char *) * i);
		if (args == NULL)
		{
			return (NULL);
		}
		token = strtok(buff, DELIMI);
		for (count = 0; token != NULL; count++)
		{
			args[count] = malloc(_strlen(token) + 1);
			if (args[count] == NULL)
			{
				dobfreer(args);
				return (NULL);
			}
			_strcpy(args[count], token);
			token = strtok(NULL, DELIMI);
		}
		args[count] = NULL;
		return (args);
	}
	return (NULL);
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
 * which contains a copy of the string given as a parameter.
 * @str: string
 * Return: pointer to the duplicated string
 * 
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
