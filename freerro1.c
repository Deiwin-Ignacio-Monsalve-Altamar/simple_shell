#include "holberton.h"
/**
 * freerror1 - free buffer
 * @buff: pointer to buffer
 * Return: void
 */
void freerror1(char *buff)
{
	free(buff);
	perror("Error:");
	exit(EXIT_FAILURE);
}
