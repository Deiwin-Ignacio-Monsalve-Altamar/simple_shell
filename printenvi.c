#include "holberton.h"

/**
 * printenvi - print environment variables
 * @environ: pointer to string array with environment varibles
 * @text: pointer arrays for free
 * Return: void
 */
int printenvi(char **text, char **env)
{
    char *envi = "env";

    if ((_strcmp(envi, text[0])) == 0)
    {
        unsigned int cont, size;

        for (cont = 0; env[cont] != NULL; cont++)
        {
            size = _strlen(env[cont]);
            write(STDOUT_FILENO, env[cont], size);
            write(STDOUT_FILENO, "\n", 1);
        }
        return (1);
    }
    return (0);
}

/**
 * e_exit - produces output of simple_shell
 * @text: pointer arrays for free
 * Return: void
 */
void e_exit(char **text)
{
    char *exit_com = "exit";

    if ((_strcmp(exit_com, text[0])) == 0)
    {
        dobfreer(text);
        exit(EXIT_SUCCESS);
    }
}

/**
 * getline_aux- produces output of simple_shell
 * @buff: pointer arrays for free
 * Return: void
 */
int getline_aux(char *buff)
{
    int i, j;
    size_t size = 1024;
    char buf[1023];

    j = read(STDIN_FILENO, buf, size);
    buff = malloc(sizeof(char) * (j + 1));
    if (j == 0 || buff == NULL)
    {
        return (-1);
    }
    i = 0;
    while (i < j)
    {
        buff[i] = buf[i];
        i++;
    }
    buff[i] = '\0';
    return (0);
}
/**
 * ctrl_c - produces output of simple_shell
 * @sign: pointer arrays for free
 * Return: void
 */
void ctrl_c(int sign)
{
    sign = sign * 1;
    write(STDOUT_FILENO, "\n", 1);
    write(STDOUT_FILENO, "Holber->$ ", 10);
}
