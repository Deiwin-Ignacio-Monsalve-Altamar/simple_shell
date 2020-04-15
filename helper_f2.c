#include "holberton.h"

/**
 * contokens - count the tokens
 * @buff: pointer to string
 * Return: token numbers
 */

int contokens(char *buff)
{
	int count;
	char *token = NULL, *aux_buff = NULL;

	aux_buff = _strdup(buff);
	token = strtok(aux_buff, " \n");
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
		write(STDOUT_FILENO, "Holber->$ ", 10);
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
			write(STDOUT_FILENO, "\n", 1);
		free(line);
		exit(0);
	}
	return (line);
}
/**
 * execute - function  that fork and execute the user input
 * @buffer: pointer to string with data to execute
 * @av: string
 * @env: pointer to Environment Variables
 * Return: int
 */
int execute(char **buffer, char *av, char **env)
{
	pid_t pid;
	int status, check;
	char *program = NULL;
	struct stat stark;

	e_exit(buffer);

	check = printenvi(buffer, env);
	if (check == 1)
		return (1);

	if (stat(buffer[0], &stark) == 0)
	{
		program = _strdup(buffer[0]);
	}
	else
	{
		program = _path(buffer[0], env);
		if (program == NULL)
		{
			free(program);
			perror(av);
			return (1);
		}
	}
	pid = fork();
	if (pid < 0)
	{
		fail_fork();
	}
	else if (pid == 0)
	{
		if (execve(program, buffer, NULL) == -1)
			perror(av);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
		free(program);
	return (1);
}
