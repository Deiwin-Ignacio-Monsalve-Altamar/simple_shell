#include "holberton.h"
/*
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
/*
 * fail_fork - fail fork
 * 
 * Return: void
 */
void fail_fork(void)
{
	perror("Error:");
	exit(EXIT_FAILURE);
}