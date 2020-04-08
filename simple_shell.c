#include "holberton.h"

/**
 * main - Simple Shell Project
 *
 * Return: Always 0.
 */

int main(void)
{
	size_t size = 0;
	pid_t pid;
	ssize_t num_read;
	char **capt = NULL, *buff = NULL;
	int status;

	while (1)
	{
		printf("$ ");
		buff = (char *)malloc(sizeof(size));
		if (buff == NULL)
		{
			free(buzz);
			continue;
		}
		num_read = getline(&buff, &size, stdin);
		if (num_read == -1)
			freerror1(*buff);
		pid = fork();
		if (pid == -1)
			freerror1(*buff);
		if (pid == 0)
		{
			capt = malloc(sizeof(char *));
			*capt = malloc(sizeof(char) * num_read);
			if (capt == NULL || *capt == NULL)
			{
				free(capt);
				free(*capt);
				continue;
			}
			capt = getargs(buff, num_read);
			if (execve(capt[0], capt, NULL) == -1)
				dobfreer(**capt);
		}
		wait(&status);
		free(buff);
	}
	return (0);
}
