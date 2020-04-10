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
