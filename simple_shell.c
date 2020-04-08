#include "holberton.h"

void thander(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}
/**
 * main - execve example
 *
 * Return: Always 0.
 */
int	main(void)
{
    char *line = NULL;
    size_t len = 0;
    int status, read = 0;
    pid_t pid;
    char **text, *token;

    printf("#cisfun$ ");
    read = getline(&line, &len, stdin);
    while (read > 1)
    {
        
        text = getargs(line);
        
        pid = fork();
        if (pid == -1)
        {
            perror("Error");
            return (1);
        }
        
        if (pid == 0)
        {
            if (execve(text[0], text, NULL) == -1)
            {
                perror("Error: \n");
            }
        }
        else
        {
            wait(&status);
        }
        
        printf("#cisfun$ ");
        getline(&line, &len, stdin);
    }
	free(line);
    if (character == -1)
		exit(EXIT_FAILURE);
    return (0);
}