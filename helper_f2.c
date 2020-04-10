#include "holberton.h"

/**
 * contokens - count the tokens
 * @buff: pointer to string
 * Return: token numbers
 */

int contokens(char *buff)
{
	int count;
	char *token, *aux_buff;

	aux_buff = _strdup(buff);
	token = strtok(buff, " \n");
	for (count = 1; token != NULL; count++)
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
 * prompt - function  that print the prompt
 * Return: void
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(1, "Holber->$ ", 10);
	}
}
/**
 * _getline - count the tokens
 * Return: pointer to the data entered by the user
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
		free(line);
		exit(0);
	}
	return (line);
}

/**
 * execute - function  that fork and execute the user input
 * @buff: pointer to string with data to execute
 * Return: int
 */
int execute(char **buffer, char *av)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		dobfreer(buffer);
		fail_fork();
	}
	if (pid == 0)
	{
		if (execve(buffer[0], buffer, NULL) == -1)
		{
			dobfreer(buffer);
			perror(av);
			exit(0);
		}
		dobfreer(buffer);
	}
	else
	{
		wait(&status);
	}
	return (1);
}
