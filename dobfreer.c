#include "holberton.h"
/**
 * dobfreer - free double pointer
 * @capt: double pointer to free
 * Return: void
 */

void dobfreer(char **capt)
{
	int count = 0;

	while (capt[count] != NULL)
	{
		free(capt[count]);
		count++;
	}
	free(capt);
}


/**
 * _strncpy - copy  strings
 * @dest: string 1
 * @src: string 2
 * @n: count
 * Return: pointer to copy
 */
char *_strncpy(char *dest, char *src, int n)
{
	int x;

	for (x = 0; src[x] != '\0'; x++)
	{
		if (x < n)
			dest[x] = src[x];
	}
	for (; x < n ; x++)
	{
		dest[x] = '\0';
	}
	return (dest);
}
