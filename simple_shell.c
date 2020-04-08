#include "holberton.h"

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int	main(void)
{
    char *line;
    size_t len = 0;
    int status;
    pid_t pid;
    char *text[2], *token;

    text[1] = NULL;
    line = malloc(sizeof(char));
    if (line == NULL)
    {
        return (0);
    }
    printf("#cisfun$ ");
	getline(&line, &len, stdin);
    while (1)
    {
        token = strtok(line, "\n");
        text[0] = token;
        
		
        pid = fork();
        if (pid == -1)
        {
            fail_fork();
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
    return (0);
}