#include "holberton.h"

/**
 * contokens - count the tokens
 * @buff: pointer to string
 * Return: token numbers
 */

size_t contokens(char *buff)
{
	size_t count;
	char *token, *aux_buff;

	aux_buff = _strdup(char buff);
	token = strtok(buff, " \n");
	for (count = 1; token != NULL, count++)
	{
		token = strtok(NULL, " \n");
	}
	free(aux_buff);
	return (count);
}
