#include "holberton.h"
/**
 * main - execve example
 *
 * Return: Always 0.
 */
int	main(int argc, char **argv, char **env)
{
    char *line = NULL;
    size_t len = 0;
    int status, tmp = 0;
    pid_t pid; struct stat file;
    char **text;

    write(STDOUT_FILENO, "Holber->$ ", 10);
  
    while ((tmp = getline(&line, &len, stdin)))
    {
        if (tmp == EOF)
        {
            write(STDOUT_FILENO, "\n", 1);
            free(line);
            exit(0);
        }
        
        text = getargs(line);
        
        pid = fork();
        if (pid == -1)
            fail_fork();
        if (pid == 0)
        {
            if (text == NULL)
            {
                free(line);
                exit(EXIT_SUCCESS);
            }

            if (stat(text[0], &file) == 0)
                execve(text[0], text, NULL);
        }
        else
        {
            wait(&status);
        }
        
        len = 0; line = NULL;
        write(STDOUT_FILENO, "Holber->$ ", 10);
    }
    if (tmp == -1)
		exit(EXIT_FAILURE);
	free(line);
    return (0);
}