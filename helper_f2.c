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

/**
 * _strcmp - compare two strings
 * @s1: string 1
 * @s2: string 2
 * Return: 0 if they are equal or a number less
 * than 0 if they are different
 */
int _strcmp(char *s1, char *s2)
{
	int x;

	for (x = 0; s1[x] != '\0' && s2[x] != '\0'; x++)
	{
		if (s1[x] != s2[x])
		{
			return (s1[x] - s2[x]);
		}
	}
	return (0);
}
/**
 * contokens - count the tokens
 * @buff: pointer to string
 * Return: token numbers
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(1, "Holber->$ ", 10);
	}
}
/**
 * contokens - count the tokens
 * @buff: pointer to string
 * Return: token numbers
 */
char *_getline(void)
{
	int tmp;
	char *line = NULL;
	size_t size  = 0;

	tmp = getline(&line, &size, stdin);
	if (tmp == EOF)
	{
		if (isatty(STDIN_FILENO))
			write(1, "\n", 1);
		exit(0);
	}
	return (line);
}
/**
 * contokens - count the tokens
 * @buff: pointer to string
 * Return: token numbers
 */
int execute(char **buffer, char **av)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(buffer[0], buffer, NULL) == -1)
		{
			perror(av[0]);
			exit(0);
		}
	}
	else
	{
		wait(&status);
	}
	return (1);
}